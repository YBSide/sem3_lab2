#pragma once

#include "tic_tac_toe.h"
#include "InterfaceFunctions.h"
using namespace std;

void start_game() {
    tic_tac_toe game;
    cout << "Do you want to play a game?(yes or no)" << endl;
    auto answer = interface_function_1();
    while (answer == "1") {
        game.initialize_field();
        game.show_filed();
        auto character = game.user_symbol();
        string position;
        while (!game.game_over()) {
            if (character == "x") {
                cout << "Position:"<<endl;
                cin >> position;
                auto avl = game.player_turn(position);
                while (!avl) {
                    cin >> position;
                    avl = game.player_turn(position);
                }
            }
            else {
                game.computer_turn();
                game.show_filed();
            }
            if (game.game_over())
                break;
            if (character == "x") {
                game.computer_turn();
                game.show_filed();
            }
            else {
                cout << "Position:"<<endl;
                cin >> position;
                auto avl = game.player_turn(position);
                while (!avl) {
                    cin >> position;
                    avl = game.player_turn(position);
                }
            }
            if (game.game_over())
                break;
        }
        cout << "Game Over!" << endl;
        cout << "Final battlefield:" << endl;
        game.show_filed();
        cout << "Do you want to play again?" << endl;
        answer = interface_function_1();
    }

}