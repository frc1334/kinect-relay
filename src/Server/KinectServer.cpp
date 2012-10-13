/*
 * KinectServer.cpp
 *
 *  Created on: Jul 29, 2012
 *      Author: joseph
 */

#include "../../config.h"
#include "KinectServer.h"
#include "KinectServerConnection.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>

KinectServer::~KinectServer()
{

}

KinectServer::KinectServer(boost::asio::io_service& io_service, int portno, KinectFrameManager* kinect)
	: _acceptor(io_service, tcp::endpoint(tcp::v4(), portno)), kinect(kinect)
{
	startAccept();
}

void KinectServer::startAccept()
{
    KinectServerConnection::pointer new_connection = KinectServerConnection::Create(_acceptor.get_io_service(), kinect);

  	_acceptor.async_accept(new_connection->Socket(), boost::bind(&KinectServer::handleAccept, this, new_connection, boost::asio::placeholders::error));
}

void KinectServer::handleAccept(KinectServerConnection::pointer new_connection, const boost::system::error_code& error)
{
    if (!error)
	{
    	new_connection->Start();
	    startAccept();
	}
}
