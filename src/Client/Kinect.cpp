/*
 * Kinect.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: joseph
 */

#include "Kinect.h"
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

using boost::asio::ip::tcp;

Kinect::Kinect(int messageSize)
	: isNewData(0), message_length(messageSize)
{
}

bool Kinect::IsNewData()
{
	return isNewData;
}

void Kinect::asyncRead()
{
	// We're going to do all TCP stuff in here
	// Nothing will be kept between calls
	boost::asio::io_service io_service;
	tcp::resolver resolver(io_service);
	tcp::resolver::query resolverQuery("tempip", "kinectd");
	tcp::resolver::iterator endpoints = resolver.resolve(resolverQuery);
	tcp::socket socket(io_service);
	boost::asio::connect(socket, endpoints);
	while (true)
	{
		boost::array<char, message_length> buffer;
		boost::system::error_code error;

		size_t length = boost::asio::read(socket, boost::asio::buffer(buffer, message_length), boost::asio::transfer_all(), error);

		if (error == boost::asio::error::eof)
			break;
	    else if (error)
	        throw boost::system::system_error(error);
	}
}

void Kinect::StartListening()
{
	boost::thread listenerThread(asyncRead);
}

ProcessedKinectData Kinect::GetFrameResult()
{
	Mutex::ScopeMutex lock(mutexData);
	return data;
}
