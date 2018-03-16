#include "CodeWord.h"
#include <iostream>
#include <string.h>
using namespace std;

CodeWord::CodeWord(int mode)
{
        this->mode = mode;

        if(mode == 1)
        {
            generatorN = 8;
            generatorM = 12;
            errorN = 4;
            errorM = 12;
            generator = new int*[8];
            for(int i = 0; i<8; i++)
            {
                generator[i] = new int[12];
            }

            for(int i = 0; i<8; i++)
            {
                for(int j = 0; j< 12; j++)
                {
                   generator[i][j] = SingleGenerator[i][j];
                }
            }

            error = new int*[4];
            for(int i = 0; i<4; i++)
            {
                error[i] = new int[12];
            }

            for(int i = 0; i<4; i++)
            {
                for(int j = 0; j<12; j++)
                {
                    error[i][j] = SinglEerror[i][j];
                }
            }
        }
        else if(mode == 2)
        {
            generatorN = 8;
            generatorM = 16;
            errorN = 8;
            errorM = 16;


            generator = new int*[8];
            for(int i = 0; i<8; i++)
            {
                generator[i] = new int[16];
            }
            for(int i = 0; i<8; i++)
            {
                for(int j = 0; j<16; j++)
                {
                    generator[i][j] = DoubleGenerator[i][j];
                }
            }


            error = new int*[8];
            for(int i = 0; i<8; i++)
            {
                error[i] = new int[16];
            }
            for(int i = 0; i<8; i++)
            {
                for(int j = 0; j<16; j++)
                {
                    error[i][j] = DoubleError[i][j];
                }
            }


        }
}


CodeWord::~CodeWord()
{
    if(mode == 1)
    {
        for(int i = 0; i<8; i++)
        {
            delete [] generator[i];
        }

        for(int i = 0; i<4; i++)
        {
            delete [] error[i];
        }

          delete [] generator;
          delete [] error;

    }
    else if(mode == 2)
    {
        for(int i = 0; i<8; i++)
        {
            delete [] generator[i];
            delete [] error[i];
        }
        delete [] generator;
        delete [] error;
    }

}
void CodeWord::generate(vector<int> binary, vector<int>& result)
{

    int sum = 0, c=0;
   for(int k = 0; k< binary.size(); k += 8)
   {
    for(int i = 0; i<generatorM; i++)
    {
        sum = 0;
        for(int j = 0; j<generatorN; j++)
        {
            sum += binary[j+ k] * generator[j][i];
        }
            sum %= 2;
            result.push_back(sum);
    }
    }

}

void CodeWord::decode(vector<int>& codeWord)
{
    int countTo;
    if(mode == 1) countTo = 4;
    else countTo = 8;

    int *result = new int[codeWord.size()];
    for(int k = 0; k<codeWord.size(); k += errorM)
    {
        for(int i = 0; i<errorN; i++)
        {
          result[i + k] = 0;
            for(int j = 0; j<errorM; j++)
            {
                result[i + k] += error[i][j] * codeWord[j+k];
            }
            result[i + k] %= 2;
            cout<<result[i+k];
        }
       cout<<endl;
    }

    int counter = 0;
    bool found = false;
    for(int k = 0; k<codeWord.size(); k += errorM)
    {
        for(int i = 0; i<errorM; i++)
        {
            counter = 0;
            for(int j = 0; j<errorN; j++)
            {
                if(error[j][i] == result[j+ k])
                {
                    counter++;
                }

            }
            if(counter == countTo)
            {
                if(codeWord[i+k] == 0)
                {
                    codeWord[i+k] = 1;
                }
                else
                    codeWord[i+k] = 0;
                found == true;
            }
        }
    }

    if(mode == 2 && found == false)
    {
        bool match;
        for(int l = 0; l<codeWord.size(); l += errorM)
        {
            counter = 0;
        for(int i = 0; i< errorM; i++)
        {

        for(int j = i+1; j< errorM; j++)
        {
            match = true;

            for(int k = 0; k< errorN; k++)
            {
                if(error[k][i] ^ error[k][j] != result[k + l])
                {
                    match = false;
                    break;
                }
            }

        if(match == true)
        {
            counter++;
           // cout<<counter<<endl;
           cout<<i + l<<" "<<j+ l<<endl;
            if(codeWord[i+l] == 0)
            {
                codeWord[i+l] = 1;
            }
            else
                codeWord[i+l] = 0;

            if(codeWord[j+l] == 0)
            {
                codeWord[j+l] = 1;
            }
            else
                codeWord[j+l] = 0;
                break;

        }
        }
    }
}

}

    delete [] result;
}

void CodeWord::removeParityBits(vector<int>& from, vector<int>& to)
{
    for(int i = 0; i<from.size(); i += errorM)
    {
        for(int j = 0; j<errorM; j++)
        {
            if(j < 8)
            {
                to.push_back(from[j + i]);
            }
        }
    }
}
