#pragma once
#include "MaterialBibliografico.h"
#include<string>

class Revista: public MaterialBibliografico
{
    private:
        string numeroEdicion;
        string mesPublicacion;
    public:
        Revista(string nombre, string isbn, string autor, bool prestado, string numeroEdicion, string mesPublicacion);
        string mostrarInformacion();
        string getEdicion();
        string getMesPublicacion();
        string getLine();
        ~Revista();
};