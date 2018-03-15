#include <iostream>
#include "CodeWord.h"
#include "Print.h"
#include "File.h"
using namespace std;

int vectorLength(vector<string> v)
{
    int counter = 0;
    for(int i = 0; i<v.size(); i++)
    {
        counter += v[i].length();
    }
    return counter;
}
int main()
{
    vector<int> binary;
    vector<int> result;
    vector<string> textFromFile;
    File dataFile;
    if(dataFile.openFile("dane.txt") ==0)
    {
        cout<<"Blad otwarcia pliku"<<endl;
        return 0;
    }
    dataFile.readFromFile(textFromFile);
    Convert converter(vectorLength(textFromFile));
    CodeWord code;

    for(int i = 0; i<textFromFile.size(); i++)
    {
        converter.stringToBinary(binary, textFromFile[i]);
        code.generate(binary, result);
    }

    int answer;
    cout<<"Co chcesz zrobiæ?\n 1. Zapisz kod do pliku. \n 2. Dekoduj dane z pliku\n";
    cin>>answer;
    switch(answer)
    {
    case 1:
        {
            File codeFile;
            codeFile.openFile("kod.txt");
            codeFile.saveToFile(result.size(), result);
            break;
        }
    case 2:
        {
            File codeFile2;
            codeFile2.openFile("kod.txt");
            File codeFile3;
            codeFile3.openFile("kod.txt");
            vector<string> codeFromFile;
            vector<int>  binaryCodeFromFile;
            vector<string> tests;
            vector<int> test;


            codeFile2.readFromFile(codeFromFile);
            codeFile3.readFromFile(tests);

            for(int i = 0; i<codeFromFile.size(); i++)
            {
                string current = codeFromFile[i];
                for(int j = 0; j<current.length(); j++)
                {
                 binaryCodeFromFile.push_back(current[j] - '0');
                }
            }

             for(int i = 0; i<tests.size(); i++)
            {
                string current = tests[i];
                for(int j = 0; j<current.length(); j++)
                {
                 test.push_back(current[j] - '0');
                }
            }
            vector<int> to;
            vector<char> czary_mary;
            code.removeParityBits(test, to);
            converter.binaryToString(to, czary_mary);
            for(int i = 0;i <czary_mary.size(); i++)
            {
                cout<<czary_mary[i];
            }

            cout<<endl;
            code.decode(binaryCodeFromFile);
            vector<char> bToS2;
            vector<int> finalResult;

            code.removeParityBits(binaryCodeFromFile, finalResult);


            converter.binaryToString(finalResult, bToS2);
            for(int i = 0; i<bToS2.size(); i++)
            {
                cout<<bToS2[i];
            }
            break;
        }
    default:
        {
            cout<<"Brak poprawnej odpowiedzi";
            return 0;
        }
    }

    return 0;
}
