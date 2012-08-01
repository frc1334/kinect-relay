/*
 * KinectFrameManager.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include "KinectFrameManager.h"

KinectFrameManager::KinectFrameManager(freenect_context *ctx, int index)
{
}

void KinectFrameManager::VideoCallback(void* _rgb, uint32_t timestamp)
{
}

void KinectFrameManager::DepthCallback(void* _depth, uint32_t timestamp)
{
}

void KinectFrameManager::getRGB(std::vector<uint8_t> &buffer)
{
}

void KinectFrameManager::getDepth(std::vector<uint8_t> &buffer)
{
}

bool KinectFrameManager::isNewRGB()
{
	return false;
}

bool KinectFrameManager::isNewDepth()
{
	return false;
}

void KinectFrameManager::DoLoop()
{
}
