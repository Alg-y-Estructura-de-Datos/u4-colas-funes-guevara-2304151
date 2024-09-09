/*Implementar una función que suprima de la cola todos los elementos mayores que un número “n” dado como límite.
 Al final se debe imprimir la cola depurada sin perder el orden que había desde la cola original. */

#include <iostream>
#include "Cola/Cola.h"
using namespace std;


void eliminarMayor(Cola<int> &cola, int limite) {
    Cola<int> colaAux;  // Cola auxiliar para mantener los elementos menores o iguales a "n"

    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato <= limite) {
                colaAux.encolar(dato);  // Solo se agregan los elementos menores o iguales a "n"
            }
        }

        // Transferir los elementos de la cola auxiliar a la cola original
        while (!colaAux.esVacia()) { //paso los menores o iguales al limite a la colaorg
            cola.encolar(colaAux.desencolar());
        }
    }



int main() {

        cout << "Ejercicio N 2" << endl;

        Cola<int> cola;
        int limite;

        // Lectura de la cola
        cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
        int input;
        while (cin >> input && input != -1) {
            cola.encolar(input);
        }

        // Lectura del límite
        cout << "Ingrese el limite: ";
        cin >> limite;

        // Eliminar los elementos mayores que el límite
        eliminarMayor(cola, limite);

        // Mostrar la cola depurada
        cout << "Cola depurada: ";
        while (!cola.esVacia()) {
            cout << cola.desencolar() << " ";
        }
        cout << endl;

        return 0;
    }

