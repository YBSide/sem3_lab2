#pragma once

#include "ListSequence.h"
#include <string>
#include <iostream>
#include "ShellSort.h"
using namespace std;

class alphabetical_pointer {
    struct word_el {
        string word;
        int page;
    };
private:
    list_sequence<word_el>* data;

public:
    alphabetical_pointer(string sentence, int size_of_page) {
        data = new list_sequence<word_el>();
        word_el word_el;
        string current_word;
        string max_word = " ";
        if (size_of_page <= 0)
            throw out_of_range("Size of page <= 0");
        for (int i=0; i < sentence.length(); i++) {
            if (string(1, sentence[i]) == " ") {
                word_el.word = current_word;
                word_el.page = 0;
                data->prepend(word_el);
                if (current_word > max_word)
                    max_word = current_word;
                current_word = "";
            } else {
                current_word += string(1, sentence[i]);
            }
        }
        if (size_of_page < max_word.length()) {
            throw out_of_range("Size of page is smaller than word's length :(");
        } else {
            int current_length = 0;
            int current_page = 1;
            int page_length;
            for (int i=0; i < data->get_length(); i++) {
                page_length = size_of_page / 2;
                if (current_page % 10 == 0)
                    page_length = 3 * size_of_page / 4;
                if (current_page != 1 && current_page % 10 != 0)
                    page_length = size_of_page;
                current_length += data->get(i).word.length() + 1;
                struct word_el temp;
                if (current_length <= page_length) {
                    temp.page = current_page;
                    temp.word = data->get(i).word;
                    data->set(i, temp);
                }
                else {
                    current_length = data->get(i).word.length();
                    current_page++;
                    temp.page = current_page;
                    temp.word = data->get(i).word;
                    data->set(i, temp);
                }
            }
        }
        shell_sort(data);
    }

    void show_arr() {
        for (int i=0; i < data->get_length(); i++) {
            cout << data->get(i).word << "| page:" << data->get(i).page << endl;
        }
    }

    string get_word(int index) {
        return data->get(index).word;
    }

    int get_page(int index) {
        return data->get(index).page;
    }
};