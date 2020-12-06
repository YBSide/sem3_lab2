#pragma once

#include "AlphabeticalIndex.h"
#include "InterfaceFunctions.h"
#include <string>
using namespace std;
void start_alph_prog() {
    string answer = "1";
    while (answer == "1") {
        string input;
        int size_of_page;
        cout << "Enter your string:" << endl;
        cin.ignore();
        getline(cin, input);
        cout << "Enter size of page:" << endl;
        cin >> size_of_page;
        auto pointer = alphabetical_pointer(input, size_of_page);
        pointer.show_arr();
        cout << "Do you want to run this program again? Yes(y) or No(n)" << endl;
        answer = interface_function_1();
    }
}
