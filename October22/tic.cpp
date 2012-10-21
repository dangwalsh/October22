//
//  tic.cpp
//  October22
//
//  Created by Daniel Walsh on 10/21/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#include "tic.h"
using namespace std;

char name[3] = {'O',' ','X'};


void randomChoice();
void move(int x, int y);

bool userTurn = true;
int turn = 0;
int win = 0;

int a[][3] {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};

const size_t nrows = sizeof a / sizeof a[0];
const size_t ncols = sizeof a[0] / sizeof a[0][0];

void getWinner()
{
    if (turn > 8) {
        win = 2;
    }

    int diag1 = a[0][0] + a[1][1] + a[2][2];
    int diag2 = a[0][2] + a[1][1] + a[2][0];
    
    if (diag1 == 3 || diag2 == 3) {
        win = 1;
    } else if (diag1 == -3 || diag2 == -3) {
        win = -1;
    } else {
        for (int i=0; i<3; ++i) {
            
            int horiz = a[i][0] + a[i][1] + a[i][2];
            int vert = a[0][i] + a[1][i] + a[2][i];
            
            if (horiz == 3 || vert == 3) {
                win = 1; break;
            } else if (horiz == -3 || vert == -3) {
                win = -1; break;
            }
        }
    }
}

void draw()
{
    cout << endl;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j <  ncols; ++j) {
            cout << name[a[i][j] + 1]; if (j < ncols-1) cout << "|";
        }
        cout << endl; if (i < nrows-1) cout << "-+-+-" << endl;
    }
    cout << endl;
}

void move(int x, int y)
{
    if (userTurn) {
        a[x][y] = 1;
    } else {
        a[x][y] = -1;
    }
    ++turn;
    
    draw();
    getWinner();
    
    userTurn = !userTurn;
    
    if (!userTurn && win == 0) {
        cout << "Now it's my turn, let me see..." << endl;
        term_wait(3000);
        cout << "Ok, here we go!" << endl;
        randomChoice();
    }
}

void randomChoice()
{
    srand(static_cast<unsigned>(time(0)));
    
    int x = random() % nrows;
    int y = random() % ncols;
    
    checkSpace(x, y);
}

void checkSpace(int x, int y)
{
    if (a[x][y] == 0) {
       move(x, y); 
    } else if (userTurn){
        cout << "Pick another spot, that one is already taken." << endl;
    } else {
        randomChoice();
    }
}

