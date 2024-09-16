#pragma once
#include "Revista.h"
#include<iostream>
#include<string>

using namespace std;

Revista::Revista(string nombre, string isbn, string autor, bool prestado, string numeroEdicion, string mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor, prestado){
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
}

string Revista::mostrarInformacion()
{
    return MaterialBibliografico::mostrarInformacion() + "\nNumero de edicion: : " + this -> numeroEdicion + "\nMes de publicacion: " + this->mesPublicacion + "\n";
}

string Revista::getEdicion()
{
    return this -> numeroEdicion;
}

string Revista::getMesPublicacion()
{
    return this -> mesPublicacion;
}

Revista::~Revista()
{
    cout<<"Se destruyó una revista de nombre " + this->nombre <<endl;
}
