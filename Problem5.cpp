/**
 * Solution by Luis Galotti
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
 
#include <iostream>
int GetGCD(int num1, int num2)
{
       while(num1!=num2)
       {
       if(num1 > num2)
              num1 = num1 - num2;
       if(num2 > num1)
              num2 = num2 - num1;
       }
       return num1;
}
 
int GetLCM(int num1, long num2)
{
    return (num1 * num2) / GetGCD(num1, num2);
}
 
using namespace std;

int main()
{
    int solution = 1;
    int max = 20;
    int aux = 1;
    for (int i = 2; i<=20; i++){
        aux = GetLCM(aux, i);
    }
    solution = aux;
   	printf("Solution =  %i", solution);
   
   return 0;
}
