/**
 * Solution by Luis Galotti
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
 
#include <iostream>
bool isPalindromic (int number);

bool isPalindromic (int number){
    bool palindromic = true;
    int length = 0;
    //We are going to save the last digit first
    int digits [1000];
    int numberAux = number;
    bool continue = true;
    while (continue){
        digits[i] = numberAux % 10;
        numberAux = numberAux / 10;
        length++;
        if (numberAux == 0) continue = false;
    }
    continue = true;
    int aux = 0;
    while (continue){
        if (digits[aux] != digits[length - aux - 1]) {
            continue = false;
            palindromic = false;
        }
        aux++;
        if (aux == length / 2)
            continue = false;
    }
    
    return palindromic;	
 
}

using namespace std;

int main()
{
    long long solution = 0;
    long long min = 100;
    bool continuar = true;
    int number = 999;
    int numberAux = 999;
    while (continuar){
        bool continuar2 = true;
        while (continuar2){
            if (isPalindromic(number * numberAux)){
                continuar2 = false;
                continuar= false;
                solution = 
            }
        }
    }
    
    if (solution == 0) 
        printf("600851475143 is not prime");
    else {
        printf("pedo");
        printf("Solution =  %l", solution);} 
   
   return 0;
}
