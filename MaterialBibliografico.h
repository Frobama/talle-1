#pragma once
#include<string>

class MaterialBibliografico{

    private:
        string nombre;
        string isbn;
        string autor;
        bool prestado; 
    public:
        MaterialBibliografico(string nombre, string isbn, string autor, bool prestado);
        string getNombre();
        string getisbn();
        string getAutor();
        bool isPrestado();
        void setPrestado();
}