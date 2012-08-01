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
#include "libfreenect/libfreenect.hpp"

class KinectFrameManager
	: public Freenect::FreenectDevice
{
public:
	KinectFrameManager(freenect_context *ctx, int index);
	void VideoCallback(void* _rgb, uint32_t timestamp);
	void DepthCallback(void* _depth, uint32_t timestamp);
	void getRGB(std::vector<uint8_t> &buffer);
	void getDepth(std::vector<uint8_t> &buffer);
	bool isNewRGB();
	bool isNewDepth();
	void DoLoop(KinectServerConnection* connection);
};

#endif /* KINECTFRAMEMANAGER_H_ */
