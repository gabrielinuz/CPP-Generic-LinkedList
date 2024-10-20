#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <functional>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head; // Apuntador al primer nodo de la lista
    Node* tail; // Apuntador al último nodo de la lista
    int size;   // Tamaño actual de la lista

public:
    LinkedList();
    ~LinkedList();

    void add(const T& element);       // Método para añadir elementos
    void remove(const T& element);    // Método para remover elementos
    void forEach(const std::function<void(const T&)>& action) const; // Método para iterar sobre la lista

    int getSize() const;
    bool isEmpty() const;
};

// Implementación de métodos fuera de la clase

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

template <typename T>
void LinkedList<T>::add(const T& element) {
    Node* newNode = new Node(element);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove(const T& element) {
    if (isEmpty()) return;

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == element) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            size--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::forEach(const std::function<void(const T&)>& action) const {
    Node* current = head;
    while (current != nullptr) {
        action(current->data); // Ejecuta la acción recibida sobre cada nodo
        current = current->next;
    }
}

template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

#endif // LINKEDLIST_HPP
