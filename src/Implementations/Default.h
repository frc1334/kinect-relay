/*
 * KinectDataGenerator.h
 *
 *  Created on: Jul 30, 2012
 *      Author: joseph
 */

#ifndef KINECTDATAGENERATOR_H_
#define KINECTDATAGENERATOR_H_

#if HAVE_CONFIG_H
#include "../../config.h"
#endif

#include <boost/archive/binary_oarchive.hpp>

// This class holds data to be used by the cRIO after processing and transmission
// At the moment, it hold useless placeholder data
class ProcessedKinectData
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		// All members must be listed here in this fashion
		ar & uselessData;
		// Example: if you had another member call "foo" you would add this:
		// ar & foo;
		// If you are confuzzled by something: http://www.boost.org/doc/libs/1_50_0/libs/serialization/doc/tutorial.html
	}

public:
	int uselessData;
};

#ifdef SERVER
class KinectFrameManager; // forward declare this class; due to recursive includes

#include "../Server/KinectFrameManager.h"

class VisionCode
{
public:
	// This method will be used to process vision data
	// This will be called by KinectFrameManager
	static ProcessedKinectData GenerateKinectData(KinectFrameManager* kinect, bool newVideo, bool newDepth)
	{
		ProcessedKinectData data;
		data.uselessData = 42;
		return data;
	}
};
#endif

#endif /* KINECTDATAGENERATOR_H_ */
