#ifndef KINECTPROC_H
#define KINECTPROC_H

#include "libfreenect.hpp"

// Manages freenect communication
// Example used from http://openkinect.org/wiki/C%2B%2B_GL_Example
class KinectObject : public Freenect::FreenectDevice
{
 public:
  MagicBoxInternal(freenect_contect *_ctx);
  void VideoCallback(void* _rgb, uint32_t timestamp);
  void DepthCallback(void* _depth, uint32_t timestamp);
}

#endif
