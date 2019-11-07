//
// Created by lica-pc on 11/7/19.
//
#include <list>
#include <iostream>
#include <string>
#include <map>

using namespace std;

auto leer(list<string> productos, map<string,int> aliasimpor, const string &file_name ){
    string alias0;
    int importe0 = 0;
    string producto0;

    ifstream file_subasta(file_name);
    if(!file_subasta.is_open()){
        cout << "ERROR"<<endl;
    }
    else {
        do {
            getline(file_subasta, producto0);
            productos.push_back(producto0);
            cout<<producto0<<endl;
            while (file_subasta >> alias0 >> importe0) {
                aliasimpor[alias0] = importe0;
            }
        } while (!isupper(producto0[0]));

    }

    file_subasta.close();

    for (auto &p : aliasimpor) {
        cout << p.first << " " << p.second << endl;
    }
    return aliasimpor;
}


int menor_importe(const map<string,int> &aliasimporte)
{
    auto iter = aliasimporte.begin();
    int menor = iter->second;
    for(auto it = iter; it != aliasimporte.end(); ++it)
    {
        if(it->second < menor)
            menor = it->second;
    }

    return menor;
}

int mayor_importe(const map<string, int> &aliasimpor)
{
    auto iter = aliasimpor.begin();
    int mayor = iter->second;
    for(auto it = iter; it != aliasimpor.end(); ++it)
    {
        if(it->second > mayor)
            mayor = it->second;
    }
    return mayor;
}

int prom(const map<string, int> &aliasimpor){
    auto iter = aliasimpor.begin();
    int sum = 0;
    int prom = 0;
    for(auto it = iter; it != aliasimpor.end(); ++it)
    {
        sum += it->second;
    }

    prom = sum/aliasimpor.size();

    return prom;
}

void sort(const map<string, int> &aliasimpor) {
    int begin = menor_importe(aliasimpor);
    int end = mayor_importe(aliasimpor);
    for (int i = end; i >= begin; --i) {
        for (auto it = aliasimpor.begin(); it != aliasimpor.end(); ++it) {
            if (it->second == i) {
                cout << it->first << "\t" << it->second << endl;
            }
        }
    }

}