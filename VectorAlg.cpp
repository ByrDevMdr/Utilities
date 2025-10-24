#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Crear vector y llenarlo manualmente -> for(i = 0; i < sizeDefinida; i++){ count <<"Imgrese el numero: "<<endl; cin>> numero;numeros.push_back(numero);}
    vector<int> numeros;
    numeros.push_back(15);
    numeros.push_back(3);
    numeros.push_back(8);
    numeros.push_back(20);
    numeros.push_back(1);
    numeros.push_back(9);
    numeros.push_back(12);
    numeros.push_back(6);
    
    cout << "Original: ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    // Truncar
    numeros.resize(5); // Hardoceado -> count<<"Ingresar datos: "<<endl; cin>>variable;
    cout << "Truncado: ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    // Ordenar
    sort(numeros.begin(), numeros.end());
    cout << "Ordenado: ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    return 0;
}
