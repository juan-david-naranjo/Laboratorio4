#include "enrutadores.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
Enrutadores::Enrutadores():nombre(""),rutas(2){
}
Enrutadores::Enrutadores(string name):nombre(name),rutas(2){
    for(unsigned short int i=0;i<2;i++){
        cout<<"Ingrese el costo a la ruta: "<<i<<endl;
        cin>>rutas[i];
        //cout<<rutas.at(i)<<endl;
    }
}











//Metodos
string Enrutadores::getnombre()const{
    return nombre;
}




unsigned int Enrutadores:: getruta(unsigned short i)const{
    if(rutas.at(i)>0){
        return rutas.at(i);
    }else{
        cout<<"Indice Invalido....."<<endl;
        return 0;
    }

}
