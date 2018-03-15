#include "File.h"

File::~File()
{
    file.close();
}

int File::openFile(string name)
{
    file.open(name, ios::in|ios::out);

    if(file.is_open() == false)
    {
        return 0;
    }
    return 1;

}
void File::readFromFile(vector<string>& textFromFile)
{
    int i = 0;
    string line;
    while(!file.eof())
    {
        getline(file, line);
        textFromFile.push_back(line);
    }
}



void File::saveToFile(int size, vector<int>& result)
{
    int endLine = 0;
    for(int i = 0; i<size; i++)
    {
        file<<result[i];
        endLine++;
        if(endLine == 12)
        {
            file<<endl;
            endLine = 0;
        }
    }
}

