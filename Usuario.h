#pragma once
#include<string>
#include "MaterialBibliografico.h"

using namespace std;
class Usuario
{
    private:
        string nombre;
        string id;
        MaterialBibliografico* materialesPrestados[5];
    public:
        Usuario(string nombre, string id);
        string getNombre();
        string getId();
        void prestarMaterial(MaterialBibliografico material);
        void devolverMaterial(MaterialBibliografico material);
        string mostrarMaterialesPrestados();
        ~Usuario();
};