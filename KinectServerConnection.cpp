/*
 * KinectServerConnection.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "KinectServerConnection.h"

using boost::asio::ip::tcp;

KinectServerConnection::KinectServerConnection(boost::asio::io_service& io_service)
	: _socket(io_service)
{
}

KinectServerConnection::pointer KinectServerConnection::Create(boost::asio::io_service& io_service)
{
	return KinectServerConnection::pointer(new KinectServerConnection(io_service));
}

tcp::socket& KinectServerConnection::Socket()
{
	return _socket;
}

void KinectServerConnection::Start()
{
	while (2>1)
	{
		boost::asio::async_write(_socket, boost::asio::buffer("test"), boost::bind(&KinectServerConnection::handleWrite, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}
}

void KinectServerConnection::handleWrite(const boost::system::error_code& error, size_t bytes_transferred)
{
}
