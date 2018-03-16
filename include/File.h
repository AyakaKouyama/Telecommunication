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
  //  vector<string> textFromFile;
    public:
        ~File();
        int openFile(string name, bool flushMode);
        void readFromFile(vector<string>& textFromFile);
        void saveToFile(int size, vector<int>& result, int lineLength);

      //  int getTextFromFileSize() const { return textFromFile.size();}
      //  string getTextFromFile(unsigned int i) const {return textFromFile[i];}
      //  vector<string> getVector() {return textFromFile;}
      //  int textLength();

};

#endif // FILE_H
