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
	unsigned double x;
	unsigned double y;
	unsigned double z;
};

#ifdef SERVER
class KinectFrameManager; // forward declare this class; due to recursive includes

#include "../Server/KinectFrameManager.h"
#include <libfreenect/libfreenect-registration.h>
#include <opencv/cv.h>
#include <stdint.h>

using namespace cv;

class VisionCode
{
public:
	// This method will be used to process vision data
	// This will be called by KinectFrameManager
	static ProcessedKinectData GenerateKinectData(KinectFrameManager* kinect, bool newVideo, bool newDepth)
	{
		ProcessedKinectData data;
		kinect->GetDepthBuffer();
		Mat* videoRGB = kinect->GetVideoBuffer();
		Mat* videoHSV = cvCreateImage(cvGetSize(videoRGB), 8, 3);
		cvCvtColor(videoRGB, videoHSV, CV_RGB2HSV);
		Mat* greenThres = cvCreateImage(cvGetSize(videoRGB), 8, 1);
		cvInRangeS(videoHSV, cvScalar(30, 100, 100), cvScalar(40, 255, 255), greenThres);
		CvMoments *moments = (CvMoments*)malloc(sizeof(CvMoments));
		cvMoments(greenThres, moments, 1);
		double area = cvGetCentralMoment(moments, 0, 0);
		double x = cvGetSpatialMoment(moments, 1, 0) / area;
		double y = cvGetSpatialMoment(moments, 0, 1) / area;
		freenect_camera_to_world(kinect->getDevice(), (int)x, (int)y, (int)*((uint16_t*)CV_MAT_ELEM_PTR((CvMat)*kinect->GetDepthBuffer(), x, y) ), &data.x, &data.y);
		cvReleaseMat((CvMat**)&videoHSV);
		cvReleaseMat((CvMat**)&greenThres);
		return data;
	}
};
#endif

#endif /* KINECTDATAGENERATOR_H_ */
