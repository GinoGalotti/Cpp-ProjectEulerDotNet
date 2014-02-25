/**
 * Solution by Luis Galotti
 * The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>
bool isPrime (unsigned long long number);
bool isPrime (unsigned long long number){
    unsigned long long i;

	for (i=2; (i * i)<number; i++)
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
    unsigned long long solution = 0;
    const unsigned  long long number = 600851475143;
    //This way we check just until square root of number;
    for (unsigned long long i = 2; (i * i) < number; i++){
        if (number % i == 0){
        unsigned long long aux = i;
        if (isPrime(aux) and aux > solution) solution = aux;
        unsigned long long aux2 = number / i;
        if (isPrime(aux2) and isPrime(aux) and aux2 > solution) solution = aux2;}
    }

        printf("Solution =  %llu", solution);

   return 0;
}
