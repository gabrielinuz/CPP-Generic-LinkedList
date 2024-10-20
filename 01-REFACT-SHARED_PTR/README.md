Explicación de los cambios:
std::shared_ptr<Node>: Cambié los punteros crudos por std::shared_ptr, que gestiona automáticamente la memoria de los nodos. Cada nodo se eliminará automáticamente cuando ya no se esté utilizando.

std::make_shared<Node>: Se utiliza para crear nodos de manera eficiente, evitando asignaciones de memoria innecesarias.

Destructor: Ya no es necesario un destructor explícito para liberar memoria, ya que los shared_ptr se encargan de liberar la memoria cuando ya no son necesarios.

Esto reduce el riesgo de fugas de memoria y hace que el código sea más seguro y manejable.
