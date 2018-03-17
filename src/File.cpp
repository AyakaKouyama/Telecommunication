#include "File.h"

File::~File()
{
    file.close();
}

int File::openFile(string name, bool flushMode)
{
    if(flushMode == false)
    {
      file.open(name, ios::in|ios::out);
    }
    else
    {
       file.open(name, ios::in|ios::out|ios::trunc);
    }

    if(file.is_open() == false)
    {
        return 0;
    }
    return 1;

}
void File::readFromFile(vector<string>& textFromFile)
{
    string line;
    while(!file.eof())
    {
        getline(file, line);
        textFromFile.push_back(line);
    }
}



void File::saveToFile(int size, vector<int>& result, int lineLength)
{
    int endLine = 0;
    for(int i = 0; i<size; i++)
    {
        file<<result[i];
        endLine++;
        if(endLine == lineLength)
        {
            file<<endl;
            endLine = 0;
        }
    }
}

