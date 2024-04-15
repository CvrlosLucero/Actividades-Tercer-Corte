#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

struct Departamento {
    string capital;
    string clima;
};

map<string, Departamento> colombiaMap;

void addDepartamento(string departamento, string capital, string clima) {
    Departamento info = {capital, clima};
    colombiaMap[departamento] = info;
}

pair<string, string> getCapitalYClima(string departamento) {
    if (colombiaMap.find(departamento) != colombiaMap.end()) {
        return make_pair(colombiaMap[departamento].capital, colombiaMap[departamento].clima);
    } else {
        return make_pair("Nada. :(", "No hay. :(");
    }
}

list<string> getCiudadesConClima(string clima) {
    list<string> ciudades;
    for (auto& item : colombiaMap) {
        if (item.second.clima == clima) {
            ciudades.push_back(item.second.capital);
        }
    }
    return ciudades;
}

int main() {
    addDepartamento("Antioquia", "Medellin", "Tropical");
    addDepartamento("Cundinamarca", "Bogota", "Frio");

    string departamento;
    cout<<"Por favor, ingrese el nombre del departamento: ";
        cin>>departamento;

    pair<string, string> info = getCapitalYClima(departamento);
    if (info.first == "Nada. :(") {
        cout<<"El departamento ingresado no se encuentra en el mapa."<<endl;
    } else {
        cout<<"Departamento: "<<departamento<<endl;
        cout<<"Capital: "<<info.first<<", Clima: "<<info.second<<endl;
    }

    string clima;
    cout<<"Por favor, ingrese un clima: ";
        cin>>clima;

    list<string> ciudades = getCiudadesConClima(clima);
    cout<<"Ciudades con clima "<<clima<<":"<<endl;
    for (string city : ciudades) {
        cout<<city<<endl;
    }

    return 0;
}