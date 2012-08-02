/*
 * KinectFrameManager.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include "KinectFrameManager.h"
#include "KinectServerConnection.h"

KinectFrameManager::KinectFrameManager(freenect_context *ctx, int index)
	: Freenect::FreenectDevice(ctx, index), bufferDepth(freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB).bytes), bufferVideo(freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB).bytes), gamma(2048)
{
	for (unsigned int i = 0; i < 2048; i++)
	{
		float v = i / 2048.0f;
		v = std::pow(v, 3) * 6;
		gamma[i] = v * 6 * 256;
	}
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

void KinectFrameManager::DoLoop(KinectServerConnection* connection)
{
	connection->Write("bluh\n");
}
