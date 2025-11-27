# Pr-ctica-6-Cola-Circular-y-Cola-Doble-Deque-

Preguntas (A)
1. ¿Por qué en la cola circular no se desperdician posiciones como en la cola lineal?
   Porque reutiliza las posiciones vacías que quedaron al frente después de varios desencolados.
2. ¿Qué pasa cuando el índice final llega al final del arreglo?
   Se regresa a 0 y continúa desde el inicio del arreglo.
3. ¿Qué sucede si intentas encolar cuando la cola está llena?
   La operación se bloquea y el programa muestra el mensaje de cola llena.

Reflexión (B)

1. ¿Qué diferencia tiene el deque frente a la cola circular normal?
   La cola circular es menos flexible que el deque, por ejemplo la cola circular solo permite insertar por el final y eliminar por el frente, a diferencia del deque que deja insertar al frente, insertar al final, eliminar al frente y eliminar al final
  
2. ¿Qué operaciones permiten simular tanto FIFO como LIFO?
   FIFO permite:
   insert_rear()
   delete_front()

   LIFO permite:
   insert_rear()
   delete_rear()
   
4. Investiga que aplicaciones prácticas tiene deque.
   Implementación de estructuras de datos
   Rotación de elementos
   Gestión de tareas en sistemas operativos
   Problemas de optimización
