/*
 * KinectFrameManager.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTFRAMEMANAGER_H_
#define KINECTFRAMEMANAGER_H_

#include <vector>
#include "/usr/include/libfreenect/libfreenect.hpp" // Fix this later

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
};

#endif /* KINECTFRAMEMANAGER_H_ */
