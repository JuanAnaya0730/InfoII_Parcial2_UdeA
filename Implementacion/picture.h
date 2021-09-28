#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <QImage>
#include <QColor>
#include <QString>

#define PATH "../Implementacion/images/"
#define JPG ".jpg"

using namespace std;

class Picture: public QImage
{
private:
    QString name;

public:
    Picture(QString fileName);
};

#endif // PICTURE_H
