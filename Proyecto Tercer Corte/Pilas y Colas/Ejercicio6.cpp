/*Necesitamos crear un programa que le permita al usuario llevar un orden en las impresiones en una oficina. 
Debe mostrar lo que imprime y mostrar lo que le falta imprimir.*/
#include <iostream>
#include <queue>

using namespace std;

struct Impresion{
    string documento;
    int cantidadPaginas;

    Impresion(string documento, int cantidadPaginas) : documento(documento), cantidadPaginas(cantidadPaginas) {}
};

int main() {
    queue<Impresion> colaImpresiones;
    int opcion;
    string documento;
    int cantidadPaginas;

    do{
        cout<<"Menú de impresiones."<<endl;
        cout<<"(1) Agregar impresión."<<endl;
        cout<<"(2) Mostrar cola de impresiones."<<endl;
        cout<<"(3) Imprimir documento actual."<<endl;
        cout<<"(4) Salir."<<endl;
            cin>>opcion;

        switch(opcion){
            case 1:
                    cout<<"Ingrese el nombre del documento:"<<endl;
                        cin.ignore();
                        getline(cin, documento);
                    cout<<"Ingrese la cantidad de páginas a imprimir:"<<endl;
                        cin>>cantidadPaginas;
                    colaImpresiones.push(Impresion(documento, cantidadPaginas));
                break;
            case 2:
                cout<<"Impresiones pendientes:"<<endl;
                for(int i = 0; i < colaImpresiones.size(); i++){
                    cout<<i+1<<". "<<colaImpresiones.front().documento<<" - "<<colaImpresiones.front().cantidadPaginas<<" páginas."<<endl;
                    colaImpresiones.push(colaImpresiones.front());
                    colaImpresiones.pop();
                }
                break;
            case 3:
                if(!colaImpresiones.empty()){
                    cout<<"Imprimiendo: "<<colaImpresiones.front().documento<<" - "<<colaImpresiones.front().cantidadPaginas<<" páginas."<<endl;
                    colaImpresiones.pop();
                }else{
                    cout<<"No hay impresiones pendientes."<<endl;
                }
                break;
        }
    }while(opcion != 4);

    return 0;
}


