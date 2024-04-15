#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, map<string, double>> students;

void registerGrade(string studentName, string subjectName, double grade) {
    students[studentName][subjectName] = grade;
}

double getGrade(string studentName, string subjectName) {
    return students[studentName][subjectName];
}

double getAverageGrade(string studentName) {
    double sum = 0.0;
    for (auto& subject : students[studentName]) {
        sum += subject.second;
    }
    return sum / students[studentName].size();
}

double getSubjectAverage(string subjectName) {
    double sum = 0.0;
    int count = 0;
    for (auto& student : students) {
        if (student.second.find(subjectName) != student.second.end()) {
            sum += student.second[subjectName];
            count++;
        }
    }
    return sum / count;
}

int main() {
    string studentName;
    string subjectName;
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
            cin>>studentName;
            cout<<"Ingrese el nombre de la asignatura: ";
            cin>>subjectName;
            cout<<"Ingrese la nota: ";
            cin>>grade;
            registerGrade(studentName, subjectName, grade);
            break;
        }
        case 2:{
            cout<<"Ingrese el nombre del estudiante: ";
                cin>>studentName;
            cout<<"Ingrese el nombre de la asignatura: ";
                cin>>subjectName;
            cout<<"La nota de "<<studentName<<" en "<< subjectName<<" es: "<<getGrade(studentName, subjectName)<<endl;
            break;
        }
        case 3:{
            cout<<"Ingrese el nombre del estudiante: ";
                cin>>studentName;
            cout<<"El promedio de notas de "<<studentName<<" es: "<<getAverageGrade(studentName)<<endl;
            break;
        }
        case 4:{
            cout<<"Ingrese el nombre de la asignatura: ";
            cin>>subjectName;
            cout << "El promedio de notas en "<<subjectName<<" es: "<<getSubjectAverage(subjectName)<<endl;
            break;
        }
        default:
            cout<<"Opcion no valida"<<endl;
            return false;
    }
    }
    return 0;
}