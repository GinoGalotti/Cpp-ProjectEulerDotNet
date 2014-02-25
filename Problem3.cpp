/** TODO: QUE FUNCIONE COJONEH
 * Solution by Luis Galotti
 * The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
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
    long long solution = 0;
    long long number = 600851475142;
    long long max = 600851475143;
    bool found = false;
    while (!found && number > 1){
        if (max % number == 0){
            if (isPrime(number)) 
                found = true;}
        number--;
    }
    solution = number;
    if (solution == 0) 
        printf("600851475143 is not prime");
    else {
        printf("pedo");
        printf("Solution =  %l", solution);} 
   
   return 0;
}
