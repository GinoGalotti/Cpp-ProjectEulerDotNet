/**
 * Solution by Luis Galotti
 * NOTE: I'm using TTMath library to deal with really big integer numbers. You can find more information about it at: http://www.ttmath.org/
 * The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <string>
#include <sstream>
#include <ttmath/ttmath.h>

using namespace std;
//TTMath use a base word number system, so if we want to handle 2^1000; we need at least 1000/32 + 1.
const int numWordsNeeded = (1000/32) + 1;

ttmath::UInt<numWordsNeeded> power2To(int power){
	//The number of Paths of a Lattice path is equal to a binomial coefficent of:
	//(x + y)
	//(  x  )	=  !(x+y) / y!x!
	ttmath::UInt<numWordsNeeded> number = 1;

	for (int i = 1; i <= power; i++){
        number *= 2;
	}

	return number;
}

int main()
{
    ttmath::UInt<numWordsNeeded> solution = 0;

    solution = power2To(1000);
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
