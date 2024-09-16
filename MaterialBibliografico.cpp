#pragma once
#include "MaterialBibliografico.h"
#include<iostream>
#include<string>

MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor, bool prestado)
{
    this -> nombre = nombre;
    this -> isbn;
    this -> autor = autor;
    this -> prestado = prestado;
}

string MaterialBibliografico::mostrarInformacion()
{  
    string p;
    if(this->prestado){p = "Prestado";}
    else{p = "Disponible";}

    return "Nombre: " + this->nombre + "\nISBN: " + this->isbn + "\nAutor: " + this->autor + "\nDispoibilidad: " + p;
}

string MaterialBibliografico::getNombre()
{
    return this -> nombre;
}

string MaterialBibliografico::getisbn()
{
    return this -> isbn;
}

string MaterialBibliografico::getAutor()
{
    return this -> autor;
}

bool MaterialBibliografico::isPrestado()
{
    return this -> prestado;
}

void MaterialBibliografico::setPrestado(bool prestado)
{
    this -> prestado = prestado;
}

MaterialBibliografico::~MaterialBibliografico(){std::cout<<"Se destruyó un material"<<std::endl;}
