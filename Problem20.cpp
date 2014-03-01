/**
 * Solution by Luis Galotti
 * NOTE: I'm using TTMath library to deal with really big integer numbers. You can find more information about it at: http://www.ttmath.org/
 * n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
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
