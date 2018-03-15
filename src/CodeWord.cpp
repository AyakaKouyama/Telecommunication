#include "CodeWord.h"
#include <iostream>
using namespace std;

CodeWord::CodeWord()
{
    //ctor
}

void CodeWord::generate(vector<int> binary, vector<int>& result)
{
    int sum = 0, c=0;
   for(int k = 0; k< binary.size(); k += 8)
   {
    for(int i = 0; i<12; i++)
    {
        sum = 0;
        for(int j = 0; j<8; j++)
        {
            sum += binary[j+ k] * singleErrorGenerator[j][i];
        }
            sum %= 2;
            result.push_back(sum);
    }
    }

}


void CodeWord::decode(vector<int>& codeWord)
{
    int *result = new int[codeWord.size()];
    for(int k = 0; k<codeWord.size(); k+= 12)
    {
        for(int i = 0; i<4; i++)
        {
          result[i + k] = 0;
            for(int j = 0; j<12; j++)
            {
                result[i + k] += singleError[i][j] * codeWord[j+k];
            }
            result[i + k ] %= 2;
        }
    }


    int counter = 0;
    for(int k = 0; k<codeWord.size(); k+=12)
    {
        for(int i = 0; i<12; i++)
        {
            counter = 0;
            for(int j = 0; j<4; j++)
            {
                if(singleError[j][i] == result[j+ k])
                {
                    counter++;
                }

            }
            if(counter == 4)
            {
                if(codeWord[i+k] == 0)
                {
                    codeWord[i+k] = 1;
                }
                else
                {
                    codeWord[i+k] = 0;
                }

            }
        }
    }

    delete [] result;
}

void CodeWord::removeParityBits(vector<int>& from, vector<int>& to)
{
    int counter = 0;

    for(int i = 0; i<from.size(); i+=12)
    {
        for(int j = 0; j<12; j++)
        {
            if(j < 8)
            {
                to.push_back(from[j + i]);
            }
        }
    }
}
