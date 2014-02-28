/**
 * Solution by Luis Galotti
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
#include <stdio.h>

using namespace std;
const int maxNum = 1000;
const int lettersInNumber[20] = {3,   //one
                                3,    //two
                                5,    //three
                                4,    //four
                                4,    //five
                                3,    //six
                                5,    //seven
                                5,    //eight
                                4,    //nine
                                3,    //ten
                                6,    //eleven
                                6,    //twelve
                                8,    //thirteen
                                8,    //fourteen
                                7,    //fifteen
                                7,    //sixteen
                                9,    //seventeen
                                8,    //eighteen
                                8,    //nineteen
                                6};    //twenty


int countLetterOfNumber(int number){
	int total = 0;
	if (number <= 20){
        total = lettersInNumber[number-1];
        }else{
            if (number < 40 or (number >=80 and number < 100)){
                if (number % 10 == 0) total = 6;                                                        //thirty, eighty and ninety
                else total = 6 + countLetterOfNumber(number%10);                                        //twenty something, thirty something, eighty something or ninety something
            }else {
                if (number < 70 ){
                    if (number % 10 == 0) total = 5;                                                    //forty, fifty, sixty
                    else total = 5 + countLetterOfNumber(number%10);                                    //forty something, fifty something or sixty something
                }else {
                    if (number == 70) total = 7;                                                        //seventy
                    else {if (number < 100) total = 7 + countLetterOfNumber(number%10);                 //seventy something
                        else {                                                                          //this are > 100
                            if (number % 1000 == 0) total = lettersInNumber[(number/1000)-1] + 8;       //X thousand
                            else if (number % 100 == 0) total = lettersInNumber[(number/100)-1] + 7;     //X hundred
                                else total = lettersInNumber[(number/100)-1] + 7 + 3 + countLetterOfNumber(number%100);         //X hundred and something
                        }}}}}
	return total;
}



int main()
{
    int total = 0;

    for (int i = 1; i <= maxNum; i++){
        total += countLetterOfNumber(i);
    }
    printf("Solution = %i",total);
    return 0;
}
