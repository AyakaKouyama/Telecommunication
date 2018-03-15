#ifndef CODEWORD_H
#define CODEWORD_H
#include <iostream>
#include <vector>
using namespace std;

class CodeWord
{
   private:
       int singleErrorGenerator[8][12] = {
   { 1, 0, 0, 0, 0, 0, 0, 0,  1, 1, 0, 0},
   { 0, 1, 0, 0, 0, 0, 0, 0,  1, 0, 1, 0},
   { 0, 0, 1, 0, 0, 0, 0, 0,  0, 1, 1, 0},
   { 0, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1, 0},
   { 0, 0, 0, 0, 1, 0, 0, 0,  1, 0, 0, 1},
   { 0, 0, 0, 0, 0, 1, 0, 0,  0, 1, 0, 1},
   { 0, 0, 0, 0, 0, 0, 1, 0,  0, 0, 1, 1},
   { 0, 0, 0, 0, 0, 0, 0, 1,  0, 1, 1, 1},
   };
      int singleError[4][12] =
   {
    { 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1 }
   };




   public:
        CodeWord();
        void generate(vector<int> binary, vector<int>& result);
        void decode(vector<int>& codeWord);
        void removeParityBits(vector<int>& from, vector<int>& to);

};

#endif // CODEWORD_H
