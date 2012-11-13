/*
 * Kinect.h
 *
 *  Created on: Aug 13, 2012
 *      Author: joseph
 */

#ifndef KINECT_H_
#define KINECT_H_

#if HAVE_CONFIG_H
#include "../../config.h"
#endif

#include "../MagicBox/KinectDataGenerator.h"
#include "../Shared/Mutex.h"

class Kinect
{
public:
	Kinect(std::string ip, std::string port);
	bool IsNewData();
	void StartListening();
	ProcessedKinectData GetFrameResult();
private:
	void asyncRead();
	Mutex mutexData;
	ProcessedKinectData data;
	bool isNewData;

	std::string ip, port;
};

#endif /* KINECT_H_ */
