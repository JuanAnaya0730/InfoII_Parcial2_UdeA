#include "picture.h"

Picture::Picture(QString fileName)
{
    name = fileName;
    load(PATH_IMG+name+JPG);
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
    save(PATH_IMG + name + to_string(_width_).c_str() + "x" + to_string(_height_).c_str()+ JPG);
}

void Picture::arduino()
{
    int RGB[3][height()][width()];
    QColor pixel;
    ofstream archivo;

    archivo.open((PATH_TXT + name + TXT).toStdString(), ios::trunc);

    for(int i=0; i<width(); ++i){
        for(int j=0; j<height(); ++j){
            pixel = pixelColor(i,j);
            if(pixel == QColor(255,255,255)){
                pixel = QColor(254,254,254);
            }
            else if(pixel == QColor(0,0,0)){
                pixel = QColor(1,1,1);
            }
            RGB[0][j][i] = pixel.red();
            RGB[1][j][i] = pixel.green();
            RGB[2][j][i] = pixel.blue();
        }
    }
    archivo.close();
}










