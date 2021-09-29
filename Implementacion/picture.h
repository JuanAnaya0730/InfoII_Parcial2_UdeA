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
    QString name; // Name almacena el nombre de la imagen que se desee procesar

public:
    Picture(); // Constructor
    Picture(QString fileName); // Este contructor me carca una imagen de nombre fileName

    void resize(int _width_, int _height_); // Esta funcion es la encargada de realizar el sub y sobre muestreo
    void arduino(void); // Esta funcion me guarda en un archivo .txt los datos que debo copiar y pegar en tinkercad
    void load(QString fileName); // Esta funcion me carga una imagen de nombre fileName
    bool isLoad(void); // Esta funcion me dice si la imagen se cargo correctamente

};

#endif // PICTURE_H
