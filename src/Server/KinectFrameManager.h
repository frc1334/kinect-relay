/*
 * KinectFrameManager.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTFRAMEMANAGER_H_
#define KINECTFRAMEMANAGER_H_

class KinectServerConnection;

#include <opencv/cv.h>
#include <boost/thread.hpp>
#include "../Shared/Mutex.h"
#include "../MagicBox/KinectDataGenerator.h"
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
	cv::Mat* GetDepthBuffer();
	cv::Mat* GetVideoBuffer();
private:
	cv::Mat bufferDepth;
	cv::Mat bufferVideo;
	Mutex mutexBufferDepth;
	Mutex mutexBufferVideo;
	Mutex mutexBufferData;
	ProcessedKinectData processedData;
	bool newDepth;
	bool newVideo;
	bool newFrame;
	boost::thread* frameThread;
};

#endif /* KINECTFRAMEMANAGER_H_ */
