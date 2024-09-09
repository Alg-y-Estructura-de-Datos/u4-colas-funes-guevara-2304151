#include <iostream>
#include "Cola/Cola.h"  // Incluye la biblioteca de la Cola
using namespace std;

bool sonIguales(Cola<char> &cola1, Cola<char> &cola2) {
    while (!cola1.esVacia() && !cola2.esVacia()) { //si alguna esta vacia de una ya termina el bucle
        if (cola1.peek() != cola2.peek()) {
            return false; //primera no coincidencia corta la ejecucion del codigo
        }
        cola1.desencolar();
        cola2.desencolar();
    }

    // Si ambas colas están vacías al mismo tiempo, son iguales
    return cola1.esVacia() && cola2.esVacia(); //pero podria ser que una es mas larga con los mismos elementos que la otra
}                                              //si ambas estan vacias,retorna 1, forma de compactar el codigo con booleano

int main() {

    cout << "Ejercicio 04/01" << endl;

    Cola<char> cola1;
    Cola<char> cola2;

    //lo hace como un menu para tener un buen seguimiento
    // Lectura de la primera cola
    cout << "Ingrese caracteres para la primera cola (ingrese '.' para terminar): " << endl;
    char input;
    while (cin >> input && input != '.') {
        cola1.encolar(input);
    }

    // Lectura de la segunda cola
    cout << "Ingrese caracteres para la segunda cola (ingrese '.' para terminar): " << endl;
    while (cin >> input && input != '.') {
        cola2.encolar(input);
    }

    // Comparación de las colas
    if (sonIguales(cola1, cola2)) {
        cout << "Las colas son iguales." << endl;
    } else {
        cout << "Las colas son diferentes." << endl;
    }

    return 0;
}
