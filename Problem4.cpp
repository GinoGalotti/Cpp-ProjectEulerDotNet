/**
 * Solution by Luis Galotti
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

const int NUMBER_MIN= 100;
const int NUMBER_MAX= 999;

string toString(int number)
   {
   ostringstream s;
   string cad = "";
   if (s << number)
      cad = s.str();

   return cad;
   }

bool isPalindrome(const string& p_str) {

   int length = p_str.size();
   bool palindrome = true;

   for (int i = 0; i < length/2; i++){
    if (p_str[i] != p_str[length - 1 - i]) palindrome = false;
   }

   return palindrome;
}

int main()
{
    int i, j, product, solution = 0;
     for (i = NUMBER_MAX; i >= NUMBER_MIN; i--)
       {
          for (j = NUMBER_MAX; j >= NUMBER_MIN; j--)
          {
             product = i*j;
             if (isPalindrome(toString(product)) and (product > solution))
                {solution = product;}
             }}

   	printf("Solution =  %i", solution);

   return 0;
}
