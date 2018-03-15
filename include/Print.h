#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <vector>
using namespace std;

class Convert
{
private:
  ///  vector<int> binary;
    int size;
public:
    Convert(int size);
    void printBinaryMessage(vector<int>& binary);
    void binaryToString(vector<int>& binary, vector<char>& strings);
    void stringToBinary(vector<int>& binary, string message);
    //int getBinary(unsigned int i) { return binary[i];}
    //int getBinarySize() {return binary.size();}
};

#endif // PRINT_H
