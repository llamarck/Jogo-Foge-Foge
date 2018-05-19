/*
 * map.c
 *
 *  Created on: 15/05/2018
 *      Author: Léo
 */

#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void printMap(MAP * m){
	int i;
	for(i = 0; i < m->lines; i++){
		printf("%s\n", m->matriz[i]);
	}
}

void freeMap(MAP * m){
	int i;
	for(i = 0; i < m->lines; i++){
		free(m->matriz[i]); //libera cada um dos arrays alocados
	}
	free(m->matriz); //libera a matriz como um todo
}

void allocMap(MAP * m){
	m->matriz = malloc(sizeof(char*) * m->lines);

	int i;
	for(i = 0; i < m->lines; i++){
		m->matriz[i] = malloc(sizeof(char) * m->columns + 1);
	}
}

void readMap(MAP * m){
	FILE * f;
	f = fopen("map.txt", "r");
	if(f == 0){
		printf("Erro ao ler o mapa!");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->lines), &(m->columns));
	fflush(stdout);
	allocMap(m);

	int i;
	for(i = 0; i < m->lines; i++){
		fscanf(f, "%s", m->matriz[i]); //lendo do map.txt
		fflush(stdout);
	}

	fclose(f);
}

int isEmpty(MAP * m, int x, int y){
	return m->matriz[x][y] == '.';
}
