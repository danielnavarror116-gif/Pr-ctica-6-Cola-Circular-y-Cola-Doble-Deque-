#include <stdio.h>

#define MAX 5

/* Paso B1. Inicialización
   1. Define estructura Deque con:
      - datos[MAX]
      - front, size
      - Nota: rear se calcula como (front + size - 1) % MAX
*/
typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

/* Paso B2. Operaciones
   Implementa funciones:
   - insert_front(valor)
   - insert_rear(valor)
   - delete_front()
   - delete_rear()
   - peek_front(), peek_rear()
   - printDeque()
*/

void insert_front(Deque *d, int valor) {
    if (d->size == MAX) {
        printf("Deque lleno. No se puede insertar al frente.\n");
        return;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;
}

void insert_rear(Deque *d, int valor) {
    if (d->size == MAX) {
        printf("Deque lleno. No se puede insertar al final.\n");
        return;
    }
    int rear = (d->front + d->size) % MAX;
    d->datos[rear] = valor;
    d->size++;
}

int delete_front(Deque *d, int *valor) {
    if (d->size == 0) {
        printf("Deque vacio. No se puede borrar del frente.\n");
        return 0;
    }
    *valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return 1;
}

int delete_rear(Deque *d, int *valor) {
    if (d->size == 0) {
        printf("Deque vacio. No se puede borrar del final.\n");
        return 0;
    }
    int rear = (d->front + d->size - 1) % MAX;
    *valor = d->datos[rear];
    d->size--;
    return 1;
}

int peek_front(Deque *d, int *valor) {
    if (d->size == 0) {
        printf("Deque vacio. No hay elemento al frente.\n");
        return 0;
    }
    *valor = d->datos[d->front];
    return 1;
}

int peek_rear(Deque *d, int *valor) {
    if (d->size == 0) {
        printf("Deque vacio. No hay elemento al final.\n");
        return 0;
    }
    int rear = (d->front + d->size - 1) % MAX;
    *valor = d->datos[rear];
    return 1;
}

void printDeque(Deque *d) {
    printf("Deque: ");
    if (d->size == 0) {
        printf("vacio\n");
        return;
    }

    int i, idx;
    idx = d->front;
    for (i = 0; i < d->size; i++) {
        printf("%d ", d->datos[idx]);
        idx = (idx + 1) % MAX;
    }

    int rear = (d->front + d->size - 1) % MAX;
    printf(" | front=%d rear=%d\n", d->front, rear);
}

int main() {
    Deque d;
    int valor;

    /* Paso B1. Inicializa con front = 0, size = 0 */
    d.front = 0;
    d.size = 0;
    printf("Deque inicializado\n");

    /* Paso B3. Pruebas */

    printf("\ninsert_front(10)\n");
    insert_front(&d, 10);
    printDeque(&d);

    printf("\ninsert_rear(15)\n");
    insert_rear(&d, 15);
    printDeque(&d);

    printf("\ninsert_rear(20)\n");
    insert_rear(&d, 20);
    printDeque(&d);

    printf("\ninsert_front(30)\n");
    insert_front(&d, 30);
    printDeque(&d);

    printf("\ninsert_rear(40)\n");
    insert_rear(&d, 40);
    printDeque(&d);

    printf("\ndelete_front()\n");
    if (delete_front(&d, &valor))
        printf("Eliminado del frente: %d\n", valor);
    printDeque(&d);

    printf("\ndelete_rear()\n");
    if (delete_rear(&d, &valor))
        printf("Eliminado del final: %d\n", valor);
    printDeque(&d);

    printf("\nNuevas inserciones:\n");
    insert_front(&d, 50);
    printDeque(&d);
    insert_rear(&d, 60);
    printDeque(&d);

    return 0;
}