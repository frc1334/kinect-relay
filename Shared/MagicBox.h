#ifndef MAGICBOX_H
#define MAGICBOX_H

#include "libfreenect.hpp"

// Manages freenect communication
class MagicBox
{
public:
    static void Proccess();
private:
    // Internal class used by parent to tack an individual kinect
    // Example used from http://openkinect.org/wiki/C%2B%2B_GL_Example
    class MagicBoxInternal : public Freenect::FreenectDevice
    {
    public:
        MagicBoxInternal(freenect_contect *_ctx);
        void VideoCallback(void* _rgb, uint32_t timestamp);
        void DepthCallback(void* _depth, uint32_t timestamp);
    }
}

#endif
