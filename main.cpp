#include <iostream>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include<string>
using namespace std;

void agregarMaterial(MaterialBibliografico[] materiales){
    
    string nombre;
    string isbn;
    string autor;
    string tipoLibro;
    cout<<"Ingrese el tipo de material (Libro/Revista): "; cin >> tipoLibro;
    while(tipoLibro != "Libro" && tipoLibro != "Revista"){
        cout<<"Ingrese un tipo válido (Libro/Revista): "; cin >> tipoLibro;
    }
    cout<<"Ingrese el nombre: "; cin >> nombre;
    cout<<"Ingrese el ISBN: "; cin >> isbn;
    cout<<"Ingrese el autor: "; cin >> autor;
    if(tipoLibro == "Libro"){
        cout<<"Ingrese la fecha de publicacion: "; cin >> string fecha;
        cout<<"Ingrese el resumen: "; cin >> string resumen;
        for(int i = 0; i < materiales.size(); i++){
            if(materiales[i] != nullptr){
                materiales[i] = new Libro(nombre,isbn,autor,false,fecha,resumen);
            }
        }
        
    }
    
}
void mostrarMateriales(MaterialBibliografico[] materiales){
    for (int i = 0; i<materiales.size(); i++){
        if (materiales[i] == nullptr){break;}
        cout<<i<<"\n"<<materiales.mostrarInformacion()<<"\n"<<endl;
    }  
}

void buscarMateriales(MaterialBibliografico[] materiales){
    MaterialBibliografico* materialptr;
}
int main() {
    MaterialBibliografico* materiales[100] = {};
    int opcion = 1;
    while (opcion != 0)
    {
        cout<< "Ingrese la acción a realizar\n 1.- Agregar material bibliografico\n 2.- Mostrar informacion de los materiales\n 3.- Buscar un material\n 4.- Prestar y devolver material\n 5.- Gestion de usuarios\n"<< endl;
        
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            
            agregarMaterial(materiales);
            break;

        case 2:
            mostrarMateriales(materiales);
            break;

        case 3:
            mostrarMateriales(materiales);
            break;
        }
    }
    
    cout<<"XD"<<endl;
    delete materiales;
    return 0;
}