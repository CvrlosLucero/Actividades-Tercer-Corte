#include <iostream>
#include <string>
#include <map>

using namespace std;

pair<string, int> simpleHash(string& texto){
    int hash = 0;
    for(char c : texto){
        hash += c;
    }
    return make_pair(texto, hash);
}

int main() {
    pair<string, int> hashes;

    cout<<"Ingrese el texto a hashear:"<<endl;
    cin.ignore();
    getline(cin, hashes.first);

    hashes = simpleHash(hashes.first);

    cout<<"Texto: "<<hashes.first<<endl;
    cout<<"Hash: "<<hashes.second<<endl;

    return 0;
}