/**
 * Solution by Luis Galotti
 * This solution need the file problem18CompanionFile (where is written the tree)
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67,
is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

#include <fstream>
#include <iostream>
#include <string.h>
#define TRIANGLE "problem18CompanionFile.txt"

using namespace std;
const int maxNum = 15;
const int MAX = 100;

void compactRows( int* upperRow, int* lowerRow, int* numLines ){
	for (int i = 0; i < *numLines; i++){
        if (*(lowerRow+i) > *(lowerRow+i+1)){ *(upperRow + i) = *(lowerRow+i) + *(upperRow + i);}
        else {*(upperRow + i) = *(lowerRow+i+1) + *(upperRow + i);}
	}
}

int main()
{
    char* lines;

    fstream infile(TRIANGLE);

    int* upperRow;
    int* lowerRow;
    int* rows[MAX];
    static int numLines  = 0;

    if(! infile.is_open() )
    {
        cout << "Could not open " << TRIANGLE << endl;
        return 1;
    }

    while( !infile.eof() )
        {
        lines = new char[MAX+1];                //Get file lines into char[]s
        infile.getline(lines, MAX);

        if(strlen(lines) < 1 )                  //Get out if problems
            break;

        int len = strlen(lines) - numLines;     //Define int arrays of
        rows[numLines] = new int[len];          //correct length (no spaces)

        int pos = 0;
        for(int i = 0; i < strlen(lines); i++)
        {
           if ( ' ' == lines[i])                //Convert to ints, skip space
           {
                rows[numLines][pos] = static_cast<int>(lines[i+1]-48);
                rows[numLines][pos] *= 10;
                rows[numLines][pos] += static_cast<int>(lines[i+2]-48);
               i += 2;
            }
            else
            {
                rows[numLines][pos] = static_cast<int>(lines[i]-48);
                rows[numLines][pos] *= 10;
                rows[numLines][pos++] += static_cast<int>(lines[i+1]-48);
                i += 2;
            }
        }
        numLines++;
        delete[] lines;
        }
    infile.close();
    numLines--;                                //Reverse superfluous decrement

    while(numLines > 0)
    {
        lowerRow = rows[numLines];
        upperRow = rows[numLines-1];

        compactRows(upperRow, lowerRow, &numLines);

        for(int i = 0; i < numLines; i++)
             cout << *(upperRow+i) << " ";
        cout << endl;
        delete[] lowerRow;
        numLines--;
    }
    delete[] upperRow;

    cout << "Solution = " << *(rows);
    return 0;
}
