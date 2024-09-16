#include <iostream>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include<string>
using namespace std;

int main() {
    int opcion = 1;
    while (opcion != 0)
    {
        cout<< "Ingrese la acción a realizar\n 1.- Agregar material bibliografico\n 2.- Mostrar informacion de los materiales\n 3.- Buscar un material\n 4.- Prestar y devolver material\n 5.- Gestion de usuarios\n"<< endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            string nombre;
            cout<<"Ingrese el nombre del material: ";
            cin>> nombre;
            cout<<""<<endl;
            break;
        
        
        }
    }
    
    cout<<"XD"<<endl;
    
    return 0;
}