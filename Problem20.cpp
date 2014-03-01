/**
 * Solution by Luis Galotti
 * NOTE: I'm using TTMath library to deal with really big integer numbers. You can find more information about it at: http://www.ttmath.org/
 * You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <string>
#include <sstream>
#include <ttmath/ttmath.h>

using namespace std;
//TTMath use a base word number system, so if we want to handle 2^1000; we need at least 1000/32 + 1.
const int numWordsNeeded = 20;

ttmath::UInt<numWordsNeeded> factorialOf(int number){
	//The number of Paths of a Lattice path is equal to a binomial coefficent of:
	//(x + y)
	//(  x  )	=  !(x+y) / y!x!
	ttmath::UInt<numWordsNeeded> factorialOfNumber = 1;

	for (int i = number; i > 1; i--){
        factorialOfNumber *= i;
	}

	return factorialOfNumber;
}

int main()
{
    ttmath::UInt<numWordsNeeded> solution = 0;

    solution = factorialOf(100);
    string numberString = solution.ToString();
    int length = numberString.length();
    const char* a = numberString.c_str();
    solution = 0;
    for (int i = 0; i<length; i++){
      solution += (int(a[i]-48));
    }
    cout << solution;
    return 0;
}
