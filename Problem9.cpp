/**
 * Solution by Luis Galotti
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <stdio.h>
#include <string>
int* findTriplet (int addition){
    int triplet[3] = {0,0,0};
    int* pointer = triplet;

    for (int i = addition-3; i > (addition / 3) + 2;  i--){
        
        int j = (i <= addition /2) ? i : addition /2;
        
        for (j; j <= addition / 3 + 1 ; j--){
            int z = (j < (addition/3)) ? j : (addition/3-1);
            
            for (z; z <= (addition/3-1); z--){
                
                if (i + j + z == 1000){
                    if (z*z == j*j + i*i){
                    triplet[0] = i;
                    triplet[1] = j;
                    triplet[2] = z;
                    return pointer;}
                }
            }
        }
    }
    
    
    return pointer;
}    
using namespace std;

int main()
{   
    int *triplet, product;
    triplet = findTriplet(1000);
    product = triplet[0] * triplet[1] * triplet[2];

printf("Solution =  %i", product);

   return 0;
}
