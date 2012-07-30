/*
 * KinectServer.cpp
 *
 *  Created on: Jul 29, 2012
 *      Author: joseph
 */

#include "KinectServer.h"
#include <boost/asio.hpp>

KinectServer::~KinectServer()
{

}

KinectServer::KinectServer(boost::asio::io_service& io_service, int portno)
	: _acceptor(io_service, tcp::endpoint(tcp::v4(), portno))
{
	startAccept();
}

void KinectServer::startAccept()
{
    KinectServerConnection::pointer new_connection = KinectServerConnection::create(_acceptor.io_service());

  	_acceptor.async_accept(new_connection->socket(), boost::bind(&KinectServer::handleAccept, this, new_connection, boost::asio::placeholders::error));
}

void KinectServer::handleAccept(KinectServerConnection::pointer new_connection, const boost::system::error_code& error)
{
    if (!error)
	{
    	new_connection->start();
	    start_accept();
	}
}
