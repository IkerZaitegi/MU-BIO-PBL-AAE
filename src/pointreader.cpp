#define _CRT_SECURE_NO_WARNINGS
#include "pointreader.h"
#include "csv.h"
#include <stdlib.h>
#include <string.h>

int num_points = 0;
int num_rows = 0;
int col = 0;
int error = 0;

const int MAX_POINTS = 1024;
const int MAX_ANCHO_POINTS = 30;

char* valores_leidos[MAX_POINTS][3][MAX_ANCHO_POINTS];

char cad_temp[MAX_ANCHO_POINTS] = {};

void cb_field(void* data, size_t len, void* nada) {
	strncpy(cad_temp, (char*)data, len);
	cad_temp[len] = '\0';


	strcpy(*valores_leidos[num_rows][col], cad_temp);

	col++;
};

void cb_row(int c, void* points) {
	num_rows++;

	col = 0;
}

int readPoints(const char* file, point_t** points) {
	//Lee los datos y guarda los valores como array

	FILE* fp;

	fp = fopen(file, "r");

	if (!fp) {
		error = 1;

		printf("No se encuentra el archivo o no se puede abrir.\n");
	}
	else { // Inicializamos el array de valores leídos
		

		for (int i = 0; i < MAX_POINTS; i++) {
			for (int j = 0; j < 3; j++) {
				*valores_leidos[i][j] = (char*)malloc(MAX_ANCHO_POINTS * sizeof(char));

				if (valores_leidos[i][j] == NULL) {
					// Error en la memoria
					exit(1);
				}
			}
		}

		//Parser del CSV

		struct csv_parser parser;

		char buffer[1024];
		size_t bytes_read;

		csv_init(&parser, NULL);
		csv_set_delim(&parser, CSV_TAB);

		while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
			if (csv_parse(&parser, buffer, bytes_read, cb_field, cb_row, &points) != bytes_read) {
				fclose(fp);

				error = 1;
			}
		}// Finalizamos el parser del CSV

		

		csv_fini(&parser, cb_field, cb_row, NULL);
		csv_free(&parser);

		if (!error) {

			error = read_csv_header();

			if (!error) {
				
				for (int i = 2; i < num_rows; i++) {
					// Metemos puntos en el array y sumamos uno al contador de puntos


					point_t* temp = (point_t*)realloc(*points, (num_points + 1) * sizeof(point_t));

					*points = temp;

					(*points)[num_points].t = atof(*valores_leidos[i][0]);
					(*points)[num_points].x = atof(*valores_leidos[i][1]);
					(*points)[num_points].y = atof(*valores_leidos[i][2]);

					num_points++;
				}
			}
		}
	}

	if (error) {
		return -1;
	}//Si hay error al abrir el archivo
	else {
		
		
		return num_points;
	}//Si todo ha ido bien devolvemos el número de puntos leídos.
		//En la variable points tenemos los puntos leídos, que se pasan por referencia.
}

int read_csv_header() {
	
	//Comprobamos que la primera fila del archivo sea correcta (t, x, y)
	//La primera fila indica que tipo de valor es cada columna

	if (num_rows <= 2 && strcmp(*valores_leidos[1][0], "t") != 0 && strcmp(*valores_leidos[1][1], "x") != 0 && strcmp(*valores_leidos[1][2], "y") != 0) {
		return 1;
	}
	//Si se cumple la condicion significa que se detecta un error
	else {
		return 0;

	}//Si no se cumple, devuelve 0 y no hay error
	

}
