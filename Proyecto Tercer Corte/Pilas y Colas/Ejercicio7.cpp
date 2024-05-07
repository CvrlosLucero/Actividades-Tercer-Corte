/*Necesitamos crear un sistema para fila virtual, ingresa al sistema y lo pone en la fila. 
Mostrar en que posición está y cuanto se demora. Mostrar cuando ya llegue para comprar boleta.*/
#include <iostream>
#include <queue>
#include <ctime>
#include <map>

using namespace std;

struct Persona {
    string nombre;
    int edad;
};

int main() {
    queue<Persona> fila;
    map<string, int> posiciones;
    int opcion;
    string nombre;
    int edad;
    time_t ultimoRegistro = time(0);
    int tiempoRestante = 0;
    bool primerRegistro = true;

    do{
        time_t ahora = time(0);
        int segundosPasados = difftime(ahora, ultimoRegistro);
        tiempoRestante = max(0, tiempoRestante - segundosPasados);
        ultimoRegistro = ahora;

        cout<<"Menú de fila virtual."<<endl;
        cout<<"(1) Registrarse"<<endl;
        cout<<"(2) Posiciones en la fila."<<endl;
        cout<<"(3) Comprar boleta"<<endl;
        cout<<"(4) Salir"<<endl;
        cout<<"Ingrese una opción:"<<endl;
            cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese su nombre:"<<endl;
                    cin.ignore();
                    getline(cin, nombre);
                cout<<"Ingrese su edad:"<<endl;
                    cin>>edad;
                if(edad < 18){
                    cout<<"Lo sentimos, debes tener al menos 18 años para registrarte."<<endl;
                }else{
                    fila.push(Persona{nombre, edad});
                    posiciones[nombre] = fila.size();
                    if(!primerRegistro){
                        tiempoRestante += 60;
                    }
                    primerRegistro = false;
                }
                break;
            case 2:
                cout<<"Posiciones en la fila: "<<fila.size()<<endl;
                break;
            case 3:
                cout<<"Ingrese su nombre:"<<endl;
                    cin.ignore();
                    getline(cin, nombre);
                if(!fila.empty() && fila.front().nombre == nombre){
                    cout<<nombre<<" ha comprado su boleta."<<endl;
                    cout<<"Estabas en la posición "<<posiciones[nombre]<<" en la fila."<<endl;
                    fila.pop();
                    tiempoRestante = 0;
                }else if(tiempoRestante > 0){
                    if(posiciones.find(nombre) != posiciones.end()){
                        cout<<"Debe esperar hasta que el tiempo restante sea 0 para comprar otra boleta."<<endl;
                        cout<<"Tiempo restante: "<<tiempoRestante<<" segundos."<<endl;
                        cout<<"Actualmente estás en la posición "<<posiciones[nombre]<<" en la fila."<<endl;
                    }else{
                        cout<<"No estás registrado en la fila."<<endl;
                    }
                }else if(!fila.empty()){
                    cout<<"El nombre ingresado no coincide con la persona en la parte delantera de la fila."<<endl;
                }else{
                    cout<<"No hay personas en la fila."<<endl;
                }
                break;
        }
    }while(opcion != 4);

    return 0;
}
