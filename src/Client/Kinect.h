/*
 * Kinect.h
 *
 *  Created on: Aug 13, 2012
 *      Author: joseph
 */

#ifndef KINECT_H_
#define KINECT_H_

#include "../MagicBox/KinectDataGenerator.h"
#include "../Shared/Mutex.h"

class Kinect
{
public:
	Kinect();
	bool IsNewData();
	void StartListening();
	ProcessedKinectData GetFrameResult();
private:
	void asyncRead();
	Mutex mutexData;
	ProcessedKinectData data;
	bool isNewData;
};

#endif /* KINECT_H_ */
