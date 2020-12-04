#pragma once
#include <iostream>
using namespace std;
string interface_function_1() {
    string a;
    while (a != "YES" || a != "NO" || a != "n" || a != "y" || a != "N" || a != "Y") {
        cin >> a;

        if (a == "YES" || a == "Y" || a == "y")
            return "1";

        if (a == "NO" || a == "N" || a == "n")
            return "0";

        cout << "Incorrect answer! Please, use YES(y) or NO(n)" << endl;

    }
    return "00";
}