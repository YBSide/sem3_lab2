#pragma once

#include "Sequence.h"
#include <iostream>
#include "IDictionary.h"
#include <cstring>
#include <utility>

using namespace std;

class tic_tac_toe {

private:
    dict<string, string> field;
    string player_character;
    string computer_character;

public:
    string user_symbol() {
        cout << "Choose your character(0 or x): ";
        string answer;
        cin >> answer;
        while (answer != "0" && answer != "x") {
            cout << "You only have two options... Please select 0 or x" << endl;
            cin >> answer;
        }
        cout << "Nice choice!" << endl;
        player_character = answer;
        if (player_character == "0")
            computer_character = "x";
        else
            computer_character = "0";
        return player_character;
    }

    void initialize_field() {
        field.add("a1", " ");
        field.add("b1", " ");
        field.add("c1", " ");
        field.add("a2", " ");
        field.add("b2", " ");
        field.add("c2", " ");
        field.add("a3", " ");
        field.add("b3", " ");
        field.add("c3", " ");
    }

    void show_filed() {
        cout << "    1 | " << "2 | " << "3" << endl;
        for (char i : "abc") {
            string j = string(1, i);
            if (int(i) == 0)
                break;
            cout << j << " | " << field.get(j+"1") << " | " << field.get(j+"2") << " | " << field.get(j+"3") << endl;

        }

    }

    bool it_is_draw() {
        for (char i : "abc") {
            string j = string(1, i);
            if (int(i) == 0)
                break;

            for(char k : "123") {
                if (int(k) == 0)
                    break;
                if (field.get(j+k) == " ")
                    return false;
            }
        }
        return true;
    }

    bool it_is_win(string symbol) {

        for (char i : "abc") {
            string j = string(1, i);
            if (int(i) == 0)
                break;
            if (field.get(j+"1") == field.get(j+"2") && field.get(j+"3") == symbol && field.get(j+"1") == symbol)
                return true;
        }

        for (char i : "123") {
            string j = string(1, i);
            if (int(i) == 0)
                break;
            if (field.get("a"+j) == field.get("b"+j) && field.get("c"+j) == symbol && field.get("a"+j) == symbol)
                return true;
        }

        return (field.get("a1") == field.get("b2") && field.get("c3") == symbol && field.get("a1") == symbol) ||
               (field.get("c1") == field.get("b2") && field.get("a3") == symbol && field.get("c1") == symbol);
    }

    int minimax(bool it_is_ai_turn) {
        if (it_is_win(computer_character))
            return -10;
        if (it_is_win(player_character))
            return 10;
        if (it_is_draw())
            return 0;

        int best_score_for_ai = 10; // initial conditions, of course it is lower (-10)
        int best_score_for_person = -10;
        int score;

        for (char i : "abc") {

            if (int(i) == 0)
                break;

            for (char j : "123") {

                if (int(j) == 0)
                    break;
                string k = string(1, j);

                if (field.get(i+k) == " ") {

                    if (it_is_ai_turn)
                        field.add(i+k, computer_character);
                    else
                        field.add(i+k, player_character);

                    score = minimax(!it_is_ai_turn);
                    field.add(i+k, " ");

                    if (it_is_ai_turn && score <= best_score_for_ai)
                        best_score_for_ai = score;
                    if (!it_is_ai_turn && score >= best_score_for_person)
                        best_score_for_ai = score;
                    if ((it_is_ai_turn && score == -10) || (!it_is_ai_turn && score == 10))
                        return score;

                }
            }
        }
        if (it_is_ai_turn)
            return best_score_for_ai;
        else
            return best_score_for_person;
    }

    void computer_turn() {
        int best_score = 10;
        int score;
        string position;
        for (char i : "abc") {

            if (int(i) == 0)
                break;

            for (char j : "123") {

                if (int(j) == 0)
                    break;
                string k = string(1, j);

                if (field.get(i+k) == " ") {
                    field.add(i+k, computer_character);
                    score = minimax(false);
                    field.add(i+k, " ");
                    if (score < best_score) {
                        best_score = score;
                        position = i+k;
                    }
                }

                if (best_score == -10) {
                    field.add(position, computer_character);
                    return;
                }
            }
        }
        field.add(position, computer_character);
    }

    bool player_turn(string position) {
        while (field.get(position) != " ") {
            cout << "Position already taken, choose another one" << endl;
            return false;
        }
        field.add(move(position), player_character);
        return true;
    }

    bool game_over() {
        return  (it_is_draw() || it_is_win("x") || it_is_win("0"));
    }

};
