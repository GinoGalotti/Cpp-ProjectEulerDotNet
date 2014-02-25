/**
 * Solution by Luis Galotti
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/
 
#include <iostream>
bool isPrime (long long number);

bool isPrime (long long number){
    long long i;
    
    for (i=2; i<number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}}
	return true;	
 
}    
 
using namespace std;

int main()
{
    long solution = 0;
    int index = 10001;
    long number = 1;
    while (index > 0){
        number++;
        if (isPrime(number))
                index--;
    }
    solution = number;
   	printf("Solution =  %lu", solution);
   
   return 0;
}
