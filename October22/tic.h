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

extern const char player[];
extern int turn;
extern int winner;

extern void checkSpace(int x, int y);
extern void draw();

#endif /* defined(__October22__tic__) */
