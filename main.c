/*
 * main.c
 *
 *  Created on: 01/05/2018
 *      Author: Léo
 */

#include <stdio.h>
#include <stdlib.h>
#include "foge-foge.h"

char** map;
int lines;
int columns;

int end(){
	return 0;
}

void move(char direction){
	int x, y, i, j;

	for(i = 0; i < lines; i++){
		for(j = 0; j < columns; j++){
			if(map[i][j] == '@'){
				x = i;
				y = j;
				break;
			}
		}
	}

	switch(direction) {
		case 'a':
			map[x][y-1] = '@';
			break;
		case 'w':
			map[x-1][y] = '@';
			break;
		case 's':
			map[x+1][y] = '@';
			break;
		case 'd':
			map[x][y+1] = '@';
			break;
	}

	map[x][y] = '.';
}

void printMap(){
	int i;
	for(i = 0; i < lines; i++){
		printf("%s\n", map[i]);
	}
}

void freeMap(){
	int i;
	for(i = 0; i < lines; i++){
		free(map[i]); //libera cada um dos arrays alocados
	}
	free(map); //libera a matriz como um todo
}

void allocMap(){
	map = malloc(sizeof(char*) * lines);

	int i;
	for(i = 0; i < lines; i++){
		map[i] = malloc(sizeof(char) * columns + 1);
	}
}

void readMap(){
	FILE * f;
	f = fopen("map.txt", "r");
	if(f == 0){
		printf("Erro ao ler o mapa!");
		exit(1);
	}

	fscanf(f, "%d %d", &lines, &columns);
	allocMap();

	int i;
	for(i = 0; i < lines; i++){
		fscanf(f, "%s", map[i]); //lendo do map.txt
	}

	fclose(f);
}

int main() {

	readMap();

	do {
		printMap();
		char command;
		scanf(" %c", &command);
		move(command);

	}while(!end());

	freeMap();

	return 0;
}
