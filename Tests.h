#pragma once

#include "AlphabeticalCat.h"
#include "Game'sInterface.h"

void tests() {
    string answer;
    cout << "Do you want to run tests? Yes(y) or No(n)" << endl;
    cin >> answer;
    while (answer != "y" && answer != "n") {
        cout << "Wrong answer, please enter y or n" << endl;
        cin >> answer;
    }
    if (answer == "n")
        return;
    string input = "aaa bbb bb cc c ";
    auto pointer = alphabetical_pointer(input, 6);
    int tpage_1 = pointer.get_page(0);
    int tpage_2 = pointer.get_page(1);
    int tpage_3 = pointer.get_page(4);

    string tword_1 = pointer.get_word(0);
    string tword_2 = pointer.get_word(1);
    string tword_3 = pointer.get_word(4);

    dict<string, string> tests;
    tests.add("abc", "hmm");
    string out_1;
    out_1 = tests.get("abc");
    tests.add("abccc", "hmmmm");
    string out_2;
    out_2 = tests.get("abccc");

    if (tpage_1 == 2)
        cout << "Test 1 passed!" << endl;
    else
        cout << "Test 1 failed" << endl;
    if (tpage_2 == 3)
        cout << "Test 2 passed!" << endl;
    else
        cout << "Test 2 failed" << endl;
    if (tpage_3 == 4)
        cout << "Test 3 passed!" << endl;
    else
        cout << "Test 3 failed" << endl;

    if (tword_1 == "aaa")
        cout << "Test 4 passed!" << endl;
    else
        cout << "Test 4 failed" << endl;
    if (tword_2 == "bb")
        cout << "Test 5 passed!" << endl;
    else
        cout << "Test 5 failed" << endl;
    if (tword_3 == "cc")
        cout << "Test 6 passed!" << endl;
    else
        cout << "Test 6 failed" << endl;

    if (out_1 == "hmm")
        cout << "Test 7 passed!" << endl;
    else
        cout << "Test 7 failed" << endl;
    if (out_2 == "hmmmm")
        cout << "Test 8 passed!" << endl;
    else
        cout << "Test 8 failed" << endl;

}