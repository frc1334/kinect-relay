//============================================================================
// Name        : kinect-relay.cpp
// Author      : Team 1334
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <boost/asio.hpp>
#include <boost/program_options.hpp>
#include "KinectServer.h"

struct ProgramConfig
{
public:
	int port;
} config_data;

int main(int argc, char *argv[])
{
	try
	{
		KinectFrameManager kinect;
		boost::program_options::options_description generic("Generic Options");
		generic.add_options()
				("version,v", "print version information")
				("help", "output help message")
				;
		boost::program_options::options_description config("Standard Configuration");
		config.add_options()
				("port", boost::program_options::value<int>(&config_data.port)->default_value(4200), "port number")
				;
		boost::program_options::options_description cmdLine("Allowed Options");
		boost::program_options::options_description configFile;
		cmdLine.add(generic).add(config);
		configFile.add(config);
		boost::program_options::variables_map readOptions;
		boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(cmdLine).run(), readOptions);
		std::ifstream configFs("kinect-relay.cfg");
		boost::program_options::store(parse_config_file(configFs, configFile), readOptions);
		boost::program_options::notify(readOptions);
		if (readOptions.count("help"))
		{
			std::cout << cmdLine << std::endl;
			return 0;
		}
		if (readOptions.count("version"))
		{
			std::cout << "version information goes here" << std::endl;
			return 0;
		}
		boost::asio::io_service io_service;
		KinectServer server(io_service, config_data.port, &kinect);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
