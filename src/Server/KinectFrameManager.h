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
#include "../Shared/Mutex.h"
#include "libfreenect.hpp"

class KinectFrameManager
	: public Freenect::FreenectDevice
{
public:
	KinectFrameManager(freenect_context *ctx, int index);
	void VideoCallback(void* _rgb, uint32_t timestamp);
	void DepthCallback(void* _depth, uint32_t timestamp);
	void DoLoop(KinectServerConnection* connection);
	cv::Mat* GetDepthBuffer();
	cv::Mat* GetVideoBuffer();
private:
	cv::Mat bufferDepth;
	cv::Mat bufferVideo;
	Mutex mutexBufferDepth;
	Mutex mutexBufferVideo;
	bool newDepth;
	bool newVideo;
};

#endif /* KINECTFRAMEMANAGER_H_ */
