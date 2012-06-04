#ifndef MAGICBOX_H
#define MAGICBOX_H

struct VisionData
{
}

#if BEAGLEBOARD
#include "../Beagleboard/KinectProc.h"

VisionData Process(KinectObject *kinect)
{
}
#endif

// TODO: Return type is incorrect.  Return type should be data ready for sockets
void Encode(VisionData data)
{
}

// TODO: This should have a parameter that matches the return type of Encode()
VisionData Decode()
{
}

#endif
