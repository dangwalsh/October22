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
    cout << "Welcome to another round Tic-Tac-Toe." << endl;
    cout << "\tYou will be the X and I will be the O." << endl;
    cout << "\tPress any key when you're ready to go. " << endl;
    
    char c;
    while ((c = term_key()) == '\0') {
    }
    
    draw();
    
    while (win == 0) {
        
        cout << "Choose a ROW number (0-2)..." << endl;
        int x;
        cin >> x;
        if (!cin) {
            cerr << "Sorry, that wasn't a number. Try again." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            draw();
            continue;
        } else if (x < 0 || x > 2) {
            cerr << "Sorry, that space isn't on the board. Try again." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            draw();
            continue;
        }
        
        cout << "...and a COLUMN number (0-2)..." << endl;
        int y;
        cin >> y;
        if (!cin) {
            cerr << "Sorry, that wasn't a number. Try again." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            draw();
            continue;
        } else if (y < 0 || y > 2) {
            cerr << "Sorry, that space isn't on the board. Try again." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            draw();
            continue;
        }
        
        checkSpace(x, y);
    }
    
    if (win == 2){
        cout << "Sorry, there is no winner today.";
    } else {
        cout << "The " << player[win+1] << "'s win!" << endl;
    }
    
    return EXIT_SUCCESS;
}

