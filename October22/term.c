//
//  term.c
//  October22
//
//  Created by Daniel Walsh on 10/21/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#include <stdio.h>
#include <curses.h>

char term_key(void)
{
    int c;
    c = getchar();
    return c == ERR ? '\0' : c;
}

void term_wait(int milliseconds)
{
    if (napms(milliseconds) != OK) {
		fprintf(stderr, "napms didn't return OK\n");
	}
}