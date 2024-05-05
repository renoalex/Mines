#include <iostream>
#include <ctime>
#include <string>


int mine, cell, val, score = 0;
bool gameOver = false;
std::string table[25];

void Setup() {
    system("clear");
    srand(time(nullptr));
    mine = rand() % 26;
    val = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            table[val] = std::to_string(val);
            val++;
        }
    }
}

void Display() {
    val = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << table[val] << "\t";
            val++;
        }
        std::cout << "\n\n\n";


    }
    std::cout << "SCORE: " << score << "\n";
}


void Input() {
    std::cout << "Choose a cell number between 0-24\n";
    std::cin >> cell;
    if (cell > 25 || cell < 0) {}
    else {
        if (cell == mine) {
            gameOver = true;
            table[cell] = "!!";
        } else {
            if (table[cell] == "*") {}
            else {
                table[cell] = "*";
                score++;
            }
        }
    }
}


int main() {
    Setup();
    while (!gameOver) {

        Display();
        Input();
        system("clear");

    }

    Display();
    std::cout << "GAME OVER\n";
    std::cin.get();

    return 0;
}