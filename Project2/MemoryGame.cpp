#include "MemoryGame.hpp"
#include <iomanip>

MemoryGame::MemoryGame(int numPairs, int numSlots) {
     if (numPairs < 0 || numSlots < 0 || numSlots < numPairs * 2) {
        this->numPairs = 3;
        this->numSlots = 8;
    } else {
        this->numPairs = numPairs;
        this->numSlots = numSlots;
    }

    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Generating pairs of numbers
    for (int i = 0; i < numPairs * 2; i += 2) {
        int num = rand() % 1000;
        values[i] = to_string(num);
        values[i + 1] = to_string(num);

        bShown[i] = false;
        bShown[i + 1] = false;
    }

    // Filling the rest with empty strings
    for (int i = numPairs * 2; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }
}

MemoryGame::MemoryGame() : MemoryGame(3, 8) {}

MemoryGame::MemoryGame(string* words, int size, int numSlots) {
    if((size < 0 || numSlots < 0 ) || (numSlots < size*2)){
        numSlots = size*2;
    }
    this->numPairs = size;
    this->numSlots = numSlots;
    
    values = new string[numSlots];
    bShown = new bool[numSlots];

    //generating three numbers
    for (int i = 0; i < numPairs*2; i++){
        if (i % 2 == 1){
            values[i] = words[(i-1)/2];
        }else{
            values[i] = words[i/2];
        }

        bShown[i] = false;
    }
    //filling the rest with empty strings
    for (int i = numPairs*2; i < numSlots; i++){
        values[i] = "";
        bShown[i] = false;
    }
}

MemoryGame::~MemoryGame() {
    delete[] values;
    delete[] bShown;
    values = nullptr;
    bShown = nullptr;
}

void MemoryGame::randomize() {
    int size = numSlots;
    int num;
    while(size > 1){
        num = rand() % size;
        std::swap(values[num], values[size-1]);
        size--;
    }
}
void printSeparatedLine(int size) {
    std::cout << "+"; //the first +
    //draw -----+ for (size) many times
    for (int i = 0; i < size; i++){
        std::cout << "-----+";
    }

cout << endl;
}

void MemoryGame::display() const {
    std::cout << " ";
    for (int i = 0; i < numSlots; i++){
        std::cout << std::setw(3) << i << std::setw(3) << " ";
    }
    //setw(3) before i means i occupies 3-character,
    //For example, if i has only two digits,
    //then pad a space to its left.
    std::cout << std::endl;
    printSeparatedLine(numSlots);
    std::cout << "|";
    for(int i = 0; i < numSlots;i++){
        if(bShown[i]){
            std::cout << setw(5) << values[i] << "|";
        }
        else{
            std::cout << setw(6) << "|";
        }
    }
    std::cout << std::endl;
    printSeparatedLine(numSlots);
}

int MemoryGame::input() const{
    int slot;
    bool valid = true;
    std::cout << "Enter a unflipped card in [0, " << numSlots-1 << "]: " << endl;
    std::cin >> slot;
    do{
        if(slot < 0 || slot > numSlots-1){
            std::cout << "input is not in [0, " << numSlots-1 << "]. Re-enter: " << endl;
            valid = false;
            cin >> slot;
        }
        else if (bShown[slot]){
            std::cout << "The card is flipped already. Re-enter: " << endl;
            valid = false;
            cin >> slot;
        }else{
            valid = true;
        }
    }while(!valid);
    //cout << slot << endl;
    return slot;
}

void MemoryGame::play(){
    randomize();
    int right = 0;
    int round = 1;
    int slot; //inputed slot
    int flipped = 0; //number of flipped cards
    int prev = 0; //previous input
    while (right != numSlots/2){
        display();
        cout << "Round \t" << round << ":" << endl;
        if (round > 1){
            prev = slot;
        }
        slot = input();

        // new pair of cards
        if (flipped % 2 == 0){
            bShown[slot] = true;
            flipped++;
        }else{
            //checks if it matches
            if (values[prev] == values[slot]){
                bShown[slot] = true;
                right++;
                flipped++;
            }else{
                bShown[prev] = false;
                bShown[slot] = false;
                flipped--;
            }
        }

        round++;
    }
    display();
    cout << "Congratulations! Found out all pairs in " << round-1 << " rounds" << endl;
}
