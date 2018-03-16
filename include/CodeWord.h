#ifndef CODEWORD_H
#define CODEWORD_H
#include <iostream>
#include <vector>
using namespace std;

class CodeWord
{
   private:
    int mode;
    unsigned int generatorN=0;
    unsigned int generatorM=0;
    unsigned int errorN=0;
    unsigned int errorM=0;
    int** generator;
    int** error;
    int SingleGenerator[8][12] =  {
   { 1, 0, 0, 0, 0, 0, 0, 0,  1, 1, 0, 0},
   { 0, 1, 0, 0, 0, 0, 0, 0,  1, 0, 1, 0},
   { 0, 0, 1, 0, 0, 0, 0, 0,  0, 1, 1, 0},
   { 0, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1, 0},
   { 0, 0, 0, 0, 1, 0, 0, 0,  1, 0, 0, 1},
   { 0, 0, 0, 0, 0, 1, 0, 0,  0, 1, 0, 1},
   { 0, 0, 0, 0, 0, 0, 1, 0,  0, 0, 1, 1},
   { 0, 0, 0, 0, 0, 0, 0, 1,  0, 1, 1, 1},
   };
    int SinglEerror[4][12] = {
    { 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1 }
    };

    int DoubleGenerator[8][16] = {
   { 1, 0, 0, 0, 0, 0, 0, 0,  0, 0, 1, 0, 1, 1, 1, 0},
   { 0, 1, 0, 0, 0, 0, 0, 0,  1, 0, 0, 1, 0, 1, 1, 1},
   { 0, 0, 1, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 0, 1, 1},
   { 0, 0, 0, 1, 0, 0, 0, 0,  0, 1, 1, 0, 0, 1, 0, 1},
   { 0, 0, 0, 0, 1, 0, 0, 0,  1, 0, 1, 1, 0, 0, 1, 0},
   { 0, 0, 0, 0, 0, 1, 0, 0,  1, 1, 0, 1, 1, 0, 0, 1},
   { 0, 0, 0, 0, 0, 0, 1, 0,  1, 1, 1, 0, 1, 1, 0, 0},
   { 0, 0, 0, 0, 0, 0, 0, 1,  0, 1, 1, 1, 0, 1, 1, 0},
    };
    int DoubleError[8][16] = {
    { 0, 1, 1, 0, 1, 1, 1, 0,   1, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 1, 1, 1,   0, 1, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 1, 1, 0, 1, 1,   0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 1, 1, 0, 1,   0, 0, 0, 1, 0, 0, 0, 0 },
    { 1, 0, 1, 0, 0, 1, 1, 0,   0, 0, 0, 0, 1, 0, 0, 0 },
    { 1, 1, 0, 1, 0, 0, 1, 1,   0, 0, 0, 0, 0, 1, 0, 0 },
    { 1, 1, 1, 0, 1, 0, 0, 1,   0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 0, 1, 0, 0,   0, 0, 0, 0, 0, 0, 0, 1 }
};

   public:
        CodeWord(int mode);
        ~CodeWord();

        void generate(vector<int> binary, vector<int>& result);
        void decode(vector<int>& codeWord);
        void removeParityBits(vector<int>& from, vector<int>& to);

};

#endif // CODEWORD_H
