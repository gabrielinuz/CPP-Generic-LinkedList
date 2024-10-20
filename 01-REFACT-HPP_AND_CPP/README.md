Explicación de la separación:
En LinkedList.hpp, solo declaramos las funciones y las estructuras, sin definirlas.
En LinkedList.cpp, realizamos la implementación de todas las funciones que fueron declaradas en el archivo .hpp.
Nota: En plantillas de C++, debido a cómo se manejan en la compilación, es necesario incluir el archivo .cpp al final del archivo .hpp, de lo contrario, el compilador no encontrará las implementaciones.
