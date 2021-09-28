#include "picture.h"

Picture::Picture(QString fileName)
{
    name = fileName;
    load(PATH+name+JPG);
}

void Picture::resize(int _width_, int _height_)
{
    QImage auxImage(_width_,_height_,QImage::Format_RGB32);
    auxImage.fill(Qt::white);

    int deltaX = (width()-((float(_width_)-1)*(width()/float(_width_))))/2;
    int deltaY = (height()-((float(_height_)-1)*(height()/float(_height_))))/2;

    for(int i=0, pX; i<_width_; ++i){
        pX = (i*(width()/float(_width_)))+deltaX;
        for(int j=0, pY; j<_height_; ++j){
            pY = (j*(height()/float(_height_)))+deltaY;
            auxImage.setPixelColor(i,j,pixelColor(pX,pY));
        }
    }

    QImage::operator=(auxImage);
    save(PATH + name + to_string(_width_).c_str() + "x" + to_string(_height_).c_str()+ JPG);
}
