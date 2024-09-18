#pragma once
#include<string>

class Libro: public MaterialBibliografico 
{
    private:
        string fechaPublicacion;
        string resumen;
    public:
        Libro(string nombre, string isbn, string autor, bool prestado, string fechaPublicacion, string resumen);
        string mostrarInformacion();
        string getFecha();
        string getResumen();
        string getLine();
        ~Libro();
};