#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <memory>
#include <functional>

template <typename T>
class LinkedList 
{
    private:
        // Estructura Nodo que almacena el dato y el puntero al siguiente nodo
        struct Node {
            T data;
            std::shared_ptr<Node> next;
            Node(const T& data) : data(data), next(nullptr) {}
        };

        std::shared_ptr<Node> head;  // Puntero a la cabeza de la lista

    public:
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        
        void add(const T& data);  // Agregar un nodo al final de la lista
        void remove(const T& data);  // Eliminar el nodo con el valor proporcionado
        void forEach(const std::function<void(const T&)>& func) const;  // Aplicar una función a cada elemento de la lista
};

#include "../src/LinkedList.cpp"  // Incluimos el archivo de implementación para evitar problemas con plantillas.

#endif // LINKEDLIST_HPP
