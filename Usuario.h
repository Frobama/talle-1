#pragma once
#include<string>
#include "MaterialBibliografico.h"

using namespace std;

class MaterialBibliografico;

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
        bool prestarMaterial(MaterialBibliografico* material);
        bool devolverMaterial(MaterialBibliografico* material);
        string mostrarMaterialesPrestados();
        void borrar();
        ~Usuario();
};