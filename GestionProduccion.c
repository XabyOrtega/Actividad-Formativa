#include <stdio.h>

#define MAX 5

int main() {
    char nombres[MAX][20];
    int cantidades[MAX];
    float tiempoU[MAX], recursosU[MAX];
    int n, i;

    float tiempoDisp, recursosDisp;
    float tTotal = 0, rTotal = 0;

    printf("Cuantos productos desea ingresar (max 5): ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);

        printf("Nombre: ");
        scanf("%s", nombres[i]);
        printf("Cantidad: ");
        scanf("%d", &cantidades[i]);
        printf("Tiempo por unidad: ");
        scanf("%f", &tiempoU[i]);
        printf("Recursos por unidad: ");
        scanf("%f", &recursosU[i]);
    }

    for (i = 0; i < n; i++) {
        tTotal += cantidades[i] * tiempoU[i];
        rTotal += cantidades[i] * recursosU[i];
    }

    printf("\nTiempo disponible: ");
    scanf("%f", &tiempoDisp);
    printf("Recursos disponibles: ");
    scanf("%f", &recursosDisp);

    printf("\nTiempo total requerido: %.2f\n", tTotal);
    printf("Recursos totales requeridos: %.2f\n", rTotal);

    if (tTotal <= tiempoDisp && rTotal <= recursosDisp)
        printf("Puede cumplir con la demanda.\n");
    else
        printf("NO puede cumplir la demanda.\n");

    return 0;
}
