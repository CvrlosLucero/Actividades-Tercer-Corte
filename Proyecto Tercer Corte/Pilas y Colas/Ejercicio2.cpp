//Simular turnos de eps para acceder a una sita médica (ingrese documento de identidad y tipo de cita).
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

map<char, pair<string, int>> tiposCita = {
    {'G', {"General", 0}},
    {'E', {"Especialista", 0}},
    {'P', {"Pediatría", 0}},
    {'O', {"Odontología", 0}}
};

struct Turno {
    string documento;
    string idTurno;
    
    Turno(string documento, string idTurno) : documento(documento), idTurno(idTurno) {}
};

void solicitarTurno(queue<Turno>& cola){
    string documento;
    char tipoCita;

    cout<<"Ingrese el documento de identidad:"<<endl;
        cin>>documento;
    cout<<"Ingrese la primera letra del tipo de cita (G para General, E para Especialista, P para Pediatría, O para Odontología.):"<<endl;
        cin>>tipoCita;

    if(tiposCita.count(tipoCita) > 0){
        tiposCita[tipoCita].second++;
        string idTurno = tipoCita + to_string(tiposCita[tipoCita].second);
        cola.push(Turno(documento, idTurno));
    }else{
        cout<<"Tipo de cita no reconocido."<<endl;
    }
}

void mostrarTurnos(queue<Turno> cola){
    while(!cola.empty()){
        cout<<"Turno: "<<cola.front().idTurno<<endl;
        cout<<"Documento de identidad: "<<cola.front().documento<<endl;
        cola.pop();
    }
}

int main(){
    queue<Turno> cola;
    int opcion;

    do{
        cout<<"Menú de turnos."<<endl;
        cout<<"(1) Solicitar turno."<<endl;
        cout<<"(2) Mostrar turnos."<<endl;
        cout<<"(3) Salir."<<endl;
        cout<<"Ingrese una opción:"<<endl;
            cin>>opcion;

        switch(opcion) {
            case 1:
                solicitarTurno(cola);
                break;
            case 2:
                mostrarTurnos(cola);
                break;
        }
    }while(opcion != 3);

    return 0;
}