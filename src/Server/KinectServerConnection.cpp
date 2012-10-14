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

using boost::asio::ip::tcp;

KinectServerConnection::KinectServerConnection(boost::asio::io_service& io_service, KinectFrameManager* kinect)
	: _socket(io_service), kinect(kinect) { }

KinectServerConnection::pointer KinectServerConnection::Create(boost::asio::io_service& io_service, KinectFrameManager* kinect)
{
	return KinectServerConnection::pointer(new KinectServerConnection(io_service, kinect));
}

tcp::socket& KinectServerConnection::Socket()
{
	return _socket;
}

void x(KinectFrameManager* kinect, KinectServerConnection* connection)
{
	kinect->DoLoop(connection);
}

void KinectServerConnection::Start()
{
	kinect->DoLoop(this);
}

void KinectServerConnection::Write(boost::asio::streambuf* data)
{
	boost::asio::write(_socket, *data, boost::asio::transfer_all());
}

void KinectServerConnection::handleWrite(const boost::system::error_code& error, size_t bytes_transferred)
{
	// i think something should be done here......
	// logging, likely
}
