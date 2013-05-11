/*
 * KinectFrameManager.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTFRAMEMANAGER_H_
#define KINECTFRAMEMANAGER_H_

#if HAVE_CONFIG_H
#include "../../config.h"
#endif

class KinectServerConnection; // forward declare; due to recursive includes

#include <opencv/cv.h>
#include <boost/thread.hpp>
#include "../MagicBox/KinectDataGenerator.h"
#include "KinectServerConnection.h"
#include "libfreenect.hpp"

class KinectFrameManager
	: public Freenect::FreenectDevice
{
public:
	KinectFrameManager(freenect_context *ctx, int index);
	~KinectFrameManager();
	void VideoCallback(void* _rgb, uint32_t timestamp);
	void DepthCallback(void* _depth, uint32_t timestamp);
	void SendFrames(KinectServerConnection* connection);
	void ReadFrames();
	inline cv::Mat* GetDepthBuffer() { return &bufferDepth; }
	inline cv::Mat* GetVideoBuffer() { return &bufferVideo; }
private:
	cv::Mat bufferDepth;
	cv::Mat bufferVideo;
	pthread_mutex_t mutexBufferDepth;
        pthread_mutex_t mutexBufferVideo;
	pthread_mutex_t mutexBufferData;
	ProcessedKinectData processedData;
	bool newDepth;
	bool newVideo;
	bool newFrame;
	boost::thread* frameThread;
};

#endif /* KINECTFRAMEMANAGER_H_ */
