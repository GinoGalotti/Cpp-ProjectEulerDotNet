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
    //We are going to save the last digit first, and we are going to limit to 7 digits. (our max is 999; so 999*999 is under 7 digits)
    int digits [7];
    int numberAux = number;
    bool continuar = true;
    int aux = 0;
    while (continuar){
        digits[aux] = numberAux % 10;
        numberAux = numberAux / 10;
        length++;
        aux++;
        if (numberAux == 0) continuar = false;
    }
    continuar = true;
    aux = 0;
    while (continuar){
        if (digits[aux] != digits[length - aux - 1]) {
            continuar = false;
            palindromic = false;
        }
        aux++;
        if (aux == length / 2)
            continuar = false;
    }
    
    return palindromic;	
 
}

using namespace std;

int main()
{
    int solution = 0;
    int min = 100;
    bool continuar = true;
    int number = 999;
    while (continuar){
        bool continuar2 = true;
        int numberAux = 999;
        while (continuar2){
        	int aux = number * numberAux;
            if (isPalindromic(aux)){
                if (aux > solution)
                	solution = aux;
            }
            numberAux--;
            if (numberAux == min) continuar2=false;
        }
        number--;
        if (number == min) continuar2=false;
    }
    
   	printf("Solution =  %i", solution);
   
   return 0;
}
