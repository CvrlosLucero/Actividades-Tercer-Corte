/*Necesitamos crear un programa que le permita al usuario crear una lista de llamadas telefónicas recientes. 
Luego se muestre la lista de llamadas de la mas reciente a la mas antigua.*/
#include <iostream>
#include <stack>

using namespace std;

struct Llamada{
    string nombreContacto;
    string numero;
    int duracion;
    string tipoLlamada;
    
    Llamada(string nombreContacto, string numero, int duracion, string tipoLlamada) : nombreContacto(nombreContacto), numero(numero), duracion(duracion), tipoLlamada(tipoLlamada) {}
};

int main(){
    stack<Llamada> llamadas;
    int opcion;
    string nombreContacto, numero, tipoLlamada;
    int duracion;

    do{
        cout<<"Menú de llamadas telefónicas."<<endl;
        cout<<"(1) Agregar llamada."<<endl;
        cout<<"(2) Mostrar llamadas."<<endl;
        cout<<"(3) Salir."<<endl;
        cout<<"Ingrese una opción:"<<endl;
            cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese el nombre del contacto:"<<endl;
                    cin>>nombreContacto;
                cout<<"Ingrese el número de la llamada:"<<endl;
                    cin>>numero;
                cout<<"Ingrese la duración de la llamada (en minutos):"<<endl;
                    cin>>duracion;
                cout<<"Ingrese el tipo de llamada (saliente o entrante):"<<endl;
                    cin>>tipoLlamada;
                llamadas.push(Llamada(nombreContacto, numero, duracion, tipoLlamada));
                break;
            case 2:
                while(!llamadas.empty()){
                    cout<<"Llamada a: "<<llamadas.top().nombreContacto<<", número: "<<llamadas.top().numero<<", duración: "<<llamadas.top().duracion<<" minutos, tipo: "<<llamadas.top().tipoLlamada<<endl;
                    llamadas.pop();
                }
                break;
        }
    }while(opcion != 3);

    return 0;
}