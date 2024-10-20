#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <functional>

// Declaración de la clase genérica LinkedList.
template <typename T>
class LinkedList
{
    private:
        // Clase interna Node que representa cada nodo de la lista enlazada.
        struct Node
        {
            T data;  // El dato del nodo, de tipo T.
            Node* next;  // Puntero al siguiente nodo.

            Node(const T& data);  // Constructor de Node.
        };

        Node* head;  // Puntero al primer nodo de la lista (cabeza).
        Node* tail;  // Puntero al último nodo de la lista (cola).

    public:
        LinkedList();  // Constructor de la lista enlazada.
        ~LinkedList();  // Destructor que elimina todos los nodos.

        void add(const T& data);  // Agregar un nuevo nodo al final.
        void remove(const T& data);  // Eliminar el primer nodo que contenga el dato especificado.
        void forEach(const std::function<void(const T&)>& action) const;  // Iterar sobre los nodos y ejecutar una acción.
        void clear();  // Eliminar todos los nodos de la lista.
        bool isEmpty() const;  // Verificar si la lista está vacía.
};

#include "../src/LinkedList.cpp"  // Incluimos el archivo de implementación para evitar problemas con plantillas.

#endif
