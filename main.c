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
POSITION hero;

void findHero(MAP * m, POSITION * p, char c){
	int i, j;
	for(i = 0; i < m->lines; i++){
		for(j = 0; j < m->columns; j++){
			if(m->matriz[i][j] == c){
				p->x = i;
				p->y = j;
				return;
			}
		}
	}
}

int end(){
	return 0;
}

void move(char direction){
	/*int x, y, i, j;

	for(i = 0; i < m.lines; i++){
		for(j = 0; j < m.columns; j++){
			if(m.matriz[i][j] == '@'){
				x = i;
				y = j;
				break;
			}
		}
	}*/

	m.matriz[hero.x][hero.y] = '.';

	switch(direction) {
		case 'a':
			m.matriz[hero.x][hero.y-1] = '@';
			hero.y--;
			break;
		case 'w':
			m.matriz[hero.x-1][hero.y] = '@';
			hero.x--;
			break;
		case 's':
			m.matriz[hero.x+1][hero.y] = '@';
			hero.x++;
			break;
		case 'd':
			m.matriz[hero.x][hero.y+1] = '@';
			hero.y++;
			break;
	}
}

int main() {

	readMap(&m);
	findHero(&m, &hero, '@');

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
