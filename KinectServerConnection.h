/*
 * KinectServerConnection.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTSERVERCONNECTION_H_
#define KINECTSERVERCONNECTION_H_

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class KinectServerConnection
	: public boost::enable_shared_from_this<KinectServerConnection>
{
public:
	typedef boost::shared_ptr<KinectServerConnection> pointer;
	static pointer Create(boost::asio::io_service& io_service);
	tcp::socket& Socket();
	void Start();
private:
	KinectServerConnection(boost::asio::io_service& io_service);
	void handleWrite(const boost::system::error_code& error, size_t bytes_transferred);
	tcp::socket _socket;
};

#endif /* KINECTSERVERCONNECTION_H_ */
