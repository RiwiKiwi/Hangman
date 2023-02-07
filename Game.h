//
// Created by riwaa on 6-2-2023.
//

#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Game {
    // there are 10 tries in total
    int counter = 10;
    //my words splitted in vector
    vector<char>my_words;
    //KEEPING already guessed words
    vector<char> incorrect;
    vector<char> correct;
    //get the input from the user
    char user_input;
    //store all file words here
    vector<string> file_words;
    // this will be the word that needs to be guessed
    string codeword;
    // Display of _ for the user to guess the word
    string lines;
    // get the line of our file
    int count_lines = 0;
    int wrong_char;
public:
    bool correct_chars(char input);
    bool incorrect_char(char input);
    void main_game_loop();
    void hang_state(int miss)const;
    void choose_word();
    void check_state(string input_lines, string input_codeword);
    void title()const;
    void saved()const;
};


#endif //HANGMAN_GAME_H
