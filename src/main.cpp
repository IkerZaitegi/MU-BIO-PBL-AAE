#define _CRT_SECURE_NO_WARNINGS
#include <csv.h>
#include <stdio.h>
#include "point.h"
#include "pointreader.h"
#include "angularvelocitycalculator.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Programa para calcular la velocidad angular máxima a partir de un archivo txt de valores separados por comas producido por Tracker\n");
		printf("Uso: %s <Puntuak9.txt>\n", argv[0]);
		return -1;
	}
	struct point_t* points = nullptr;

 	int numberOfPoints = readPoints(argv[1], &points); //para saber número de puntos leidos

	if (numberOfPoints < 0) {
		printf("Error leyendo el archivo\n");
		return -1;//si el archivo no se lee bien
	}
	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

	printf("Velocidad angular maxima: %f\n", maximumAngularVelocity);

	free(points);
	return 0;
}
