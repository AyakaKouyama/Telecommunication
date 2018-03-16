#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <vector>
using namespace std;

class Convert
{

public:
    void printBinaryMessage(vector<int>& binary, int size);
    void binaryToString(vector<int>& binary, vector<char>& strings);
    void stringToBinary(vector<int>& binary, string message);
    void BinaryFromFileToString(vector<string>& codeFromFile, vector<int>& binaryCodeFromFile);
    //int getBinary(unsigned int i) { return binary[i];}
    //int getBinarySize() {return binary.size();}
};

#endif // PRINT_H
