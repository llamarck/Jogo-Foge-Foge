/*
 * main.c
 *
 *  Created on: 01/05/2018
 *      Author: Léo
 */

#include <stdio.h>
#include <stdlib.h>

char** map;
int lines;
int cols;

readMap(){
	FILE* f;
	char map[5][10+1];

	f = fopen("map.txt", "r");
	if(f == 0){
		printf("Erro ao ler o mapa");
	    exit(1);
	}

	int i;

	for(i = 0; i < 5; i++) {
		fscanf(f, "%s", map[i]);
	}

	for(i = 0; i < 5; i++) {
		printf("%s\n", map[i]);
	}

	fclose(f);
}

void alocMap(){
	map = malloc(sizeof(char*) * lines);

	int i;

	for (i = 0; i < lines; i++){
		map[i] = malloc(sizeof(char) * cols + 1);
	}
}

int main() {

}
