/*
 * KinectFrameManager.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTFRAMEMANAGER_H_
#define KINECTFRAMEMANAGER_H_

#include "/usr/include/libfreenect/libfreenect.hpp" // Fix this later

class KinectFrameManager
	: public Freenect::FreenectDevice
{
public:
	KinectFrameManager();
};

#endif /* KINECTFRAMEMANAGER_H_ */
