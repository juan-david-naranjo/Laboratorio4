#include <iostream>
#include "enrutadores.h"
#include  <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void interfaz();    //funcion para mostrar opciones
void interfaz_enru();   //funcion para mostrar las opciones en la gestion de enrutadores
void interfaz_paque(); //funcion mostrar las opciones de envio de paquetes
short int enru_val(const vector<Enrutadores>& vector,string nombre);     //verificar que el objeto(enrutador) exista
void mostrartabla(const vector<Enrutadores>& vector);    // mostrar las rutas


int main()
{

    unsigned short int opcion=4;

    vector<Enrutadores>enrutadores;
    Enrutadores enrutador1("A");
    Enrutadores enrutador2("B");
    Enrutadores enrutador3("C");
    Enrutadores enrutador4("D");

    enrutadores.push_back(enrutador1);
    enrutadores.push_back(enrutador2);
    enrutadores.push_back(enrutador3);
    enrutadores.push_back(enrutador4);
    while(opcion!=0){
        size_t tamaño = enrutadores.size();

        vector<vector<int>> tabla(tamaño, vector<int>(tamaño, 0));
        unsigned short int opcion1=4,cant=0;
        string nombre="";
        interfaz();
        cin>>opcion;
        if(opcion==1){
            while(opcion1!=0){
                interfaz_enru();
                cin>>opcion1;
                 if(opcion1==1){
                     cout<<"Ingrese cantidad de enrutadores a agregar"<<endl;
                     cin>>cant;
                    while(cant>0){
                         cout<<"Ingrese el nombre del enrutador"<<endl;
                        cin>>nombre;
                        enrutadores.push_back(Enrutadores(nombre));
                        cant--;
                    }

                }else if(opcion1==2){
                     cout<<"Ingrese el nombre del enrutador a eliminar"<<endl;
                     cin>>nombre;
                     for (size_t i = 0; i < enrutadores.size(); i++){
                         if(enrutadores.at(i).getnombre()==nombre){
                             enrutadores.erase(enrutadores.begin()+i);
                             cout<<"Enrutador eliminado...."<<endl;
                             break;
                        }

                        }
                }else if(opcion1==0){
                    break;
                }else{
                     cout<<"Ingrese un valor valido bruto hpt"<<endl;
                }
            }
        }else if(opcion==2){
            while(opcion1!=0){
                interfaz_paque();
                cin>>opcion1;
                if(opcion1==1){
                   // unsigned int ruta1=0,ruta2=0;
                   // unsigned int front=0,behind=0;
                    string enru_destino;
                    cout<<"Ingrese el enrutador de destino: ";
                    cin>>enru_destino;
                    unsigned short int valido=enru_val(enrutadores,enru_destino);
                    if(valido>0){
                        cout<<"enrutador re contra valido pa"<<endl;
                        for (size_t i = 0; i < tamaño; i++) {
                            for (size_t j = 0; j < tamaño; j++) {
                                //ruta1=enrutadores.at(j).getruta(0);
                                //ruta2=enrutadores.at(j).getruta(1);
                                if(i==0){
                                    if(i==j){
                                    tabla[i][j] = 0;
                                         cout<<tabla[i][j]<<endl;
                                    continue;
                                    }
                                    if(j>0&&j<3){
                                        tabla[i][j]=enrutadores.at(i).getruta(j-1);;
                                    }else{
                                        tabla[i][j]=0;
                                    }
                                    cout<<tabla[i][j]<<endl;
                                }if(i==tamaño-1){
                                    if(i==j){
                                        tabla[i][j] = 0;
                                        // cout<<tabla[i][j]<<endl;
                                        continue;
                                    }else if(j==0){
                                        tabla[i][j]=enrutadores.at(i).getruta(1);
                                    }else if(j==tamaño-2){
                                        tabla[i][j]=enrutadores.at(i).getruta(0);
                                    }else{
                                        tabla[i][j]=0;
                                    }
                                    //cout<<tabla[i][j]<<endl;

                                }else if(j==i){
                                    tabla[i][j] = 0;
                                    tabla[i][j-1]=enrutadores.at(i).getruta(0);
                                    tabla[i][j+1]=enrutadores.at(i).getruta(1);
                                    cout<<tabla[i][j]<<endl;
                                }else{
                                    tabla[i][j]=0;
                                    cout<<tabla[i][j]<<endl;
                                }
                            }
                        }
                        for(unsigned int i=0;i<4;i++){
                            for(unsigned int j=0;j<4;j++){
                            cout<<tabla[i][j]<<" ";
                        }
                            cout<<endl;
                        }






                    }else if(valido==0){
                        cout<<"Enrutador de destino es el mismo"<<endl;
                    }else{
                        cout<<"Enrutador invalido"<<endl;
                    }
                }else if(opcion1==2){

                    mostrartabla(enrutadores);

                }else if(opcion1==0){
                    break;
                }else{
                    cout<<"Ingrese un valor valido tetranuta"<<endl;
                }
            }
        }else if(opcion==0){
            cout<<"Saliendo del programa"<<endl;
        }else{
            cout<<"Ingrese un valor valido bobo hpt"<<endl;
        }

    }

}







void interfaz(){
    cout<<"1. para gestionar enrutadores"<<endl;
    cout<<"2. para enviar un paquete a un enrutador "<<endl;
    cout<<"0. para salir "<<endl;
    return;
}


void interfaz_enru(){
    cout<<"1. para agregar enrutadores"<<endl;
    cout<<"2. para eliminar enrutadores "<<endl;
    cout<<"0. para salir "<<endl;
    return;
}


void interfaz_paque(){
    cout <<"1. para enviar un paquete"<<endl;
    cout <<"2. para ver la tabla con los enrutadores"<<endl;
    cout <<"0. para salir"<<endl;
    return;
}


short int enru_val(const vector<Enrutadores>& vector,string nombre){

    for (size_t i = 0; i < vector.size(); i++){
        if((vector.at(i)).getnombre()==nombre){
            return i;
        }
    }
    return -1;
}

void mostrartabla(const vector<Enrutadores>& enrutadores) {
    size_t tamaño = enrutadores.size();

    vector<string> etiquetas;
    vector<vector<int>> tabla(tamaño, vector<int>(tamaño, 0));

    for (size_t i = 0; i < tamaño; i++) {               // Imprimir la cabecera de la tabla
        etiquetas.push_back(enrutadores.at(i).getnombre());
    }
    cout << setw(5) << " ";

    for (size_t i = 0; i < tamaño; i++) {
        for (size_t j = 0; j < tamaño; j++) {
            if(j==i){
                tabla[i][j] = 0;
            }else if(j<2){
                tabla[i][j] = (enrutadores.at(j)).getruta(j);
            }else{
                tabla[i][j]=0;
            }

        }
    }

    for (const auto& etiqueta : etiquetas) {
        cout << setw(5) << etiqueta; // Imprimir etiquetas de la cabecera
    }
    cout << endl;


    for (size_t i = 0; i < tabla.size(); i++) {
        cout << setw(5) << etiquetas[i]; // Imprimir la etiqueta de la fila

        for (size_t j = 0; j < tabla[i].size(); j++) {
            cout << setw(5) << tabla[i][j]; // Imprimir los valores de la tabla
        }
        cout << endl;
    }
}
