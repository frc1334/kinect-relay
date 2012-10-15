/*
 * Kinect.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: joseph
 */

#include "Kinect.h"
#include <boost/thread.hpp>
#include <boost/asio.hpp>

Kinect::Kinect()
	: isNewData(0)
{
}

bool Kinect::IsNewData()
{
	return isNewData;
}

void Kinect::asyncRead()
{
	// We're going to do all TCP stuff in here
	// Nothing will be kept between calls
	boost::asio::io_service io_service;
}

void Kinect::StartListening()
{
	boost::thread listenerThread(asyncRead);
}

ProcessedKinectData Kinect::GetFrameResult()
{
	Mutex::ScopeMutex lock(mutexData);
	return data;
}
