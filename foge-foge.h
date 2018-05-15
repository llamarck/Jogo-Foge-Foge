/*
 * foge-foge.h
 *
 *  Created on: 12/05/2018
 *      Author: Léo
 */

#ifndef FOGE_FOGE_H_
#define FOGE_FOGE_H_

void allocMap();
void readMap();
void freeMap();
void printfMap();
int end();
void move(char direction);

typedef struct map MAPA;

struct map{
	char** matriz;
	int lines;
	int columns;
};

#endif /* FOGE_FOGE_H_ */
