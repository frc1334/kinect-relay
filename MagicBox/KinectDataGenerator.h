/*
 * KinectDataGenerator.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTDATAGENERATOR_H_
#define KINECTDATAGENERATOR_H_

// This struct holds data to be used by the cRIO after processing and transmission
// At the moment, it hold useless placeholder data
struct ProcessedKinectData
{
	int uselessData;
};

#ifdef SERVER
ProcessedKinectData GenerateKinectData();
#endif

#endif /* KINECTDATAGENERATOR_H_ */
