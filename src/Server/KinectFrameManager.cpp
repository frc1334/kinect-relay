/*
 * KinectFrameManager.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include "../../config.h"
#include "../MagicBox/KinectDataGenerator.h"
#include <boost/archive/binary_oarchive.hpp>
#include "KinectFrameManager.h"
#include "KinectServerConnection.h"
#include "libfreenect.hpp"
#include <iostream>
#include <opencv/cv.h>

using namespace cv;

KinectFrameManager::KinectFrameManager(freenect_context *ctx, int index)
	: Freenect::FreenectDevice(ctx, index), bufferDepth(Size(640, 480), CV_16UC1), bufferVideo(Size(640, 480), CV_8UC3, Scalar(0)), newDepth(false), newVideo(false), newFrame(false)
{
	frameThread = new boost::thread(boost::bind(&KinectFrameManager::ReadFrames, this));
}

KinectFrameManager::~KinectFrameManager()
{
	delete frameThread;
}

void KinectFrameManager::VideoCallback(void* _rgb, uint32_t timestamp)
{
	Mutex::ScopeMutex lock(mutexBufferVideo); // Mutex keeps data from being read during update
	uint8_t* video = static_cast<uint8_t*>(_rgb);
	bufferVideo.data = video;
	newVideo = true;
}

void KinectFrameManager::DepthCallback(void* _depth, uint32_t timestamp)
{
	Mutex::ScopeMutex lock(mutexBufferDepth); // Same as above
	uint16_t* depth = static_cast<uint16_t*>(_depth);
	bufferDepth.data = (uchar*)depth;
	newDepth = true;
}

void KinectFrameManager::ReadFrames()
{
	while (2 != 42)
	{
		if (newVideo || newDepth)
		{
			mutexBufferVideo.Lock();
			mutexBufferDepth.Lock();
			ProcessedKinectData data = VisionCode::GenerateKinectData(this, newVideo, newDepth);
			mutexBufferVideo.Unlock();
			mutexBufferDepth.Unlock();
			mutexBufferData.Lock();
			processedData = data;
			newFrame = true;
			mutexBufferData.Unlock();
		}
	}
}

void KinectFrameManager::SendFrames(KinectServerConnection* connection)
{
	this->setLed(LED_GREEN);
	while (2 != 42)
	{
		if (newFrame)
		{
			boost::asio::streambuf requestData;
			std::ostream dataStream(&requestData);
			boost::archive::binary_oarchive serializer(dataStream);
			serializer << processedData;
			connection->Write(&requestData);
		}
	}
}
