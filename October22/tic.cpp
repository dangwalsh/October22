//
//  tic.cpp
//  October22
//
//  Created by Daniel Walsh on 10/21/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#include "tic.h"
using namespace std;

int checkVal(int n);
void move(int x, int y);
void randomChoice();
void getWinner();

bool isUserTurn = true;
int turn = 0;
int winner = 0;

const char player[3] = {'O',' ','X'};

int a[][3] {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};

const size_t nrows = sizeof a / sizeof a[0];
const size_t ncols = sizeof a[0] / sizeof a[0][0];

int checkVal(int n) {
    
    switch (n) {
        case -3:
            return -1;
        case 3:
            return 1;
        default:
            return 0;
    }
    
}

void getWinner()
{
    
/* alternative method for checking array without pointers
 
     int diag1 = a[0][0] + a[1][1] + a[2][2];
     int diag2 = a[0][2] + a[1][1] + a[2][0];
     
     for (int i = 0; i < ncols; ++i) {
     
        int horiz = a[i][0] + a[i][1] + a[i][2];
        int vert = a[0][i] + a[1][i] + a[2][i];
     
        if (horiz == 3 || vert == 3) {
            winner = 1; break;
        } else if (horiz == -3 || vert == -3) {
            winner = -1; break;
        }
     }
*/
    
    for (int i = 0; i < ncols; ++i){
        
        if (i == 0) {
            
            int dd = 0;
            for (int *p = reinterpret_cast<int *>(a) + i; p < reinterpret_cast<int *>(a) + ncols * nrows; p+=4) {
                dd += *p;
            }
            winner = checkVal(dd);
            if (winner != 0) break;
            
            int du = 0;
            for (int *p = reinterpret_cast<int *>(a) + i + 2; p < reinterpret_cast<int *>(a) + ncols * nrows - 2; p+=2) {
                du += *p;
            }
            winner = checkVal(du);
            if (winner != 0) break;
        }
        
        int h = 0;
        for (int *q = reinterpret_cast<int *>(a) + i * 3; q < reinterpret_cast<int *>(a) + (nrows * i + ncols); ++q) {
            h += *q;
        }
        winner = checkVal(h);
        if (winner != 0) break;
        
        int v = 0;
        for (int *r = reinterpret_cast<int *>(a) + i; r < reinterpret_cast<int *>(a) + (ncols + 4 + i); r+=3) {
            v += *r;
        }
        winner = checkVal(v);
        if (winner != 0) break;
    }

    if (turn > 8 && winner == 0) winner = 2;
}

void draw()
{
    cout << endl;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j <  ncols; ++j) {
            cout << player[a[i][j] + 1]; if (j < ncols-1) cout << "|";
        }
        cout << endl; if (i < nrows-1) cout << "-+-+-" << endl;
    }
    cout << endl;
}

void move(int x, int y)
{
    if (isUserTurn) {
        a[x][y] = 1;
    } else {
        a[x][y] = -1;
    }
    ++turn;
    
    draw();
    getWinner();

    isUserTurn = !isUserTurn;
    
    if (!isUserTurn && winner == 0) {
        cout << "Now it's my turn, let me see..." << endl;
        term_wait(3000);
        cout << endl << "Ok, here we go!" << endl;
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
    } else if (isUserTurn){
        cout << endl << "Pick another spot, that one is already taken." << endl;
        draw();
    } else {
        randomChoice();
    }
}

