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
};

#endif // PRINT_H
