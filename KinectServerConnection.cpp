/*
 * KinectServerConnection.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

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
	boost::thread(boost::ref(x), kinect, this);
}

void KinectServerConnection::Write(std::string data)
{
	boost::asio::async_write(_socket, boost::asio::buffer(data), boost::bind(&KinectServerConnection::handleWrite, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void KinectServerConnection::handleWrite(const boost::system::error_code& error, size_t bytes_transferred)
{
}
