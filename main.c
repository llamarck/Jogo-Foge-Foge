/*
 * main.c
 *
 *  Created on: 01/05/2018
 *      Author: Léo
 */

#include <stdio.h>
#include <stdlib.h>
#include "foge-foge.h"
#include "map.h"

/*char** map;
int lines;
int columns;*/

MAP m;

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

int main() {

	readMap(&m);

	do {
		printMap(&m);
		char command;
		scanf(" %c", &command);
		fflush(stdout);
		move(command);

	}while(!end());

	freeMap(&m);

	return 0;
}
