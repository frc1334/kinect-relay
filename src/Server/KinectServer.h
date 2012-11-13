/*
 * KinectServer.h
 *
 *  Created on: Jul 29, 2012
 *      Author: joseph
 */

#ifndef KINECTSERVER_H_
#define KINECTSERVER_H_

#if HAVE_CONFIG_H
#include "../../config.h"
#endif

#include <boost/asio.hpp>
#include "KinectServerConnection.h"
#include "KinectFrameManager.h"

using boost::asio::ip::tcp;

class KinectServer
{
private:
	tcp::acceptor _acceptor;
	KinectFrameManager* kinect;
	void startAccept();
	void handleAccept(KinectServerConnection::pointer new_connection, const boost::system::error_code& error);
public:
	virtual ~KinectServer();
	KinectServer(boost::asio::io_service& io_service, int portno, KinectFrameManager* kinect);
};

#endif /* KINECTSERVER_H_ */
