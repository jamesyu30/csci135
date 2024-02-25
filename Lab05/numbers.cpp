/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 5A

checks if a number is divisible by a another number (isDivisibleBy)

checks if n is a prime number (isPrime)
*/

// 
#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d){
    if (d == 0){
        return false;
    }
    return (n % d == 0);
}

bool isPrime(int n){
    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++){
        //cout << "is div " << isDivisibleBy(n, i) << i <<  endl;
        if (isDivisibleBy(n, i)){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    int a = n+1;
    while (isPrime(a) == false){
        //cout << a;
        a++;
    }
    return a;
}

int countPrimes(int a, int b){
    int count = 0;
    for (int i = a; i <= b; i++){
        if (isPrime(i)){
            count++;
        }
    }
    return count; 
}

bool isTwinPrime(int n){
    if (isPrime(n) && (isPrime(n - 2) || isPrime(n+2))){
        return true;
    }
    return false;
}

int nextTwinPrime(int n){
    int a = n+1;
    while (isTwinPrime(a) == false){
        //cout << a;
        a++;
    }
    return a;
}

int largestTwinPrime(int a, int b){
    for (int i = b; i >= a; i--){
        if (isTwinPrime(i)){
            return i;
        }
    }
    return -1;
}

int main(){
    //cout << boolalpha << isPrime(1) << endl;
    for (int i = 0; i < 20; i++){
        //cout << isPrime(i) << endl;
    }
    cout << nextPrime(5);
    return 0;
}