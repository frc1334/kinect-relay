#ifndef MAGICBOX_H
#define MAGICBOX_H

struct VisionData
{
};

#if BEAGLEBOARD
#include "../Beagleboard/KinectProc.h"

VisionData Process(KinectObject *kinect)
{
}
#endif

char* Encode(VisionData data)
{
}


VisionData Decode(char* data)
{
}

#endif
