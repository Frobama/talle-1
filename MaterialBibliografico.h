#pragma once
#include<string>
using namespace std;

class MaterialBibliografico{

    private:
        string nombre;
        string isbn;
        string autor;
        bool prestado; 
    public:
        MaterialBibliografico(string nombre, string isbn, string autor, bool prestado);
        virtual string mostrarInformacion();
        string getNombre();
        string getisbn();
        string getAutor();
        bool isPrestado();
        void setPrestado(bool prestado);
        virtual ~MaterialBibliografico();
};