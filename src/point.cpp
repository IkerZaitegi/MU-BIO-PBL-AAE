#include "point.h"
#include <stdlib.h> // Para usar la funcion free

void freePoints(point_t** points) {
    if (points != NULL) {
        free(*points); // Liberar la memoria para el array de puntos
        *points = NULL; // Evitar el uso de punteros colgantes
    }
}
