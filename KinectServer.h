/*
 * KinectServer.h
 *
 *  Created on: Jul 29, 2012
 *      Author: joseph
 */

#ifndef KINECTSERVER_H_
#define KINECTSERVER_H_

#include <boost/asio.hpp>
#include "KinectServerConnection.h"

using boost::asio::ip::tcp;

class KinectServer
{
private:
	tcp::acceptor _acceptor;
	void startAccept();
	void handleAccept(KinectServerConnection::pointer new_connection, const boost::system::error_code& error);
public:
	virtual ~KinectServer();
	KinectServer(boost::asio::io_service& io_service, int portno);
};

#endif /* KINECTSERVER_H_ */
