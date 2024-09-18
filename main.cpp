#include <iostream>
#include <fstream>
#include <sstream>
#include "MaterialBibliografico.cpp"
#include "Libro.cpp"
#include "Revista.cpp"
#include<string>
using namespace std;


void agregarMaterial(MaterialBibliografico* materiales[100]){
    if(materiales[99] != nullptr){
        cout<<"No se pudo agregar el material, ya hay más de 100 materiales"<<endl;
        return;
    }
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
                Libro* l = new Libro(nombre,isbn,autor,false,fecha,resumen);
                materiales[i] = l;
                return;
            }
        }
    } else if(tipoLibro == "Revista"){
        string edicion;
        string mes;
        cout<<"Ingrese el número de edición: "; cin >> edicion;
        cout<<"Ingrese el mes de publicación: "; cin >> mes;
        for(int i = 0; i < 100; i++){
            if(materiales[i] == nullptr){
                Revista* r = new Revista(nombre,isbn,autor,false,edicion,mes);
                materiales[i] = r;
                return;
            }
        }
    }
}
void mostrarMateriales(MaterialBibliografico* materiales[100]){
    for (int i = 0; i<100; i++){
        if (materiales[i] == nullptr){break;}
        cout<<i+1<<".-\n"<<materiales[i]->mostrarInformacion()<<"\n"<<endl;
    }  
}

MaterialBibliografico* buscarMaterial(MaterialBibliografico* materiales[100]){
    cout<<"Ingrese 1 para buscar por nombre\nIngrese 2 para buscar por autor"<<endl;
    string op;
    cin>>op;
    while(op != "1" && op != "2"){
        cout<<"Ingrese 1 para buscar por nombre\nIngrese 2 para buscar por autor"; cin>>op;    
    }
    if(op == "1"){
        string nombre;
        cout<<"Ingrese el nombre del material: ";cin>>nombre;
        for (int i = 0; i < 100; i++){
            if(materiales[i] != nullptr && materiales[i]->getNombre() == nombre){
                return materiales[i];
            }
        }
    }
    if(op == "2"){
        string autor;
        cout<<"Ingrese el nombre del autor: ";cin>>autor;
        for (int i = 0; i < 100; i++){
            if(materiales[i] != nullptr && materiales[i]->getAutor() == autor){
                return materiales[i];
            }
        }
    }
    return nullptr;
}


void guardarBiblioteca(MaterialBibliografico* biblioteca[100]){

    ofstream archivo("materiales.txt");

    if(!archivo.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }    

    for(int i = 0; i < 100; i++){
        if(biblioteca[i] != nullptr){
            archivo << biblioteca[i]->getLine() << endl;
        }
    }

    archivo.close();

    cout<<"Biblioteca guardada exitosamente"<<endl;
}

void cargarBiblioteca(MaterialBibliografico* biblioteca[100]){

    ifstream archivo("materiales.txt");

    if(!archivo.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    int i = 0;
    string linea;

    while(getline(archivo, linea) && i < 100){
        stringstream ss(linea);
        string tipo,nombre,isbn,autor,prestado,edicion,aux1,aux2; 
        getline(ss, tipo, ',');
        getline(ss, nombre, ',');
        getline(ss, isbn, ',');
        getline(ss, autor, ',');
        getline(ss, prestado, ',');
        getline(ss, edicion, ',');
        getline(ss, aux1, ',');
        getline(ss, aux2, ',');

        bool prestadoBool = false;
        if(prestado == "true"){
            prestadoBool = true;
        }

        if(tipo == "Libro"){
            biblioteca[i] = new Libro(nombre,isbn,autor,prestadoBool,aux1,aux2);
        } else if(tipo == "Revista"){
            biblioteca[i] = new Revista(nombre,isbn,autor,prestadoBool,aux1,aux2);
        }

        i++;
    }
    archivo.close();
    cout<<"Se cargó la biblioteca con exito"<<endl;
}
int main() {
    MaterialBibliografico* biblioteca[100] = {nullptr};
    MaterialBibliografico* materialBuscar = nullptr;
    int opcion = 1;
    while (opcion != 0)
    {
        cout<< "Ingrese la acción a realizar\n 1.- Agregar material bibliografico\n 2.- Mostrar informacion de los materiales\n 3.- Buscar un material\n 4.- Prestar y devolver material\n 5.- Gestion de usuarios\n 6.- Guardar/Cargar estado Biblioteca\n 7.- Cargar/Guardar estado Usuarios"<< endl;
        
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            
            agregarMaterial(biblioteca);
            break;

        case 2:
            mostrarMateriales(biblioteca);
            break;

        case 3:
            materialBuscar = buscarMaterial(biblioteca);
            if(materialBuscar != nullptr){
                cout<<"¡Se encontró el material! Aquí está su información: "<<endl;
                cout<<materialBuscar->mostrarInformacion()<<endl;
            }
            else{
                cout<<"No se encontró el material"<<endl;
                cout<<endl;
            }
            break;
        
        case 6:
            string opBiblioteca;
            cout<<"Ingrese 1 para guardar la biblioteca\nIngrese 2 para cargar la biblioteca\n";cin>>opBiblioteca;
            while(opBiblioteca != "1" && opBiblioteca != "2"){
                cout<<"Ingrese 1 para guardar la biblioteca\nIngrese 2 para cargar la biblioteca\n";cin>>opBiblioteca;
            }
            if(opBiblioteca == "1"){
                guardarBiblioteca(biblioteca);
            }
            if(opBiblioteca == "2"){
                cargarBiblioteca(biblioteca);
            }
            break;
        }
    }
    
    cout<<"XD"<<endl;
    delete materialBuscar;
    for(int i = 0; i < 100; i++){
        delete biblioteca[i];
    }
    return 0;
}