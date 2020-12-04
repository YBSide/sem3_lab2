#include <iostream>
#include "Game'sInterface.h"
#include "IDictionary.h"
#include "InterfaceFunctions.h"
#include "ISet.h"
#include "ISortedSequence.h"
#include "ListSequence.h"
#include "AlphabeticalIndex.h"
int main() {
    auto pointer = alphabetical_pointer("milk farm herbal tea bubbleTea chicken cat baby ", 100);
    pointer.show_arr();
    auto arr = new list_sequence<int>;
    return 0;
}
