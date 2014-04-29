#include "capturebuffer.h"

CaptureBuffer::CaptureBuffer(QObject *parent) :
    QAbstractVideoSurface(parent)
{
}

CaptureBuffer::~CaptureBuffer()
{

}

bool CaptureBuffer:: present(const QVideoFrame &frame)
{

   QVideoFrame cloneFrame(frame);
   cloneFrame.map(QAbstractVideoBuffer::ReadOnly);

   QImage frameAsImage = QImage(cloneFrame.bits(), cloneFrame.width(),cloneFrame.height(), cloneFrame.bytesPerLine(),
                                  QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));

   frameAsImage.copy();
   emit s_image(frameAsImage);

   cloneFrame.unmap();



 return true;
}
