/*
 * KinectServerConnection.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTSERVERCONNECTION_H_
#define KINECTSERVERCONNECTION_H_

#if HAVE_CONFIG_H
#include "../../config.h"
#endif

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "KinectFrameManager.h"

using boost::asio::ip::tcp;

class KinectServerConnection
	: public boost::enable_shared_from_this<KinectServerConnection>
{
public:
	typedef boost::shared_ptr<KinectServerConnection> pointer;
	static pointer Create(boost::asio::io_service& io_service, KinectFrameManager* kinect);
	tcp::socket& Socket();
	void Start();
	void Write(boost::asio::streambuf* data);
private:
	KinectServerConnection(boost::asio::io_service& io_service, KinectFrameManager* kinect);
	void handleWrite(const boost::system::error_code& error, size_t bytes_transferred);
	tcp::socket _socket;
	KinectFrameManager* kinect;
};

#endif /* KINECTSERVERCONNECTION_H_ */
