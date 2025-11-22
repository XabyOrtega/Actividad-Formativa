#include <stdio.h>
#include <string.h>

#define MAX 10
#define L 30

void mostrarProductos(char nombres[][L], int cantidades[], float t[], float r[], int n);
int buscar(char nombres[][L], int n, char nom[]);

int main() {
    char nombres[MAX][L];
    int cantidades[MAX];
    float tiempoU[MAX], recursosU[MAX];
    int n = 0, opc;

    char nombreBus[L];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opc);

        if (opc == 1) {
            printf("Nombre: ");
            scanf("%s", nombres[n]);
            printf("Cantidad: ");
            scanf("%d", &cantidades[n]);
            printf("Tiempo por unidad: ");
            scanf("%f", &tiempoU[n]);
            printf("Recursos por unidad: ");
            scanf("%f", &recursosU[n]);
            n++;
        }

        else if (opc == 2) {
            printf("Nombre del producto a editar: ");
            scanf("%s", nombreBus);
            int pos = buscar(nombres, n, nombreBus);
            if (pos == -1) printf("No existe.\n");
            else {
                printf("Nuevo nombre: ");
                scanf("%s", nombres[pos]);
                printf("Nueva cantidad: ");
                scanf("%d", &cantidades[pos]);
                printf("Nuevo tiempo/u: ");
                scanf("%f", &tiempoU[pos]);
                printf("Nuevos recursos/u: ");
                scanf("%f", &recursosU[pos]);
            }
        }

        else if (opc == 3) {
            printf("Nombre del producto a eliminar: ");
            scanf("%s", nombreBus);
            int pos = buscar(nombres, n, nombreBus);
            if (pos == -1) printf("No existe.\n");
            else {
                for (int i = pos; i < n - 1; i++) {
                    strcpy(nombres[i], nombres[i + 1]);
                    cantidades[i] = cantidades[i + 1];
                    tiempoU[i] = tiempoU[i + 1];
                    recursosU[i] = recursosU[i + 1];
                }
                n--;
                printf("Eliminado.\n");
            }
        }

        else if (opc == 4) {
            mostrarProductos(nombres, cantidades, tiempoU, recursosU, n);
        }

    } while (opc != 5);

    return 0;
}

void mostrarProductos(char nombres[][L], int cantidades[], float t[], float r[], int n) {
    printf("\nProductos registrados:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Cant: %d - T/u: %.2f - R/u: %.2f\n",
               nombres[i], cantidades[i], t[i], r[i]);
    }
}

int buscar(char nombres[][L], int n, char nom[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(nombres[i], nom) == 0)
            return i;
    return -1;
}
