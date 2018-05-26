/*
 * mapa.h
 *
 *  Created on: 15/05/2018
 *      Author: Léo
 */

#ifndef MAP_H_
#define MAP_H_

#include <stdio.h>
#include <stdlib.h>

#define GHOST 'G'
#define HERO '@'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

struct map{
	char** matriz;
	int lines;
	int columns;
};

typedef struct map MAP;

struct position{
	int x;
	int y;
};

typedef struct position POSITION;

void allocMap(MAP * m);
void readMap(MAP * m);
void freeMap(MAP * m);
void printMap(MAP * m);
void ghost();
void cloneMap();
int canWalk();

#endif /* MAP_H_ */
