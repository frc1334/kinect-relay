#include "KinectProc.h"

KinectObject::KinectObject(freenect_context *_ctx, int _index) : Freenect::FreenectDevice(_ctx, _index)
{

}

void KinectObject::VideoCallback(void* _rgb, uint32_t timestamp)
{
    mutex_video.lock();
    uint8_t* frame = static_cast<uint8_t*>(_rgb);
    delete frame;
    mutex_video.unlock();
}
