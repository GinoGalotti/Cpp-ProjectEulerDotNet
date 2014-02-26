/**
 * Solution by Luis Galotti
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
 
#include <iostream>
#include <cmath>

using namespace std;

bool isPrimeBiggerThan10 (int number);
long long getPrimeAdditionSieveOfAtkin(int number);

//When I read about Sieve of Atkin, I implemented this getting faster results
long long getPrimeAdditionSieveOfAtkin(int number){
	 //Create the various different variables required
	 int limit = number, root = ceil(sqrt(limit)), insert;
	 long long addition = 0;
	 //int primes[(limit/2)+1];
	 //primes[0] = 2;
	 //primes[1] = 3;
	 bool sieve[limit];
	 for (int z = 0; z < limit; z++) sieve[z] = false; //Not all compilers have false as the default boolean value
	 for (int x = 1; x <= root; x++) {
		 for (int y = 1; y <= root; y++)
			 {
			 //Main part of Sieve of Atkin
			 int n = (4*x*x)+(y*y);
			 if (n <= limit && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;
			 n = (3*x*x)+(y*y);
			 if (n <= limit && n % 12 == 7) sieve[n] ^= true;
			 n = (3*x*x)-(y*y);
			 if (x > y && n <= limit && n % 12 == 11) sieve[n] ^= true;
		}}
	 //Mark all multiples of squares as non-prime
	 for (int r = 5; r <= root; r++) if (sieve[r]) for (int i = r*r; i < limit; i += r*r) sieve[i] = false;
	 //Add into prime array, just in case we need it on other problems
	 for (int a = 5; a < limit; a++)
	 {
		 if (sieve[a])
			 {
			 //primes[insert] = a;
			 //insert++;
			 addition += a;
		 	 }}
	return addition;
}


//This was my first approach 'home-maded'
bool isPrimeBiggerThan10 (int number){
    int i;
    
    for (i=10; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}}
	return true;	
 
}    
 

int main()
{
    long long solution = 0;
    //This was my first approach
    /*int index;
    int addition = 17; // 17 = 2 + 3 + 5 + 7
    for (index = 2000000; index > 10; index--){
    	if ((index % 2 != 0) and (index % 3 != 0) and (index % 5 != 0) and (index % 7 != 0)){
    		if (isPrimeBiggerThan10(index)){
    			addition += index;
    		}
    	}
    }
    solution = addition;*/
    solution = getPrimeAdditionSieveOfAtkin(2000000);
   	printf("Solution =  %llu", solution);
   
   return 0;
}
