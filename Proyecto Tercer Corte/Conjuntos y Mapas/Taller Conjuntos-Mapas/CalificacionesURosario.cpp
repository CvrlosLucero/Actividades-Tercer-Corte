#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, map<string, double>> estudiantes;

void registrarNota(string estudiante, string materia, double grade) {
    estudiantes[estudiante][materia] = grade;
}

double getNota(string estudiante, string materia) {
    return estudiantes[estudiante][materia];
}

double getPromedioNotas(string estudiante) {
    double suma = 0.0;
    for (auto& subject : estudiantes[estudiante]) {
        suma += subject.second;
    }
    return suma / estudiantes[estudiante].size();
}

double getPromedioMateria(string materia) {
    double suma = 0.0;
    int cuenta = 0;
    for (auto& student : estudiantes) {
        if (student.second.find(materia) != student.second.end()) {
            suma += student.second[materia];
            cuenta++;
        }
    }
    return suma / cuenta;
}

int main() {
    string estudiante;
    string materia;
    double grade;
    int eleccion;

    while(true){

    cout<<"1. Registrar nota"<<endl;
    cout<<"2. Consultar nota"<<endl;
    cout<<"3. Consultar promedio de notas de un estudiante"<<endl;
    cout<<"4. Consultar promedio de notas de una asignatura"<<endl;
    cout<<"Ingrese el numero de la opcion que desea: ";
        cin>>eleccion;

    switch (eleccion){
        case 1:{
            cout<<"Ingrese el nombre del estudiante: ";
                cin>>estudiante;
            cout<<"Ingrese el nombre de la asignatura: ";
                cin>>materia;
            cout<<"Ingrese la nota: ";
                cin>>grade;
            registrarNota(estudiante, materia, grade);
            break;
        }
        case 2:{
            cout<<"Ingrese el nombre del estudiante: ";
                cin>>estudiante;
            cout<<"Ingrese el nombre de la asignatura: ";
                cin>>materia;
            cout<<"La nota de "<<estudiante<<" en "<<materia<<" es: "<<getNota(estudiante, materia)<<endl;
            break;
        }
        case 3:{
            cout<<"Ingrese el nombre del estudiante: ";
                cin>>estudiante;
            cout<<"El promedio de notas de "<<estudiante<<" es: "<<getPromedioNotas(estudiante)<<endl;
            break;
        }
        case 4:{
            cout<<"Ingrese el nombre de la asignatura: ";
            cin>>materia;
            cout << "El promedio de notas en "<<materia<<" es: "<<getPromedioMateria(materia)<<endl;
            break;
        }
        default:
            cout<<"Opcion no valida"<<endl;
            return false;
    }
    }
    return 0;
}