//
//  tic.h
//  October22
//
//  Created by Daniel Walsh on 10/21/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#ifndef __October22__tic__
#define __October22__tic__

#include <iostream>
#include <cstdlib>
extern "C" {
#include "term.h"
}

extern char name[];
extern bool userTurn;
extern int turn;
extern int win;

extern void randomChoice();
extern void checkSpace(int x, int y);
extern void draw();
extern void getWinner();

#endif /* defined(__October22__tic__) */
