#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class File
{
    private:
      fstream file;

    public:
        ~File();
        int openFile(string name, bool flushMode);
        void readFromFile(vector<string>& textFromFile);
        void saveToFile(int size, vector<int>& result, int lineLength);
};

#endif // FILE_H
