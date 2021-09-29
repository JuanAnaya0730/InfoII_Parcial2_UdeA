#include "picture.h"

Picture::Picture()
{
    name = "";
}

Picture::Picture(QString fileName)
{
    this->load(fileName);
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
    ofstream file;
    QColor pixel;

    file.open((PATH_TXT + name + to_string(width()).c_str() + "x" + to_string(height()).c_str() + TXT).toStdString(), ios::trunc);

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

    file << "int RGB[3]["+to_string(height())+"]["+to_string(width())+"]={";
    for(int channel=0; channel<3; ++channel){
        file << "{";
        for(int i=0; i<height(); ++i) {
            file << "{";
            for(int j=0; j<width(); ++j){
                file << RGB[channel][i][j];
                if(j!=width()-1){ file << ",";}
            }
            file << "}";
            if(i!=height()-1){ file << ", ";}
        }
        file << "}";
        if(channel!=2){ file << ",\n";}
    }
    file << "};";
    file.close();
}

void Picture::load(QString fileName)
{
    name = fileName;
    QImage::load(PATH_IMG+name+JPG);
}

bool Picture::isLoad()
{
    return !isNull();
}










