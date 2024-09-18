#include "Usuario.h"
#include "MaterialBibliografico.h"
#include<iostream>
using namespace std;

Usuario::Usuario(string nombre, string id)
{
    this -> nombre = nombre;
    this -> id = id;
    this -> materialesPrestados = new MaterialBibliografico[5];
}

string Usuario::getNombre()
{
    return this->nombre;
}

string Usuario::getId()
{
    return this->id;
}

void Usuario::prestarMaterial(MaterialBibliografico material)
{
    for(int i = 0; i < 5; i++){
        if(materialesPrestados[i] == nullptr){
            materialesPrestados[i] = material;
            break;
        }
    }
    cout<<"El usuario " + this->nombre + " no puede tener más de 5 materiales."<<endl;
}

void Usuario::devolverMaterial(MaterialBibliografico material)
{
    for(int i = 0; i < 5; i++){
        if(materialesPrestados[i] == nullptr){
            materialesPrestados[i] = nullptr;
            break;
        }
    }
    cout<<"El usuario " + this->nombre + " no tiene ese material."<<endl;
}

string Usuario::mostrarMaterialesPrestados()
{
    string info = "";
    for(int i = 0; i < 5; i++){
        if(materialesPrestados[i] == nullptr){
            break;
        }
        info += materialesPrestados[i]->mostrarInformacion();

    }
    if(info == ""){
        return "El usuario no tiene materiales prestados";
    }
    return info;
}

Usuario::~Usuario()
{
    cout<<"Se destruyó al usuario de nombre " + nombre<<endl;
}
