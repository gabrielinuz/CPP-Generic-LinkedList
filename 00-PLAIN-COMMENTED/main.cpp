#include <iostream>
#include "LinkedList.hpp"

int main()
{
    // Crea una lista enlazada de enteros.
    LinkedList<int> list;

    // Agrega elementos a la lista.
    list.add(10);
    list.add(20);
    list.add(30);

    // Usa forEach para imprimir todos los elementos de la lista.
    list.forEach([](const int& value) {
        std::cout << "Value: " << value << std::endl;
    });

    // Elimina el elemento '20' de la lista.
    list.remove(20);

    // Imprime los elementos restantes.
    list.forEach([](const int& value) {
        std::cout << "Remaining Value: " << value << std::endl;
    });

    return 0;
}
