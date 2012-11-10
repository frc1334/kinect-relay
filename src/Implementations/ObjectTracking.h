/*
 * ObejctTracking.h
 *
 *  Created on: Nov 05, 2012
 *      Author: joseph
 */

#ifndef KINECTDATAGENERATOR_H_
#define KINECTDATAGENERATOR_H_

#include "../../config.h"
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
	static ProcessedKinectData GenerateKinectData(KinectFrameManager* kinect, bool newVideo, bool newDepth)
	{
		ProcessedKinectData data;
		return data;
	}
};
#endif

#endif /* KINECTDATAGENERATOR_H_ */
