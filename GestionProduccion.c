#include <stdio.h>
#include <string.h>

#define MAX 10
#define L 40

void leerCadena(char s[], int tam);
int buscar(char nombres[][L], int n, char nom[]);
void mostrar(char nombres[][L], int c[], float t[], float r[], int n);

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
        printf("5. Calcular totales\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opc);
        getchar(); // limpiar ENTER

        if (opc == 1) {
            printf("Nombre: ");
            leerCadena(nombres[n], L);

            printf("Cantidad: ");
            scanf("%d", &cantidades[n]);

            printf("Tiempo por unidad: ");
            scanf("%f", &tiempoU[n]);

            printf("Recursos por unidad: ");
            scanf("%f", &recursosU[n]);

            getchar(); // limpiar ENTER
            n++;
        }

        else if (opc == 2) {
            printf("Nombre a editar: ");
            leerCadena(nombreBus, L);

            int pos = buscar(nombres, n, nombreBus);
            if (pos == -1) printf("No existe.\n");
            else {
                printf("Nuevo nombre: ");
                leerCadena(nombres[pos], L);
                printf("Nueva cantidad: ");
                scanf("%d", &cantidades[pos]);
                printf("Nuevo tiempo/u: ");
                scanf("%f", &tiempoU[pos]);
                printf("Nuevos recursos/u: ");
                scanf("%f", &recursosU[pos]);
                getchar();
            }
        }

        else if (opc == 3) {
            printf("Nombre a eliminar: ");
            leerCadena(nombreBus, L);
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
            mostrar(nombres, cantidades, tiempoU, recursosU, n);
        }

        else if (opc == 5) {
            float tTotal = 0, rTotal = 0;
            for (int i = 0; i < n; i++) {
                tTotal += cantidades[i] * tiempoU[i];
                rTotal += cantidades[i] * recursosU[i];
            }
            printf("\nTiempo total: %.2f\n", tTotal);
            printf("Recursos totales: %.2f\n", rTotal);
        }

    } while (opc != 6);

    return 0;
}

void leerCadena(char s[], int tam) {
    fgets(s, tam, stdin);
    s[strcspn(s, "\n")] = 0;
}

int buscar(char nombres[][L], int n, char nom[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(nombres[i], nom) == 0)
            return i;
    return -1;
}

void mostrar(char nombres[][L], int c[], float t[], float r[], int n) {
    printf("\nProductos:\n");
    for (int i = 0; i < n; i++) {
        printf("%s | Cant: %d | T/u: %.2f | R/u: %.2f\n",
               nombres[i], c[i], t[i], r[i]);
    }
}
