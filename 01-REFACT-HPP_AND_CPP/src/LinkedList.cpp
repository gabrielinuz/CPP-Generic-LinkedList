#include "../include/LinkedList.hpp"

// Constructor del nodo que inicializa el dato y el puntero al siguiente nodo.
template <typename T>
LinkedList<T>::Node::Node(const T& data) : data(data), next(nullptr) {}

// Constructor de la lista enlazada que inicializa la cabeza y la cola como nulas.
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// Destructor que limpia todos los nodos de la lista enlazada.
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();  // Llama a la función clear para eliminar todos los nodos.
}

// Función para agregar un nuevo nodo al final de la lista.
template <typename T>
void LinkedList<T>::add(const T& data)
{
    Node* newNode = new Node(data);  // Crea un nuevo nodo con el dato proporcionado.

    if (tail)  // Si la lista no está vacía,
    {
        tail->next = newNode;  // El último nodo apunta al nuevo nodo.
    }
    else  // Si la lista está vacía,
    {
        head = newNode;  // El nuevo nodo también es el primer nodo.
    }

    tail = newNode;  // Actualizamos tail al nuevo nodo.
}

// Función para eliminar el primer nodo que contenga el valor especificado.
template <typename T>
void LinkedList<T>::remove(const T& data)
{
    Node* current = head;  // Comienza desde la cabeza de la lista.
    Node* prev = nullptr;  // Almacena el nodo anterior durante la iteración.

    while (current)  // Mientras haya nodos por recorrer,
    {
        if (current->data == data)  // Si el nodo contiene el dato buscado,
        {
            if (prev)  // Si no es el primer nodo,
            {
                prev->next = current->next;  // Saltamos el nodo actual.
            }
            else  // Si es el primer nodo,
            {
                head = current->next;  // La cabeza ahora es el siguiente nodo.
            }

            if (current == tail)  // Si es el último nodo,
            {
                tail = prev;  // La cola se actualiza al nodo anterior.
            }

            delete current;  // Liberamos la memoria del nodo eliminado.
            return;
        }

        prev = current;  // Actualizamos el nodo anterior.
        current = current->next;  // Avanzamos al siguiente nodo.
    }
}

// Función para recorrer la lista y aplicar una función (action) a cada nodo.
template <typename T>
void LinkedList<T>::forEach(const std::function<void(const T&)>& action) const
{
    Node* current = head;  // Comienza desde la cabeza.

    while (current)  // Mientras haya nodos por recorrer,
    {
        action(current->data);  // Ejecuta la acción con el dato del nodo actual.
        current = current->next;  // Avanza al siguiente nodo.
    }
}

// Función para eliminar todos los nodos de la lista.
template <typename T>
void LinkedList<T>::clear()
{
    Node* current = head;  // Comienza desde la cabeza de la lista.

    while (current)  // Mientras haya nodos por eliminar,
    {
        Node* toDelete = current;  // Guarda el nodo actual para eliminarlo.
        current = current->next;  // Avanza al siguiente nodo.
        delete toDelete;  // Libera la memoria del nodo.
    }

    head = nullptr;  // Reinicia la cabeza de la lista.
    tail = nullptr;  // Reinicia la cola de la lista.
}

// Función que devuelve si la lista está vacía o no.
template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == nullptr;  // Si la cabeza es nullptr, la lista está vacía.
}
