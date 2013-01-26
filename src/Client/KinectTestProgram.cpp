/*
 * KinectTestProgram.cpp
 *
 *  Created on: Oct 17, 2012
 *      Author: joseph
 */

#include "Kinect.h"

using namespace std;

int main(int argc, char *argv[])
{
	Kinect kinect(argv[0], argv[1]);
	kinect.StartListening();
	while (true)
		if (kinect.IsNewData())
			cout << kinect.GetFrameResult().x << ", " << kinect.GetFrameResult().y << ", " << kinect.GetFrameResult().z << endl;
}

