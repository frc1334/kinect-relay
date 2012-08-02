/*
 * KinectDataGenerator.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTDATAGENERATOR_H_
#define KINECTDATAGENERATOR_H_

#include "../KinectFrameManager.h"

// This class holds data to be used by the cRIO after processing and transmission
// At the moment, it hold useless placeholder data
class ProcessedKinectData
{
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		// All members must be listed here in this fashion
		ar & uselessData;
	}

	int uselessData;
};

#ifdef SERVER
ProcessedKinectData GenerateKinectData(KinectFrameManager* kinect);
#endif

#endif /* KINECTDATAGENERATOR_H_ */
