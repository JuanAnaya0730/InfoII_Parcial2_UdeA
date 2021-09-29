#include "picture.h"

using namespace std;

int main()
{
    string fileName;
    Picture flag;

    cout << "Ingrese el nombre del la imagen: ";
    cin >> fileName;

    flag.load(fileName.c_str());
    if(flag.isLoad()){
        flag.resize(12,12);
        flag.arduino();
        cout << "Exito en el proceso." << endl;
    }else{
        cout << "No se pudo abrir la imagen " << fileName << endl;
    }

    return 0;
}
