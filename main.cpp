#include <iostream>
#include "MaterialBibliografico.cpp"
#include "Libro.cpp"
#include "Revista.cpp"
#include<string>
using namespace std;


void agregarMaterial(MaterialBibliografico* materiales[100]){
    
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
        string fecha;
        string resumen;
        cout<<"Ingrese la fecha de publicacion: "; cin >> fecha;
        cout<<"Ingrese el resumen: "; cin >> resumen;
        for(int i = 0; i < 100; i++){
            if(materiales[i] == nullptr){
                bool prestado = false;
                Libro* l = new Libro(nombre,isbn,autor,prestado,fecha,resumen);
                materiales[i] = l;
                break;
            }
        }
        
    }
    
}
void mostrarMateriales(MaterialBibliografico* materiales[100]){
    for (int i = 0; i<100; i++){
        if (materiales[i] == nullptr){break;}
        cout<<i+1<<"1.-\n"<<materiales[i]->mostrarInformacion()<<"\n"<<endl;
    }  
}

int main() {
    MaterialBibliografico* materiales[100] = {nullptr};
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
    for(int i = 0; i < 100; i++){
        delete materiales[i];
    }
    return 0;
}