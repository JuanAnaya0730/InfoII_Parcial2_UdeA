#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <fstream>
#include <QImage>
#include <QColor>
#include <QString>

#define PATH_IMG "../Implementacion/images/"
#define PATH_TXT "../Implementacion/arduino/"
#define JPG ".jpg"
#define TXT ".txt"

using namespace std;

class Picture: public QImage
{
private:
    QString name;

public:
    Picture();
    Picture(QString fileName);

    void resize(int _width_, int _height_);
    void arduino(void);
    void load(QString fileName);

};

#endif // PICTURE_H
