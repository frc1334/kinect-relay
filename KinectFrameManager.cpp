/*
 * KinectFrameManager.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include "KinectFrameManager.h"
#include "KinectServerConnection.h"

KinectFrameManager::KinectFrameManager(freenect_context *ctx, int index)
	: Freenect::FreenectDevice(ctx, index), bufferDepth(freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB).bytes), bufferVideo(freenect_find_video_mode(FREENECT_RESOLUTION_MEDIUM, FREENECT_VIDEO_RGB).bytes), newDepth(false), newVideo(false)
{
}

void KinectFrameManager::VideoCallback(void* _rgb, uint32_t timestamp)
{
	Mutex::ScopeMutex lock(mutexBufferVideo); // Mutex keeps data from being read during update
	uint8_t* video = static_cast<uint8_t*>(_rgb);
	std::copy(video, video + getVideoBufferSize(), bufferVideo.begin());
	newVideo = true;
}

void KinectFrameManager::DepthCallback(void* _depth, uint32_t timestamp)
{
	Mutex::ScopeMutex lock(mutexBufferDepth); // Same as above
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
