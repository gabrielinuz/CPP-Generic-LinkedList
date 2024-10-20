#include "../include/LinkedList.hpp"

// Constructor: Inicializa head como nullptr, indicando que la lista está vacía.
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

// Destructor: No es necesario liberar manualmente los recursos porque los shared_ptr lo gestionan.
template <typename T>
LinkedList<T>::~LinkedList() {
    // No se requiere acción especial gracias a shared_ptr
}

// Método para agregar un nuevo nodo al final de la lista
template <typename T>
void LinkedList<T>::add(const T& data) {
    auto newNode = std::make_shared<Node>(data);  // Crea un nuevo nodo usando shared_ptr
    if (!head) {
        head = newNode;  // Si la lista está vacía, el nuevo nodo es la cabeza
    } else {
        auto temp = head;
        while (temp->next) {
            temp = temp->next;  // Recorre la lista hasta el último nodo
        }
        temp->next = newNode;  // Añade el nuevo nodo al final
    }
}

// Método para eliminar un nodo por valor
template <typename T>
void LinkedList<T>::remove(const T& data) {
    if (!head) return;  // Si la lista está vacía, no se hace nada

    if (head->data == data) {
        head = head->next;  // Si el nodo a eliminar es la cabeza, la cabeza se actualiza al siguiente
        return;
    }

    auto temp = head;
    while (temp->next && temp->next->data != data) {
        temp = temp->next;  // Recorre la lista buscando el nodo con el valor proporcionado
    }

    if (temp->next) {
        temp->next = temp->next->next;  // Si encuentra el nodo, lo salta en la cadena
    }
}

// Método forEach para aplicar una función a cada nodo de la lista
template <typename T>
void LinkedList<T>::forEach(const std::function<void(const T&)>& func) const {
    auto temp = head;
    while (temp) {
        func(temp->data);  // Aplica la función proporcionada al dato del nodo actual
        temp = temp->next;  // Pasa al siguiente nodo
    }
}

// Asegúrate de incluir esta declaración para que las implementaciones de las plantillas sean visibles
//template class LinkedList<int>;  // Ejemplo de instancia para int
//template class LinkedList<std::string>;  // Ejemplo de instancia para std::string
