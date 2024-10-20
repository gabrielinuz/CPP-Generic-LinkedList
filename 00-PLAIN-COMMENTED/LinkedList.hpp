#include <iostream>
#include <functional>

// Clase genérica LinkedList que usará plantillas para soportar cualquier tipo de dato.
template <typename T>
class LinkedList
{
    private:
        // Clase Node encapsula cada elemento de la lista enlazada
        struct Node
        {
            T data;  // Dato que almacena el nodo, de tipo T (puede ser cualquier tipo).
            Node* next;  // Puntero al siguiente nodo en la lista.

            // Constructor del nodo que inicializa los datos y el puntero next.
            Node(const T& data) : data(data), next(nullptr) {}
        };

        Node* head;  // Puntero al primer nodo de la lista (la "cabeza").
        Node* tail;  // Puntero al último nodo de la lista (la "cola").

    public:
        // Constructor que inicializa la lista vacía.
        LinkedList() : head(nullptr), tail(nullptr) {}

        // Destructor para liberar la memoria cuando se destruye la lista.
        ~LinkedList()
        {
            clear();  // Llama a la función clear para eliminar todos los nodos.
        }

        // Función que agrega un elemento al final de la lista.
        void add(const T& data)
        {
            Node* newNode = new Node(data);  // Crea un nuevo nodo con el dato.

            if (tail)  // Si la lista no está vacía (es decir, si tail no es nullptr),
            {
                tail->next = newNode;  // El último nodo apunta al nuevo nodo.
            }
            else  // Si la lista está vacía (tail es nullptr),
            {
                head = newNode;  // El nuevo nodo es también el primer nodo.
            }
            
            tail = newNode;  // Actualizamos tail al nuevo nodo.
        }

        // Función que elimina el primer nodo que contiene el valor especificado.
        void remove(const T& data)
        {
            Node* current = head;  // Comienza desde la cabeza de la lista.
            Node* prev = nullptr;  // Almacena el nodo anterior durante la iteración.

            while (current)  // Itera mientras haya nodos.
            {
                if (current->data == data)  // Si el nodo actual tiene el dato que buscamos,
                {
                    if (prev)  // Si no es el primer nodo,
                    {
                        prev->next = current->next;  // Saltamos el nodo actual.
                    }
                    else  // Si es el primer nodo,
                    {
                        head = current->next;  // La cabeza ahora es el siguiente nodo.
                    }

                    if (current == tail)  // Si estamos eliminando el último nodo,
                    {
                        tail = prev;  // Actualizamos tail al nodo anterior.
                    }

                    delete current;  // Liberamos la memoria del nodo eliminado.
                    return;
                }

                prev = current;  // Actualizamos el nodo anterior.
                current = current->next;  // Avanzamos al siguiente nodo.
            }
        }

        // Función para iterar sobre la lista y ejecutar una función pasada como parámetro.
        void forEach(const std::function<void(const T&)>& action) const
        {
            Node* current = head;  // Comienza desde la cabeza de la lista.

            while (current)  // Mientras haya nodos por recorrer,
            {
                action(current->data);  // Ejecuta la función action con el dato del nodo actual.
                current = current->next;  // Avanza al siguiente nodo.
            }
        }

        // Función que limpia la lista eliminando todos los nodos.
        void clear()
        {
            Node* current = head;  // Comienza desde la cabeza.

            while (current)  // Mientras haya nodos por eliminar,
            {
                Node* toDelete = current;  // Guarda el nodo actual para eliminarlo.
                current = current->next;  // Avanza al siguiente nodo.
                delete toDelete;  // Libera la memoria del nodo.
            }

            head = nullptr;  // Reinicia la cabeza de la lista.
            tail = nullptr;  // Reinicia la cola de la lista.
        }

        // Función que comprueba si la lista está vacía.
        bool isEmpty() const
        {
            return head == nullptr;  // Si la cabeza es nullptr, la lista está vacía.
        }
};
