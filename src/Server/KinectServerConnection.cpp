/*
 * KinectServerConnection.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include "../../config.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include "KinectServerConnection.h"
#include "KinectFrameManager.h"

KinectServerConnection::KinectServerConnection(KinectFrameManager* kinect)
	: kinect(kinect) { }

KinectServerConnection::pointer KinectServerConnection::Create(KinectFrameManager* kinect)
{
	return KinectServerConnection::pointer(new KinectServerConnection(kinect));
}

void KinectServerConnection::Start()
{
	kinect->SendFrames(this);
}

void KinectServerConnection::Write(boost::asio::streambuf* data)
{
}
