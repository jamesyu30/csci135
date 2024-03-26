#include <iostream>
#include <string>
#include "MemoryGame.hpp"
using namespace std;

int main() {
    // MemoryGame game;
    // game.~MemoryGame();

    MemoryGame game2(3, 9);
    //game2.display();
    game2.~MemoryGame();

    string words[] = {"Hello", "Hi", "Hey"};
    int size = sizeof(words) / sizeof(words[0]);
    MemoryGame game3(words, 3, 9);
    //game3.display();
    game3.~MemoryGame();


    MemoryGame game;
    game.play();

    game.~MemoryGame();
    return 0;
}
