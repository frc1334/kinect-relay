//============================================================================
// Name        : kinect-relay.cpp
// Author      : Team 1334
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <boost/asio.hpp>
#include <libconfig.h++>
#include "KinectServer.h"

using namespace libconfig;

struct ProgramConfig
{
	int port;
} config;

int main(void)
{
	Config cfg;

	try
	{
		cfg.readFile("example.cfg");
	}
	catch(const FileIOException &fioex)
	{
		std::cerr << "I/O error while reading file." << std::endl;
		return(EXIT_FAILURE);
	}
	catch(const ParseException &pex)
	{
		std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
		return(EXIT_FAILURE);
	}

	try
	{
		config.port = cfg.lookup("port");
	}
	catch(const SettingNotFoundException &nfex)
	{
		config.port = 4200;
	}

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
