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

int validDirection(MAP * m, int x, int y){
	if(x >= m->lines)
		return 0;
	if(y >= m->columns)
		return 0;

	return 1;
}

int realDirection(char direction){
	return
			direction == 'a' ||
			direction == 'w' ||
			direction == 's' ||
			direction == 'd';
}

void walkingInMap(MAP * m, int xOrigin, int yOrigin, int xDestiny, int yDestiny){
	char character = m->matriz[xOrigin][yOrigin];
	m->matriz[xDestiny][yDestiny] = character;
	m->matriz[xOrigin][yOrigin] = '.';
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

	/*if((direction != 'a') && (direction != 'w') && (direction != 's') && (direction != 'd')){
		return;
	}*/

	if(!realDirection(direction))
		return;

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

	if(!validDirection(&m, nextX, nextY)){
		return;
	}
	if(!isEmpty(&m, nextX, nextY)){
		return;
	}
	if(m.matriz[nextX][nextY] != '.'){
		return;
	}

	walkingInMap(&m, hero.x, hero.y, nextX, nextY);
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
