#include <iostream>
#include "Game'sInterface.h"
#include "InterfaceFunctions.h"
#include "ListSequence.h"
#include "AlphabeticalCat.h"
#include "Tests.h"
int main() {
    tests();
    string end = "0";
    while (end == "0") {
        string answer;
        cout << "Which program do you want to run? Tic Tac Toe (1) or Alphabetical Catalog (2)" << endl;
        cin >> answer;
        while (answer != "1" && answer != "2") {
            cout << "Wrong answer, please enter 1 or 2" << endl;
            cin >> answer;
        }
        if (answer == "1")
            start_game();
        if (answer == "2")
            start_alph_prog();
        cout << "Do you want to exit? Yes(y) or No(n)" << endl;
        end = interface_function_1();
    }

    return 0;
}
