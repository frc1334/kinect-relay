#ifndef KINECTPROC_H
#define KINECTPROC_H

#include "libfreenect.hpp"
#include "../Shared/Mutex.h"

// Manages freenect communication
// Example used from http://openkinect.org/wiki/C%2B%2B_GL_Example
class KinectObject : public Freenect::FreenectDevice
{
    public:
        KinectObject(freenect_context *_ctx, int _index);
        void VideoCallback(void* _rgb, uint32_t timestamp);
        void DepthCallback(void* _depth, uint32_t timestamp);
    private:
        Mutex mutex_video;
};

#endif
