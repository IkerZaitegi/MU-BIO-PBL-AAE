#define _CRT_SECURE_NO_WARNINGS
#include "angularvelocitycalculator.h"
#include <math.h>

float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) {

    float maxAngularVelocity = 0.0f;
	//Inicializamos la variable maxAngularVelocity = 0.0f, para que no tenga un valor basura y sea tipo float

    for (int i = 1; i < numberOfPoints; i++) {
        //Usamos esta formulas para calcular los deltas
        float deltaX = points[i].x - points[i - 1].x;
        float deltaY = points[i].y - points[i - 1].y;
        float deltaT = points[i].t - points[i - 1].t;

        // Evitar división por cero en deltaT
        if (deltaT <= 0.0f) {
            continue; 
            // no se ejecutarán las instrucciones que vienen después de esta línea del bucle.
        }

        // Calcular el cambio de ángulo (Delta Theta)
        float deltaTheta = atan2(deltaY, deltaX);

        // Calcular la velocidad angular
        float angularVelocity = fabs(deltaTheta / deltaT);

        // Actualizar la velocidad angular máxima
        if (angularVelocity > maxAngularVelocity) {
            maxAngularVelocity = angularVelocity;
        }
    }

    return maxAngularVelocity;
}
