/*
 * Kinect.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: joseph
 */

#include "Kinect.h"

Kinect::Kinect()
	: isNewData(0)
{
}

bool Kinect::IsNewData()
{
	return isNewData;
}

ProcessedKinectData Kinect::GetFrameResult()
{
	Mutex::ScopeMutex lock(mutexData);
	return data;
}
