#include <iostream>
#include <set>
#include <string>
#include <algorithm>


using namespace std;

//se usa set <tipo de dato> nombre para crear un conjunto
set<string> conjunto;

/*las operaciones comunes son: 
insert(elemento) para agregar un elemento al conjunto
erase(elemento) para eliminar un elemento del conjunto
find(elemento) para buscar un elemento en el conjunto
clear() para eliminar todos los elementos del conjunto
empty() para verificar si el conjunto esta vacio
size() para obtener el tamaño del conjunto
add(elemento) para agregar un elemento al conjunto

*/
int main() {
    cout<<"Conjunto de frutas."<<endl;
    conjunto.insert("Manzana");
    conjunto.insert("Pera");
    conjunto.insert("Banano");
    conjunto.insert("Uva");

    //Mostrar el tamaño del conjunto
    cout<<"El conjunto tiene "<<conjunto.size()<<" elementos."<<endl;

    //impresion de los elementos del conjunto sin crear una copia de cada elemento
    cout<<"Frutas en el conjunto:"<<endl;
    for (const string& fruta : conjunto) {
        cout<<fruta<<endl;
    }
    /*
    Esta manera es para modificar todos los valores del conjunto o también para imprimir pero crea una copia de cada elemento
    for(string fruta : conjunto){
        cout<<fruta<<endl;
    }
    */

    //Buscar un elemento en el conjunto
    string fruta;
    cout<<"Ingrese una fruta para buscar en el conjunto: ";
        cin>>fruta;
    if (conjunto.find(fruta) != conjunto.end()) {
        cout<<"La fruta "<<fruta<<" se encuentra en el conjunto."<<endl;
    } else {
        cout<<"La fruta "<<fruta<<" no se encuentra en el conjunto."<<endl;
    }

    //Eliminar un elemento del conjunto
    cout<<"Ingrese una fruta para eliminar del conjunto: ";
        cin>>fruta;
    conjunto.erase(fruta);
    //verificar si el conjunto esta vacio
    if (conjunto.empty()) {
        cout<<"El conjunto esta vacio."<<endl;
    } else {
        cout<<"El conjunto no esta vacio."<<endl;
    }

    //Ejercicio: conjunto de canciones de reproducción (van a tener 3 canciones y luego se agrega una más, se eliminan dos y buscan una)
    set<string> canciones;
    canciones.insert("asd");
    canciones.insert("asdf");
    canciones.insert("asdfg");

    string cancion;
    cout<<"Ingrese una cancion para agregar al conjunto: ";
        cin>>cancion;

    string cancion2;
    cout<<"Ingrese una cancion para eliminar al conjunto: ";
        cin>>cancion2;

    if(canciones.find(cancion2) != canciones.end()){
        canciones.erase(cancion2);
    }else{
        cout<<"La cancion "<<cancion2<<" no se encuentra en el conjunto."<<endl;
    }
 

    cout<<"Ingrese una cancion para buscar del conjunto: ";
        cin>>cancion;
    
    if (canciones.find(cancion) != canciones.end()) {
        cout<<"La cancion "<<cancion<<" se encuentra en el conjunto."<<endl;
    } else {
        cout<<"La cancion "<<cancion<<" no se encuentra en el conjunto."<<endl;
    }

    set<int> conjuntoA={1,2,3,4,5};
    set<int> conjuntoB={3,4,5,6,7};

    //interseccion forma 1

    set<int> interseccion;
    for(int elemento : conjuntoA){
        if(conjuntoB.find(elemento) != conjuntoB.end()){
            interseccion.insert(elemento);
        }
        cout<<elemento<<endl;
    }
    for(int elemento:interseccion){
        cout<<elemento<<endl;
    }

    //interseccion forma 2

    set<int> interseccion2;
    for(int elemento : conjuntoA){
        if(conjuntoB.find(elemento) != conjuntoB.end()){
            interseccion2.insert(elemento);
        }
    }

    for(int elemento:interseccion2){
        cout<<elemento<<endl;
    }
    

    //union de conjuntos forma 1
    set<int> unionAB;
    for(int elemento : conjuntoA){
        unionAB.insert(elemento);
    }
    for(int elemento : conjuntoB){
        unionAB.insert(elemento);
    }

    for(int elemento:unionAB){
        cout<<elemento<<endl;
    }
    
    //union de conjuntos forma 2
    set<int> unionAB2=conjuntoA;
    unionAB2.insert(conjuntoB.begin(), conjuntoB.end());

    for(int elemento:unionAB2){
        cout<<elemento<<endl;
    }

    //diferencia de conjuntos forma 1
    
    set<int> diferencia;
    for(int elemento : conjuntoA){
        if(conjuntoB.find(elemento) == conjuntoB.end()){
            diferencia.insert(elemento);
        }
    }

    for(int elemento:diferencia){
        cout<<elemento<<endl;
    }

    //diferencia de conjuntos forma 2
    set<int> diferencia2;
    set_difference(conjuntoA.begin(), conjuntoA.end(), conjuntoB.begin(), conjuntoB.end(), inserter(diferencia2, diferencia2.begin()));

    for(int elemento:diferencia2){
        cout<<elemento<<endl;
    }

    return 0;
}