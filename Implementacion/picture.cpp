#include "picture.h"

Picture::Picture(QString fileName)
{
    name = fileName;
    load(PATH+name+JPG);
}
