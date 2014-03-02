/**
 * Solution by Luis Galotti
 * This code need the file "Problem22CompanionFile.txt"
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order.
 Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
Evaluate the sum of all the amicable numbers under 10000.
*/
#include <stdio.h>
#include <fstream>
#include <map>
#include <string>

#define FILENAMES "Problem22CompanionFile.txt"

using namespace std;
map<string, int> names;
map<string, int>::iterator ite;

int main()
{
    long long solution  = 0;
    int value = 0;
    char in;
    string str = "";
    ifstream inFile(FILENAMES);

    if(! inFile.is_open() ){
        printf("Could not find %s", FILENAMES);
        return 1;
    }

   in = inFile.get();

   while(!inFile.eof())
    {
        if (in == '\"')
        {
            if(str.size() > 0) names[str] =  value;
            str = "";
            value = 0;
         }
        else if (in >= 'A' && in <= 'Z')
        {
            str += in ;
            value += (int)in-64;
        }
        in = inFile.get();
    }

    inFile.close();

    ite = names.begin();
    for (int i = 1; i <= names.size(); i++){
        solution += (ite->second * i);
        ite++;
    }
    printf("Solution = %llu", solution);
    return 0;
}
