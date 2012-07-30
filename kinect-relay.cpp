//============================================================================
// Name        : kinect-relay.cpp
// Author      : Team 1334
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "KinectServer.h"
#include <boost/asio.hpp>

int main(void)
{
	try
	{
		boost::asio::io_service io_service;
		KinectServer server(io_service, 4200);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
