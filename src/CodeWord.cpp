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

    int sum = 0;
   for(unsigned int k = 0; k< binary.size(); k += 8)
   {
    for(unsigned int i = 0; i<generatorM; i++)
    {
        sum = 0;
        for(unsigned int j = 0; j<generatorN; j++)
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

    for(unsigned int k = 0; k<codeWord.size(); k += errorM)
    {
        for(unsigned int i = 0; i<errorN; i++)
        {
          result[i + k] = 0;
            for(unsigned int j = 0; j<errorM; j++)
            {
                result[i + k] += error[i][j] * codeWord[j+k];
            }
            result[i + k] %= 2;
        }
    }



    int counter = 0;
    bool found = false;
    for(unsigned int k = 0; k<codeWord.size(); k += errorM)
    {
        found = false;
        for(unsigned int i = 0; i<errorM; i++)
        {

            counter = 0;
            for(unsigned int j = 0; j<errorN; j++)
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

                found = true;

            }
        }

      if(found == false && mode == 2)
      {
      bool match;
      counter = 0;

        for(unsigned int i = 0; i< errorM; i++)
        {

        for(unsigned int j = i+1; j< errorM; j++)
        {
            match = true;

            for(unsigned int l = 0; l< errorN; l++)
            {
                if((error[l][i] ^ error[l][j]) != result[l + k])
                {
                    match = false;
                    break;
                }
            }

        if(match == true)
        {
            if(codeWord[i+k] == 0)
            {
                codeWord[i+k] = 1;
            }
            else
                codeWord[i+k] = 0;

            if(codeWord[j+k] == 0)
            {
                codeWord[j+k] = 1;
            }
            else
              codeWord[j+k] = 0;

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
    for(unsigned int i = 0; i<from.size(); i += errorM)
    {
        for(unsigned int j = 0; j<errorM; j++)
        {
            if(j < 8)
            {
                to.push_back(from[j + i]);
            }
        }
    }
}
