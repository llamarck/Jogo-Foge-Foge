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

void cloneMap(MAP * destiny, MAP * origin){
	destiny->lines = origin->lines;
	destiny->columns = origin->columns;
	allocMap(destiny);
	int i;
	for(i = 0; i < origin->lines; i++){
		strcpy(destiny->matriz[i], origin->matriz[i]);
	}
}

void ghosts(){
	MAP clone;

	cloneMap(&clone, &m);

	int i, j;
	for(i = 0; i < m.lines; i++){
		for(j = 0; j < m.columns; j++){
			if(m.matriz[i][j] == GHOST){
				if(validDirection(&m, i, j+1)){
					walkingInMap(&m, i, j, i, j+1);
				}
			}
		}
	}
	freeMap(&clone);
}

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
			direction == LEFT ||
			direction == UP ||
			direction == DOWN ||
			direction == RIGHT;
}

void walkingInMap(MAP * m, int xOrigin, int yOrigin, int xDestiny, int yDestiny){
	char character = m->matriz[xOrigin][yOrigin];
	m->matriz[xDestiny][yDestiny] = character;
	m->matriz[xOrigin][yOrigin] = EMPTY;
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

	//m.matriz[hero.x][hero.y] = EMPTY;

	switch(direction) {
		case LEFT:
			//m.matriz[hero.x][hero.y-1] = HERO;
			nextY--;
			break;
		case UP:
			//m.matriz[hero.x-1][hero.y] = HERO;
			nextX--;
			break;
		case DOWN:
			//m.matriz[hero.x+1][hero.y] = HERO;
			nextX++;
			break;
		case RIGHT:
			//m.matriz[hero.x][hero.y+1] = HERO;
			nextY++;
			break;
	}

	if(!validDirection(&m, nextX, nextY)){
		return;
	}
	if(!isEmpty(&m, nextX, nextY)){
		return;
	}
	/*if(m.matriz[nextX][nextY] != EMPTY){
		return;
	}*/

	walkingInMap(&m, hero.x, hero.y, nextX, nextY);
	/*m.matriz[nextX][nextY] = HERO;
	m.matriz[hero.x][hero.y] = EMPTY;*/
	hero.x = nextX;
	hero.y = nextY;
}

int main() {

	readMap(&m);
	findHero(&m, &hero, HERO);

	do {
		printMap(&m);
		char command;
		scanf(" %c", &command);
		fflush(stdout);
		move(command);
		ghosts();

	}while(!end());

	freeMap(&m);

	return 0;
}
