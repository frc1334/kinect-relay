/*
 * ObejctTracking.h
 *
 *  Created on: Nov 05, 2012
 *      Author: joseph
 */

#ifndef KINECTDATAGENERATOR_H_
#define KINECTDATAGENERATOR_H_

#if HAVE_CONFIG_H
#include "../../config.h"
#endif

#include <boost/archive/binary_oarchive.hpp>

class ProcessedKinectData
{
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & x;
		ar & y;
	}

public:
	unsigned int x;
	unsigned int y;
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
		return data;
	}
};
#endif

#endif /* KINECTDATAGENERATOR_H_ */
