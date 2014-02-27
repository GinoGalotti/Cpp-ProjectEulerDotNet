/**
 * Solution by Luis Galotti
 * The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

const int MAX_NUMBER = 1000;

unsigned long long lengthOfTheChain(unsigned int startingNumber){
	unsigned long long actualNumber = startingNumber;
	unsigned long long length = 1;
	
	while (actualNumber > 1){
		if (actualNumber % 2 == 0 ){
			actualNumber /= 2;
		} actualNumber = actualNumber * 3 + 1;
		length++;
	}
	
}	

int main()
{
    unsigned long long solution = 0;
    int i = MAX_NUMBER;
    if (i % 2 == 0) i--;
   	for (i ; i > 1; i = i-2){
   		
   		unsigned long long aux = lengthOfTheChain(i);
   		if (aux > solution) solution = aux;
   	}
       	
     
    printf("Solution = %llu", solution );
        
    
    return 0;
}
