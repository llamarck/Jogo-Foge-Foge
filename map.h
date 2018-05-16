/*
 * mapa.h
 *
 *  Created on: 15/05/2018
 *      Author: L�o
 */

#ifndef MAP_H_
#define MAP_H_

#include <stdio.h>
#include <stdlib.h>

struct map{
	char** matriz;
	int lines;
	int columns;
};

typedef struct map MAP;

void allocMap(MAP * m);
void readMap(MAP * m);
void freeMap(MAP * m);
void printfMap(MAP * m);

#endif /* MAP_H_ */