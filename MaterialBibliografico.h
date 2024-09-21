#pragma once
#include<string>
using namespace std;

class Usuario;

class MaterialBibliografico{

    private:
        string nombre;
        string isbn;
        string autor;
        bool prestado; 
        Usuario* usuarioPrestado;
    public:
        MaterialBibliografico(string nombre, string isbn, string autor, bool prestado);
        virtual string mostrarInformacion();
        string getNombre();
        Usuario* getUsuario();
        string getisbn();
        string getAutor();
        bool isPrestado();
        void setPrestado(bool prestado, Usuario* usuario);
        virtual string getLine();
        virtual ~MaterialBibliografico();
};