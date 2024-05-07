/*Crear Lista de canciones o videos favoritos de youtube y decir si es una pila o una cola.*/
/* Respuesta: Es una cola debido a que a medida que se agrega una canción a la lista, se acumula y al momento de imprimirla, se verifica desde 
el primer ingreso hasta el último.*/
#include <iostream>
#include <queue>

using namespace std;

struct Video {
    string nombre;
    string duracion;
    int posicion;

    Video(string nombre, string duracion, int posicion) : nombre(nombre), duracion(duracion), posicion(posicion) {}
};

bool posicionExiste(queue<Video> cola, int posicion){
    while(!cola.empty()){
        if(cola.front().posicion == posicion){
            return true;
        }
        cola.pop();
    }
    return false;
}

void agregarVideo(queue<Video>& cola){
    string nombre;
    string duracion;
    int posicion;

    cout<<"Ingrese el nombre del video: "<<endl;
        cin.ignore();
        getline(cin, nombre);
    cout<<"Ingrese la duración del video: "<<endl;
        cin>>duracion;
    cout<<"Ingrese la posición en la cola: "<<endl;
        cin>>posicion;

    if(posicionExiste(cola, posicion)){
        cout<<"La posición ya existe en la cola."<<endl;
        return;
    }

    cola.push(Video(nombre, duracion, posicion));
}

void imprimirCola(queue<Video> cola){
    while(!cola.empty()) {
        cout<<"Nombre del video: "<<cola.front().nombre<<endl;
        cout<<"Duración del video (en segundos): "<<cola.front().duracion<<endl;
        cout<<"Posición en la cola: "<<cola.front().posicion<<endl;
        cola.pop();
    }
}


int main() {
    queue<Video> cola;
    int opcion;

    do{
        cout<<"Menú de lista."<<endl;
        cout<<"(1) Agregar video."<<endl;
        cout<<"(2) Imprimir cola."<<endl;
        cout<<"(3) Salir."<<endl;
        cout<<"Ingrese una opción: "<<endl;
            cin>>opcion;

        switch(opcion){
            case 1:
                agregarVideo(cola);
                break;
            case 2:
                imprimirCola(cola);
                break;
        }

    }while(opcion != 3);

    return 0;
}