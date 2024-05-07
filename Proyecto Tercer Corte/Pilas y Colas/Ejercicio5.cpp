/*Necesitamos crear un programa que le permita al usuario introducir texto, 
que permita hacer modificaciones y que el sistema muestre la anterior modificación o volver a la misma.*/
#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<string> versiones, deshechas;
    int opcion;
    string texto;

    do{
        cout<<"Menú de modificación de texto."<<endl;
        cout<<"(1) Modificar o crear texto."<<endl;
        cout<<"(2) Deshacer modificación."<<endl;
        cout<<"(3) Rehacer modificación."<<endl;
        cout<<"(4) Mostrar texto actual."<<endl;
        cout<<"(5) Salir."<<endl;
        cout<<"Ingrese una opción:"<<endl;
            cin>>opcion;

        switch(opcion){
            case 1:
                if(!texto.empty()){
                    versiones.push(texto);
                }
                cout<<"Texto actual: "<<texto<<endl;
                cout<<"Ingrese el nuevo texto:"<<endl;
                cin.ignore();
                getline(cin, texto);
                break;
            case 2:
                if(!versiones.empty()){
                    deshechas.push(texto);
                    texto = versiones.top();
                    versiones.pop();
                }else{
                    cout<<"No hay versiones anteriores disponibles."<<endl;
                }
                break;
            case 3:
                if(!deshechas.empty()){
                    versiones.push(texto);
                    texto = deshechas.top();
                    deshechas.pop();
                }else{
                    cout<<"No hay versiones para rehacer."<<endl;
                }
                break;
            case 4:
                cout<<"Texto actual: "<<texto<<endl;
                break;
        }
    }while(opcion != 5);

    return 0;
}