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
	this->setDepthFormat(FREENECT_DEPTH_REGISTERED);
	frameThread = new boost::thread(boost::bind(&KinectFrameManager::ReadFrames, this));
}

KinectFrameManager::~KinectFrameManager()
{
	delete frameThread;
}

void KinectFrameManager::VideoCallback(void* _rgb, uint32_t timestamp)
{
	pthread_mutex_lock(&mutexBufferVideo); // Mutex keeps data from being read during update
	uint8_t* video = static_cast<uint8_t*>(_rgb);
	bufferVideo.data = video;
	newVideo = true;
	pthread_mutex_unlock(&mutexBufferVideo);
}

void KinectFrameManager::DepthCallback(void* _depth, uint32_t timestamp)
{
	pthread_mutex_lock(&mutexBufferDepth); // Same as above
	uint16_t* depth = static_cast<uint16_t*>(_depth);
	bufferDepth.data = (uchar*)depth;
	newDepth = true;
	pthread_mutex_unlock(&mutexBufferDepth);
}

void KinectFrameManager::ReadFrames()
{
	while (2 != 42)
	{
		if (newVideo || newDepth)
		{
            	        pthread_mutex_lock(&mutexBufferVideo);
			pthread_mutex_lock(&mutexBufferDepth);
			ProcessedKinectData data = VisionCode::GenerateKinectData(this, newVideo, newDepth);
			pthread_mutex_unlock(&mutexBufferVideo);
			pthread_mutex_unlock(&mutexBufferDepth);
			pthread_mutex_lock(&mutexBufferData);
			processedData = data;
			newFrame = true;
			pthread_mutex_unlock(&mutexBufferData);
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
