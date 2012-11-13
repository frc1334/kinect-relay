/*
 * Kinect.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: joseph
 */

#include "Kinect.h"
#include <boost/interprocess/streams/bufferstream.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

using namespace std;
using namespace boost::interprocess;
using boost::asio::ip::tcp;

Kinect::Kinect(std::string ip, std::string port)
	: isNewData(0), ip(ip), port(port)
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
	tcp::resolver::query resolverQuery(tcp::v4(), ip, port);
	tcp::resolver::iterator endpoints = resolver.resolve(resolverQuery);
	tcp::socket socket(io_service);
	boost::asio::connect(socket, endpoints);
	while (true)
	{
		vector<char> buf(4);
		boost::system::error_code error;

		size_t length = boost::asio::read(socket, boost::asio::buffer(buf), boost::asio::transfer_all(), error);

		bufferstream bufstr(&buf[0], buf.size());
		boost::archive::binary_iarchive io(bufstr);
		mutexData.Lock();
		io >> data;
		isNewData = true;
		mutexData.Unlock();

		if (error == boost::asio::error::eof)
			break;
	    else if (error)
	        throw boost::system::system_error(error);
	}
}

void Kinect::StartListening()
{
	boost::thread listenerThread(&Kinect::asyncRead, this);
}

ProcessedKinectData Kinect::GetFrameResult()
{
	Mutex::ScopeMutex lock(mutexData);
	isNewData = false;
	return data;
}
