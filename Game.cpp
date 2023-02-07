//
// Created by riwaa on 6-2-2023.
//

#include "Game.h"
#include <fstream>
#include <time.h>
#include <algorithm>

void Game::check_state(string input_lines, string input_codeword) {
    if (input_lines == input_codeword){
        cout << "**********************************************"<< endl;
        printf(" WELL DONE SOLDIER! He is now alive !\n");
        cout << "**********************************************"<< endl;
        saved();
        cout << endl;
        cout << "you guessed "<< codeword << " Correctly !  :) " << endl;
    }else{
        cerr << "**********************************************"<< endl;
        cerr << "      MISSON FAILED: BETTER LUCK NEXT TIME   "<< endl;
        cerr << "**********************************************"<< endl;
        cout << endl;
        cout << "The codeword was : "<< codeword <<endl;
    }
}
bool Game::incorrect_char(char input) {
    for (int i = 0; i < incorrect.size(); ++i) {
        if (incorrect[i] == input){
            return true;
        }else{
            continue;
        }
    }
    return false;
}

bool Game::correct_chars(char input) {
    for (int i = 0; i < correct.size(); ++i) {
        if (correct[i] == input){
            return true;
        }else{
            continue;
        }
    }
    return false;
}

void Game::main_game_loop() {
    wrong_char = 0;
    title();
    cout <<endl;
    cout << "Hi ! "<<"your task is to save this man from getting hanged to death!" << endl;
    while(lines != codeword && wrong_char < 10){
        first:
        cout<<" Guess the codeword: "<< lines << endl;
        cin >> user_input;
        if (correct_chars(user_input)|| incorrect_char(user_input)){
            printf("You have already guessed this char !\n");
            goto first;
        }
        else{
            for (int i = 0; i < codeword.length(); ++i) {
                my_words.push_back(codeword[i]);
            }
            for (int i = 0; i < my_words.size(); ++i) {
                if (user_input == my_words[i]){
                    correct.push_back(user_input);
                    for (int j = 0; j < codeword.size(); ++j) {
                        if (codeword[j] == user_input){
                            lines[j] = user_input;
                            continue;
                        }else{
                            continue;
                        }
                    }
                    if (lines == codeword){
                        goto last;
                    }else{
                        goto first;
                    }
                }
                else{
                    continue;
                }
            }
            if (lines == codeword){
                break;
            }else{
                cerr<< "Incorrect :(" << endl;
                incorrect.push_back(user_input);
                counter--;
                wrong_char++;
                hang_state(wrong_char);
                cout << "Lives left: "<<counter << endl;
            }
        }
    }
    last:
    check_state(lines,codeword);
}

