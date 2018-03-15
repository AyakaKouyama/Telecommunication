#include "Print.h"
#include <cmath>

Convert::Convert(int size)
{
    this->size = size;
}
void Convert::stringToBinary(vector<int>& binary, string message)
{
    int z = 0;

        for(unsigned int i = 0; i<message.length(); i++)
        {
            for(int j = 7; j>=0; j--, z++)
            {
               binary.push_back(message[i]&(1<<j) ? 1 : 0);
            }
        }

}

void Convert::binaryToString(vector<int>& binary, vector<char>& strings)
{
    int z = 0, sum = 0;
    for(int i = 0; i<binary.size() / 8; i++)
    {
        sum = 0;
        for(int j = 7; j>=0 ; j--, z++)
        {
            if(binary[z] == 1)
            {
              sum +=  pow(2, j);
            }
        }
        strings.push_back(sum);
    }

}

void Convert::printBinaryMessage(vector<int>& binary)
{
    int z = 0;
    for(unsigned int i = 0; i<size; i++)
    {
      for(int j = 7; j>=0; j--, z++)
      {
        cout<<binary[z];
      }
      cout<<endl;
    }

}
