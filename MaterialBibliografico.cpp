#include "MaterialBibliografico.h"
#include<iostream>
#include<string>

MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor, bool prestado)
{
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> prestado = prestado;
    this ->usuarioPrestado = nullptr;
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

Usuario *MaterialBibliografico::getUsuario()
{
    return this->usuarioPrestado;
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

void MaterialBibliografico::setPrestado(bool prestado, Usuario* usuario)
{
    this -> prestado = prestado;
    if(prestado){this->usuarioPrestado=usuario;}
    else{this->usuarioPrestado=nullptr;}
}

string MaterialBibliografico::getLine()
{
    return "";
}

MaterialBibliografico::~MaterialBibliografico(){std::cout<<"Se destruyó un material"<<std::endl;}
