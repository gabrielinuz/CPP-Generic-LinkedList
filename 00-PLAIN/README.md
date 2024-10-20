Explicación del código
Templates: template <typename T> permite que la clase LinkedList acepte cualquier tipo de objeto, T representa el tipo genérico.

Estructura interna Node: Cada nodo de la lista contiene un dato data del tipo T y un puntero next al siguiente nodo.

Método add: Añade un nuevo elemento al final de la lista. Si la lista está vacía, inicializa head y tail al nuevo nodo.

Método remove: Busca y elimina un nodo que contiene el valor especificado. Si lo encuentra, ajusta los punteros correspondientes.

Método forEach: Recorre cada elemento de la lista y ejecuta una acción (función) sobre ese elemento. Utiliza std::function<void(const T&)> para aceptar cualquier función o lambda que reciba un argumento del tipo T.

Destructor: Libera la memoria de cada nodo para evitar fugas de memoria cuando la lista se destruye.


Explicación del uso
Agregar elementos: Se agregan elementos enteros a la lista.
forEach: Recorre la lista e imprime cada valor usando una función externa llamada printInt.
Eliminar un elemento: Se elimina el número 2 de la lista y luego se imprime la lista nuevamente para verificar.


Este enfoque te permite crear listas enlazadas de cualquier tipo y realizar operaciones de manera flexible, usando templates y lambdas o funciones estándar para realizar operaciones en cada elemento.
