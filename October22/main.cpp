//
//  main.cpp
//  October22
//
//  Created by Daniel Walsh on 10/21/12.
//  Copyright (c) 2012 Daniel Walsh. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "tic.h"
extern "C" {
#include "term.h"
}
using namespace std;

int main()
{
/*
    int a[][3] {
        {0,1,2},
        {3,0,0},
        {4,0,0}
    };
    
    const int *p = reinterpret_cast<int *>(a);
    
    cout << "cols: " << getCols() << endl;
    cout << "rows: " << getRows() << endl;
    
    getWinner(reinterpret_cast<int *>(a));
*/
    char c;
    //int win = 0;
    
    cout << "Welcome to another round Tic-Tac-Toe" << endl;
    cout << "\tYou will be the X and I will be the O." << endl;
    cout << "\tWhen you're ready to begin, press a key and off we go..." << endl;
    
    while ((c = term_key()) == '\0') {
    }
    
    draw();
    
    while (win == 0) {
        
        cout << "Choose a ROW number (0-2)..." << endl;
        int x;
        cin >> x;
        
        cout << "...and a COLUMN number (0-2):" << endl;
        int y;
        cin >> y;
        
        checkSpace(x, y);
    }
    
    draw();
    
    if (win == 2){
        cout << "Sorry, there is no winner today.";
    } else {
        cout << "The " << name[win+1] << "'s win!" << endl;
    }
    
    return EXIT_SUCCESS;
}

