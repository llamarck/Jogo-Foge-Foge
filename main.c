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

	if((direction != 'a') && (direction != 'w') && (direction != 's') && (direction != 'd')){
		return;
	}

	int nextX = hero.x;
	int nextY = hero.y;

	m.matriz[hero.x][hero.y] = '.';

	switch(direction) {
		case 'a':
			m.matriz[hero.x][hero.y-1] = '@';
			nextY--;
			break;
		case 'w':
			m.matriz[hero.x-1][hero.y] = '@';
			nextX--;
			break;
		case 's':
			m.matriz[hero.x+1][hero.y] = '@';
			nextX++;
			break;
		case 'd':
			m.matriz[hero.x][hero.y+1] = '@';
			nextY++;
			break;
	}

	if(nextX >= m.lines){
		return;
	}
	if(nextY >= m.columns){
		return;
	}
	if(m.matriz[nextX][nextY] != '.'){
		return;
	}

	m.matriz[nextX][nextY] = '@';
	m.matriz[hero.x][hero.y] = '.';
	hero.x = nextX;
	hero.y = nextY;
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
