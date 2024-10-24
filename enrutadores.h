#ifndef ENRUTADORES_H
#define ENRUTADORES_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Enrutadores
{
private:
    string nombre;
    vector<int>rutas;
    //vector<int>tabla;
public:

    //constructor(es)...
    Enrutadores();            //valores default
    Enrutadores(string);            //valores para ingresar


    //metodos getters
    string getnombre()const;
    unsigned int getruta(unsigned short )const;
};

#endif // ENRUTADORES_H
