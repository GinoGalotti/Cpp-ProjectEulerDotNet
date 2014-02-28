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
template<typename NumTy>
string String(const NumTy& Num)
{
	stringstream StrStream;
	StrStream << Num;
	return(StrStream.str());
}


int latticePath(int posX, int posY ){
	int numberOfPath;
	if (posX==0 and posY==0){
		numberOfPath = 1;
	}else{
		numberOfPath = 0;
		if(posX > 0)
			numberOfPath += latticePath(posX -1 , posY);
		if (posY > 0)
			numberOfPath += latticePath(posX , posY -1);

	}
	return numberOfPath;
}


ttmath::UInt<6> latticePathOptimized(int lengthX, int lengthY){
	//The number of Paths of a Lattice path is equal to a binomial coefficent of:
	//(x + y)
	//(  x  )	=  !(x+y) / y!x!
	ttmath::UInt<6> factorialXAddY = 1, factorialX = 1, factorialY = 1;
	if (lengthX > lengthY){
		for (int i = 2 ; i <= lengthY; i++ ){
			factorialY *= i ;}

		factorialX = factorialY;
		for (int i = lengthY+1; i <= lengthX; i++){
			factorialX *= i;}

		factorialXAddY = factorialX;
		int limit = lengthX + lengthY;
		for (int i = lengthX+1; i <= limit; i++){
			factorialXAddY *= i;
		}
	}else {
		for (int i = 2 ; i <= lengthX; i++ ){
			factorialX *= i ;}

		factorialY = factorialX;
		for (int i = lengthX+1; i <= lengthY; i++){
			factorialY *= i;}

		factorialXAddY = factorialY;
		int limit = lengthX + lengthY;
		for (int i = lengthY+1; i <= limit; i++){
			factorialXAddY *= i;
		}

	}
	return factorialXAddY / (factorialX * factorialY);
}



int main()
{
    ttmath::UInt<6> solution = 0;

    solution = latticePathOptimized(20,20);
    //solution = latticePath(20,20);
    cout << solution;
    return 0;
}
