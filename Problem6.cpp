/**
 * Solution by Luis Galotti
 * The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
 
#include <iostream>
long sumOfSquare(int minRange, int maxRange)
{
    long result = 0;
       for (int i = minRange; i<=maxRange; i++){
           result = result + i * i;
       }
    return result;
}
 
long squareOfSum(int minRange, int maxRange)
{
    long result; 
    long sum = minRange + maxRange; 
    if (sum % 2){
        result =  (minRange + maxRange - 1) * sum / 2;
    }
    else {
        result = ((minRange + maxRange ) * (sum / 2 - 1)) + (sum / 2) ;
    }
    return result * result; 
}
 
using namespace std;

int main()
{
    long solution = squareOfSum(1, 100) - sumOfSquare(1, 100);
    
   	printf("Solution =  %lu", solution);
   
   return 0;
}