void Game::choose_word(){
    srand(time(0));
    ifstream read{"words"};
    string print = "";
    while(getline(read,print)){
        count_lines++;
        file_words.push_back(print);
    }
    read.close();
    int getindex = rand() % count_lines;
    //store that word
    codeword = file_words[getindex];
    for (int i = 0; i <codeword.size(); ++i) {
        lines += "_";
    }
}
void Game::hang_state(int miss) const {
    if (miss == 1){
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<""<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 2){
        cout <<""<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 3){
        cout <<"____________________"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 4){
        cout <<"____________________"<< endl;
        cout <<"|                  |"<< endl;
        cout <<"|                  |"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 5){
        cout <<"_____________________"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 6){
        cout <<"_____________________"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if(miss == 7){
        cout <<"_____________________"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|----------"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 8){
        cout <<"_____________________"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t   "<<"---------|----------"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 9){
        cout <<"_____________________"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|                   |"<< endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"0"<<"\t"<<"0"<<endl;
        cout <<"|"<<"\t\t"<<"  00000"<< endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t   "<<"---------|----------"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t    "<<"|"<<endl;
        cout <<"|"<<"\t\t"<<"   /"<< endl;
        cout <<"|"<<"\t\t"<<"  /"<< endl;
        cout <<"|"<<"\t\t"<<" /"<< endl;
        cout <<"|"<<"\t\t"<<"/"<< endl;
        cout <<"|"<< endl;
        cout <<"----------------------------------------"<< endl;
    }
    else if (miss == 10){
        printf(" ___________.._______\n"
               "| .__________))______|\n"
               "| | / /      ||\n"
               "| |/ /       ||\n"
               "| | /        ||.-''.\n"
               "| |/         |/  _  \\\n"
               "| |          ||  `/,|\n"
               "| |          (\\\\`_.'\n"
               "| |         .-`--'.\n"
               "| |        /Y . . Y\\\n"
               "| |       // |   | \\\\\n"
               "| |      //  | . |  \\\\\n"
               "| |     ')   |   |   (`\n"
               "| |          ||'||\n"
               "| |          || ||\n"
               "| |          || ||\n"
               "| |          || ||\n"
               "| |         / | | \\\n"
               "\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|\n"
               "|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|\n"
               "| |        \\ \\        | |\n"
               ": :         \\ \\       : :\n"
               ". .          `'       . .\n");
    }
}

void Game::title() const {
    cout << "*********************************************************"<<endl;
    printf(" _                                             \n"
           "| |                                            \n"
           "| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n"
           "| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n"
           "| | | | (_| | | | | (_| | | | | | | (_| | | | |\n"
           "|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n"
           "                    __/ |                      \n"
           "                   |___/\n");
    cout <<"********************************************************"<<endl;
}

void Game::saved() const {
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⠆⠿⡿⠷⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⠹⡄⠀⠀⢀⠀⠈⠙⢿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⢠⡶⡄⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠁⠀⢸⣿⠀⠀⢹⣇⠀⠀⠀⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⣰⡶⠛⠿⣦⣤⡘⡇⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⠃⠠⣾⡄⠈⠀⠀⠈⢉⣤⣄⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⠀⠀⠀⠀⠀⠀\n"
           "⢿⣧⡀⠀⠈⠙⢿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⢸⡆⠀⠘⣿⣆⠀⠀⣠⣾⡟⠁⣰⣿⠁⠀⠀⠀⠀⠀⠀⢠⡞⣹⣯⣤⣶⠶⠶⣶⡄\n"
           "⠀⠙⠿⣶⣄⣀⣀⣡⣼⠇⠀⠀⠀⠀⠀⠀⠀⠈⢿⣄⡀⠈⠛⠷⠾⠟⠉⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⢠⡎⠀⠿⠉⠁⠀⠀⣐⣠⡇\n"
           "⠀⠀⠀⠀⠉⠉⠙⠙⠻⢿⣷⣦⣤⡀⠀⠀⠀⠀⠀⠘⠻⠷⠶⣶⣶⣶⠿⠛⠋⠀⠀⠀⠀⢀⣀⣤⣴⣿⡇⠿⠿⠶⠶⠿⠛⠛⠉⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⢿⣷⣦⣄⡀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⣠⣤⣶⠿⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⢷⣄⣼⣃⡴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡟⠋⠻⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠙⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⢀⣷⣦⣤⣄⣀⠀⠀⠀⠀⠀⢠⣾⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡆⠀⠀⠀⠀⠀⠀⠀⣀⣤⡀⠀⠀⠀⠀⠀\n"
           "⠀⢸⣿⠀⠈⠉⠙⠳⢶⣄⠀⣠⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⡀⠀⠀⠀⣀⣴⠾⠛⠙⣿⠀⠀⠀⠀⠀\n"
           "⠀⠸⣿⡀⠀⠀⠀⠀⣀⣽⣷⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⢀⣰⡾⠋⠁⠀⠀⢠⣿⠀⠀⠀⠀⠀\n"
           "⠀⠀⠙⠿⠷⠶⠾⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠻⣅⠀⠀⢀⣀⣴⣿⠇⠀");
}
