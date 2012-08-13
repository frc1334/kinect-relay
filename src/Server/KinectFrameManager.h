/*
 * KinectFrameManager.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTFRAMEMANAGER_H_
#define KINECTFRAMEMANAGER_H_

class KinectServerConnection;

#include <vector>
#include "../Shared/Mutex.h"
#include "libfreenect/libfreenect.hpp"

class KinectFrameManager
	: public Freenect::FreenectDevice
{
public:
	KinectFrameManager(freenect_context *ctx, int index);
	void VideoCallback(void* _rgb, uint32_t timestamp);
	void DepthCallback(void* _depth, uint32_t timestamp);
	void DoLoop(KinectServerConnection* connection);
private:
	std::vector<uint8_t> bufferDepth;
	std::vector<uint16_t> bufferVideo;
	Mutex mutexBufferDepth;
	Mutex mutexBufferVideo;
	bool newDepth;
	bool newVideo;
};

#endif /* KINECTFRAMEMANAGER_H_ */
