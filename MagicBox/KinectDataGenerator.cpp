/*
 * ProcessedKinectData.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#include "KinectDataGenerator.h"

#ifdef SERVER
// This method will be used to process vision data
// This will be called by KinectFrameManager
ProcessedKinectData GenerateKinectData(KinectFrameManager* kinect)
{
	ProcessedKinectData data;
	data.uselessData = 42;
	return data;
}
#endif
