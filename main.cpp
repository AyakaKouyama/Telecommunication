#include <iostream>
#include <conio.h>
#include "CodeWord.h"
#include "Print.h"
#include "File.h"
#include <ctime>

using namespace std;

template<typename T> void printVector(vector<T> v)
{
    for(unsigned int i = 0; i< v.size(); i++)
    {
        cout<<v[i];
    }
}

void SingleRandomError(vector<int>& text, vector<int>& text2)
{
    for(int j = 0;  j<text.size(); j+=12)
    {

        int r = rand()%12 + j;
        text[r] = 0 ? 1 : 0;
        text2[r] = 0 ? 1 : 0;
    }
}
void DoubleRandomError(vector<int>& text, vector<int>& text2)
{
    for(int j = 0;  j<text.size(); j+=16)
    {
        int r = rand()%16 + j;
        text[r] = 0 ? 1 : 0;
        text2[r] = 0 ? 1 : 0;

        int r2 = rand()%16 + j;
        text[r2] = 0 ? 1 : 0;
        text2[r2] = 0 ? 1 : 0;
    }
}
int main()
{
    srand(time(0));
    vector<int> binary, result, binaryCodeFromFile, to, test, finalResult;
    vector<string> textFromFile, codeFromFile, tests;
    vector<char> finalText, finalTextDecoded;
    int mode, errorMode;
    File dataFile, codeFile, codeFile2, codeFile3;
    Convert converter;

    if(dataFile.openFile("dane.txt", false) ==0)
    {
        cout<<"Blad otwarcia pliku"<<endl;
        return 0;
    }

    do
    {
        cout<<"__________________________________"<<endl;
        cout<<"Wybierz tryb: \n 1. Korekcja pojedynczego bledu \n 2. Korekcja podwojnego bledu\n";
        cout<<"__________________________________"<<endl;
        cin>>mode;
        system("cls");
    }while(mode < 1 || mode >2);

    do
    {
        cout<<"__________________________________"<<endl;
        cout<<"Wybierz tryb: \n 1. Reczna zmiana kodu w pliku \n 2. Bledy generowane losowo\n";
        cout<<"__________________________________"<<endl;
        cin>>errorMode;
        system("cls");
    }while(mode < 1 || mode >2);


    CodeWord code(mode);
    dataFile.readFromFile(textFromFile);
    for(unsigned int i = 0; i<textFromFile.size(); i++)
    {
        converter.stringToBinary(binary, textFromFile[i]);
        code.generate(binary, result);
    }

    codeFile.openFile("kod.txt", true);
    if(mode == 1)
    {
      codeFile.saveToFile(result.size(), result, 12);
    }
    else
    {
       codeFile.saveToFile(result.size(), result, 16);
    }
    codeFile.~File();


    cout<<"Pomyslnie zapisano kod do pliku."<<endl;
    if(errorMode == 1)
    {
      cout<<"Dokonaj zmian w pliku, a nastepnie nacisnij dowolny klawisz, aby kontynuowac..."<<endl;
      getch();
    }

    codeFile2.openFile("kod.txt", false);
    codeFile3.openFile("kod.txt", false);

    codeFile2.readFromFile(codeFromFile);
    codeFile3.readFromFile(tests);

    converter.BinaryFromFileToString(codeFromFile, binaryCodeFromFile);
    converter.BinaryFromFileToString(tests, test);

    if(errorMode == 2)
    {
        if(mode == 1)
        {
            SingleRandomError(test, binaryCodeFromFile);
        }
        else if(mode == 2)
        {
            DoubleRandomError(test, binaryCodeFromFile);
        }
    }

    code.removeParityBits(test, to);
    converter.binaryToString(to, finalText);
    code.decode(binaryCodeFromFile);
    code.removeParityBits(binaryCodeFromFile, finalResult);
    converter.binaryToString(finalResult, finalTextDecoded);

    cout<<"\nZawartosc pliku przed korekcja bledow:"<<endl;
    printVector(finalText);
    cout<<endl;
    cout<<"\nKod po korekcji bledow:"<<endl;
    printVector(finalTextDecoded);
    cout<<endl;

    cout<<"\nNacisnij dowolny klawisz, aby zakonczyc...";
    getch();

    return 0;
}
