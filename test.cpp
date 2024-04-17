#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int tally (int arr[], int size){
    int count[] = {0, 0, 0};
    for(int i = 0; i< size; i++){
        if(arr[i] == 0){
            count[1] = count[1]+1;
        }else if(arr[i] > 0){
            count[0] = count[0]+1;
        }else{
            count[2] = count[2]+1;
        }
    }
    cout << "zero: " << count[1] << endl;
    cout << "pos: " << count[0] << endl;
    cout << "neg: " << count[2] << endl;
    int max = count[0];
    for(int i = 1; i < 3; i++){
        if (count[i] > max){
            max = count[i];
        }
    }
    return max;
}
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void testTally() {
    srand(time(0)); // Seed the random number generator

    // Test case 1: General test case with various positive, negative, and zero elements
    int arr1[] = {1, -2, 3, 2, 0, 5, 6, -1, -2, -3, -7, -8, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << "Test case 1: " << tally(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;

    // Test case 2: Random array with 10 elements
    int arr2[10];
    for (int i = 0; i < 10; i++) {
        arr2[i] = randomInt(-10, 10); // Generate random numbers between -10 and 10
    }
    cout << "Test case 2: ";
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << " ";
    }
    cout << "-> " << tally(arr2, 10) << endl;

    // Test case 3: Random array with 20 elements
    int arr3[20];
    for (int i = 0; i < 20; i++) {
        arr3[i] = randomInt(-10, 10); // Generate random numbers between -10 and 10
    }
    cout << "Test case 3: ";
    for (int i = 0; i < 20; i++) {
        cout << arr3[i] << " ";
    }
    cout << "-> max:" << tally(arr3, 20) << endl;

    // Add more test cases as needed
}

int main(){
    testTally();
    return 0;
}