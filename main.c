/*
 * main.c
 *
 *  Created on: 01/05/2018
 *      Author: Léo
 */

#include <stdio.h>
#include <stdlib.h>
#include "foge-foge.h"

/*char** map;
int lines;
int columns;*/

MAPA m;

int end(){
	return 0;
}

void move(char direction){
	int x, y, i, j;

	for(i = 0; i < m.lines; i++){
		for(j = 0; j < m.columns; j++){
			if(m.matriz[i][j] == '@'){
				x = i;
				y = j;
				break;
			}
		}
	}

	switch(direction) {
		case 'a':
			m.matriz[x][y-1] = '@';
			break;
		case 'w':
			m.matriz[x-1][y] = '@';
			break;
		case 's':
			m.matriz[x+1][y] = '@';
			break;
		case 'd':
			m.matriz[x][y+1] = '@';
			break;
	}

	m.matriz[x][y] = '.';
}

void printMap(){
	int i;
	for(i = 0; i < m.lines; i++){
		printf("%s\n", m.matriz[i]);
	}
}

void freeMap(){
	int i;
	for(i = 0; i < m.lines; i++){
		free(m.matriz[i]); //libera cada um dos arrays alocados
	}
	free(m.matriz); //libera a matriz como um todo
}

void allocMap(){
	m.matriz = malloc(sizeof(char*) * m.lines);

	int i;
	for(i = 0; i < m.lines; i++){
		m.matriz[i] = malloc(sizeof(char) * m.columns + 1);
	}
}

void readMap(){
	FILE * f;
	f = fopen("map.txt", "r");
	if(f == 0){
		printf("Erro ao ler o mapa!");
		exit(1);
	}

	fscanf(f, "%d %d", &(m.lines), &(m.columns));
	fflush(stdout);
	allocMap();

	int i;
	for(i = 0; i < m.lines; i++){
		fscanf(f, "%s", m.matriz[i]); //lendo do map.txt
		fflush(stdout);
	}

	fclose(f);
}

int main() {

	readMap();

	do {
		printMap();
		char command;
		scanf(" %c", &command);
		fflush(stdout);
		move(command);

	}while(!end());

	freeMap();

	return 0;
}
