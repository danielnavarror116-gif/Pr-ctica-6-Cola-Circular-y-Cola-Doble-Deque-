#include <stdio.h>

#define MAX 5

/* Paso A1. Inicialización
   1. Define una estructura ColaCircular con:
      - datos[MAX]
      - índices frente y final
      - entero tamaño para llevar el conteo
*/
typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

/* Paso A2. Operaciones
   Implementa funciones:
   - isEmpty
   - isFull
   - enqueue(valor)
   - dequeue()
   - peek()
   - printQueue()
*/

int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("Cola circular llena. No se puede encolar.\n");
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;   // Avanzar índice
    c->size++;
}

int dequeue(ColaCircular *c, int *salida) {
    if (isEmpty(c)) {
        printf("Cola circular vacia. No se puede desencolar.\n");
        return 0;
    }
    *salida = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return 1;
}

int peek(ColaCircular *c, int *valor) {
    if (isEmpty(c)) {
        printf("Cola circular vacia. No hay elemento al frente.\n");
        return 0;
    }
    *valor = c->datos[c->frente];
    return 1;
}

void printQueue(ColaCircular *c) {
    int i, idx;
    printf("Cola: ");
    if (isEmpty(c)) {
        printf("vacia\n");
        return;
    }
    idx = c->frente;
    for (i = 0; i < c->size; i++) {
        printf("%d ", c->datos[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    ColaCircular cola;
    int valor;

    /* Paso A1. Inicializa la cola vacía */
    cola.frente = 0;
    cola.final = 0;
    cola.size = 0;

    printf("Cola circular inicializada\n");

    /* Paso A3. Pruebas */

    // 1. Encolar: 5, 10, 15
    printf("\nEncolando 5, 10, 15:\n");
    enqueue(&cola, 5);  printQueue(&cola);
    enqueue(&cola, 10); printQueue(&cola);
    enqueue(&cola, 15); printQueue(&cola);

    // 2. Desencolar uno
    printf("\nDesencolando un elemento:\n");
    if (dequeue(&cola, &valor))
        printf("Elemento desencolado: %d\n", valor);
    printQueue(&cola);

    // 3. Encolar: 20, 25, 30
    printf("\nEncolando 20, 25, 30:\n");
    enqueue(&cola, 20); printQueue(&cola);
    enqueue(&cola, 25); printQueue(&cola);
    enqueue(&cola, 30); printQueue(&cola);

    return 0;
}