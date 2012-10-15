//============================================================================
// Name        : kinect-relay.cpp
// Author      : Team 1334
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include "../../config.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
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
		boost::asio::io_service io_service;
		Freenect::Freenect freenect;
		KinectFrameManager* device = &freenect.createDevice<KinectFrameManager>(0);
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
			return EXIT_SUCCESS;
		}
		if (readOptions.count("version"))
		{
			std::cout << "version information goes here" << std::endl;
			return EXIT_SUCCESS;
		}
		KinectServer server(io_service, config_data.port, device);
		/*boost::asio::signal_set signals(io_service, SIGINT, SIGTERM);
	    signals.async_wait(boost::bind(&boost::asio::io_service::stop, &io_service));
	    io_service.notify_fork(boost::asio::io_service::fork_prepare);
	    if (pid_t pid = fork())
	    	if (pid > 0)
	    		exit(EXIT_SUCCESS);
	    else
	    {
	    	syslog(LOG_ERR | LOG_USER, "Primary fork failure: %m");
	    	return EXIT_FAILURE;
	    }
	    close(0);
	    close(1);
	    close(2);
	    if (open("/dev/null", O_RDONLY) < 0)
	    {
	    	syslog(LOG_ERR | LOG_USER, "Unable to open /dev/null: %m");
	    	return EXIT_FAILURE;
	    }
        const char* output = "/tmp/kinectd.daemon.out";
        const int flags = O_WRONLY | O_CREAT | O_APPEND;
        const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
        if (open(output, flags, mode) < 0)
        {
           syslog(LOG_ERR | LOG_USER, "Unable to open output file %s: %m", output);
           return EXIT_FAILURE;
        }
        if (dup(1) < 0)
        {
           syslog(LOG_ERR | LOG_USER, "Unable to dup output descriptor: %m");
           return EXIT_FAILURE;
        }
        io_service.notify_fork(boost::asio::io_service::fork_child);
        syslog(LOG_INFO | LOG_USER, "kinectd daemon started");*/
		std::cout << "Starting kinect...." << std::endl;
    	device->startVideo();
    	device->startDepth();
    	device->setLed(LED_RED);
    	std::cout << "Starting server...." << std::endl;
		io_service.run();
    	std::cout << "Stopping server...." << std::endl;
		device->stopVideo();
		device->stopDepth();
		std::cout << "Stopping kinect...." << std::endl;
		//syslog(LOG_INFO | LOG_USER, "kinectd daemon stopped");
	}
	catch (std::exception& e)
	{
		syslog(LOG_ERR | LOG_USER, "Exception: %s", e.what());
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
