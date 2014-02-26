/**
 * Solution by Luis Galotti
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
 
#include <iostream>
bool isPrimeBiggerThan10 (long long number);

bool isPrimeBiggerThan10 (long long number){
    long long i;
    
    for (i=10; i * i <= number; i++)
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
    long long solution = 0;
    long long index;
    long long addition = 17; // 17 = 2 + 3 + 5 + 7
    for (index = 2000000; index > 10; index--){
    	if ((index % 2 != 0) and (index % 3 != 0) and (index % 5 != 0) and (index % 7 != 0)){
    		if (isPrimeBiggerThan10(index)){
    			addition += index;
    		}
    	}
    }
    solution = addition;
   	printf("Solution =  %llu", solution);
   
   return 0;
}
