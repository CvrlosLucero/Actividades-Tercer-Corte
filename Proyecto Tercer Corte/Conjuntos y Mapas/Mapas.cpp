#include <iostream>
#include <map>

using namespace std;

int main() {
    
    //se usa map <tipo de dato, tipo de dato> nombre para crear un mapa
    map<int, string> frutas;

    /*
    las operaciones comunes son:
    insert(pair<tipo de dato, tipo de dato>(elemento, elemento)) para agregar un elemento al mapa
    erase(elemento) para eliminar un elemento del mapa
    find(elemento) para buscar un elemento en el mapa
    clear() para eliminar todos los elementos del mapa
    empty() para verificar si el mapa esta vacio
    size() para obtener el tamaño del mapa
    */


    //insertar elementos al mapa
    frutas[1] = "Manzana";
    frutas[2] = "Pera";
    frutas[3] = "Banano";
    frutas[4] = "Uva";

    //imprimir los elementos del mapa
    cout<<"Frutas en el mapa:"<<endl;
    for (const auto& fruta : frutas) {
        cout<<fruta.first<<". "<<fruta.second<<endl;
    }

    //buscar un elemento (clave) en el mapa
    int key;
    cout<<"Ingrese un numero para buscar en el mapa: ";
        cin>>key;
    
    if (frutas.find(key) != frutas.end()) {
        cout<<"El numero "<<key<<" se encuentra en el mapa."<<endl;
    } else {
        cout<<"El numero "<<key<<" no se encuentra en el mapa."<<endl;
    }

    //buscar el valor de una clave en el mapa
    string valor;
    cout<<"Ingrese una fruta para buscar en el mapa: ";
        cin>>valor;
    for (const auto& fruta : frutas) {
        if (fruta.second == valor) {
            cout<<"La fruta "<<valor<<" se encuentra en el mapa."<<endl;
            break;
        }
        else {
            cout<<"La fruta "<<valor<<" no se encuentra en el mapa."<<endl;
            break;
        }
    }
    
    return 0;
}