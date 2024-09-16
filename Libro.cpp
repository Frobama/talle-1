#pragma once
#include "MaterialBibliografico.h"
#include "Libro.h"
#include<iostream>
#include<string>
using namespace std;

Libro::Libro(string nombre, string isbn, string autor, bool prestado, string fechaPublicacion, string resumen)
    : MaterialBibliografico(nombre, isbn, autor, prestado){
    this -> fechaPublicacion = fechaPublicacion;
    this -> resumen = resumen;
}

string Libro::mostrarInformacion()
{
    return MaterialBibliografico::mostrarInformacion() + "\nFecha de publicacion: " + this -> fechaPublicacion + "\nResumen: " + this->resumen + "\n";
}

string Libro::getFecha()
{
    return this->fechaPublicacion;
}

string Libro::getResumen()
{
    return this->resumen;
}

Libro::~Libro()
{
    cout<<"Se destruyó un libro de nombre " + this->nombre <<endl;
}