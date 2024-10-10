#include "Usuario.h"
#include "MaterialBibliografico.h"
#include<iostream>
using namespace std;

Usuario::Usuario(string nombre, string id)
{
    this -> nombre = nombre;
    this -> id = id;
    for(int i = 0; i < 5 ; i++){
        this -> materialesPrestados[i] = nullptr;
    }
}

bool Usuario::isListaVacia(){
    for(int i = 0; i < 5 ; i++){
        if (materialesPrestados[i] != nullptr){
            return false;
        }
    }
    return true;
}

string Usuario::getNombre()
{
    return this->nombre;
}

string Usuario::getId()
{
    return this->id;
}

bool Usuario::prestarMaterial(MaterialBibliografico* material)
{
    for(int i = 0; i < 5; i++){
        if(materialesPrestados[i] == nullptr){
            materialesPrestados[i] = material;
            return true;
        }
    }
    cout<<"El usuario " + this->nombre + " no puede tener más de 5 materiales."<<endl;
    return false;
}

bool Usuario::devolverMaterial(MaterialBibliografico* material)
{
    for(int i = 0; i < 5; i++){
        if(materialesPrestados[i] == material){
            materialesPrestados[i] = nullptr;
            return true;
        }
    }
    cout<<"El usuario " + this->nombre + " no tiene ese material."<<endl;
    return false;
}

string Usuario::mostrarMaterialesPrestados()
{
    string info = "";
    for(int i = 0; i < 5; i++){
        if(materialesPrestados[i] == nullptr){
            break;
        }
        info += materialesPrestados[i]->mostrarInformacion() + "\n";

    }
    if(info == ""){
        return "El usuario no tiene materiales prestados";
    }
    return info;
}

void Usuario::borrar()
{
    for(int i = 0; i < 5; i++){
        if(materialesPrestados[i] != nullptr){
            this->materialesPrestados[i]->setPrestado(false, this);
            this->materialesPrestados[i] = nullptr;
        }
    }
}

Usuario::~Usuario()
{
    cout<<"Se destruyó al usuario de nombre " + nombre<<endl;
}
