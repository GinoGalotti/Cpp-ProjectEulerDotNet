/**
 * Solution by Luis Galotti
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <stdio.h>
using namespace std;
const int LIMIT = 10000;

int sumOfDivisors(int number){
    int sumDivisor = 1;
    for (int i = 2; i * i <= number; i++)
	  {
	    if (number % i == 0) {
	        sumDivisor += i;
	        sumDivisor += number / i;
	    }
	  }
	return sumDivisor;
}

bool isAmicable(int number){
    bool amicable = false;
    int sumDivisor = sumOfDivisors(number);
    if (sumOfDivisors(sumDivisor) == number && sumDivisor <= LIMIT && number != sumDivisor) amicable = true;

    return amicable;
}

int main()
{
   int sumOfAmicable = 0;
   for (int i = 2; i <= LIMIT; i++){
        if (isAmicable(i)) {sumOfAmicable += i;
        printf("Amicable number = %i \n", i );}
   }
  printf("Solution =  %i", sumOfAmicable);

   return 0;
}
