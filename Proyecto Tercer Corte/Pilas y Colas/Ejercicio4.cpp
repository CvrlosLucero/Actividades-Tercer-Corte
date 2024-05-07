/*Necesitamos crear un programa que le permita al usuario crear una lista para hacer mercado. 
Luego que se vea esa lista y que se vaya sacando los elementos del mercado desde el primero hasta el ultimo.*/
#include <iostream>
#include <queue>

using namespace std;

struct Producto{
    string nombre;
    int cantidad;
    
    Producto(string nombre, int cantidad) : nombre(nombre), cantidad(cantidad) {}
};

int main(){
    queue<Producto> mercado;
    int opcion;
    string nombre;
    int cantidad;

    do{
        cout<<"Menú de mercado."<<endl;
        cout<<"(1) Agregar producto."<<endl;
        cout<<"(2) Mostrar lista de mercado."<<endl;
        cout<<"(3) Sacar producto."<<endl;
        cout<<"(4) Salir."<<endl;
        cout<<"Ingrese una opción:"<<endl;
            cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese el nombre del producto:"<<endl;
                    cin.ignore();
                    getline(cin, nombre);
                cout<<"Ingrese la cantidad del producto:"<<endl;
                    cin>>cantidad;
                mercado.push(Producto(nombre, cantidad));
                break;
            case 2:
                cout<<"Lista de mercado:"<<endl;
                for(int i = 0; i < mercado.size(); i++){
                    cout<<i+1<<". "<<mercado.front().nombre<<" - "<<mercado.front().cantidad<<endl;
                    mercado.push(mercado.front());
                    mercado.pop();
                }
                break;
            case 3:
                if(!mercado.empty()){
                    cout<<"Se ha sacado el producto "<<mercado.front().nombre<<" de la lista."<<endl;
                    mercado.pop();
                }else{
                    cout<<"La lista de mercado está vacía."<<endl;
                }
                break;
        }

    }while(opcion != 4);
    
    return 0;
}