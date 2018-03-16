#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "CodeWord.h"
#include "Print.h"
#include "File.h"
using namespace std;

template<typename T> void printVector(vector<T> v)
{
    for(int i = 0; i< v.size(); i++)
    {
        cout<<v[i];
    }
}

void randomError(vector<int>& text, vector<int>& text2)
{
    for(int j = 0;  j<text.size(); j+=16)
    {
        int r = rand()%(16-1) + j;
        if(text[r] == 0)
        {
            text[r] = 1;
            text2[r] = 1;
        }

        else
        {text[r] = 0;
        text2[r] = 0;
        }

        int r2 = rand()%(16-1) + j;
        if(text[r2] == 0)
        {
            text[r2] = 1;
            text2[r2] = 1;
        }

        else
        {
            text[r2] = 0;
            text2[r2] = 0;
        }


    }
}

int main()
{
    srand(time(0));
    vector<int> binary;
    vector<int> result;
    vector<string> textFromFile;
    int mode, answer;
    File dataFile;
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


    CodeWord code(mode);
    system("cls");

    dataFile.readFromFile(textFromFile);
    for(int i = 0; i<textFromFile.size(); i++)
    {
        converter.stringToBinary(binary, textFromFile[i]);
        code.generate(binary, result);
    }

    do
    {
        cout<<"__________________________________"<<endl;
        cout<<"Co chcesz zrobic?\n 1. Zapisz kod do pliku \n 2. Dekoduj dane z pliku\n";
        cout<<"__________________________________"<<endl;
        cin>>answer;
        system("cls");
    }while(answer < 1 || answer > 2);


    switch(answer)
    {
    case 1:
        {
            File codeFile;
            codeFile.openFile("kod.txt", true);
            if(mode == 1)
            {
              codeFile.saveToFile(result.size(), result, 12);
            }
            else
            {
               codeFile.saveToFile(result.size(), result, 16);
            }

            cout<<"Pomyslnie zapisano kod do pliku."<<endl;
            break;
        }
    case 2:
        {
            vector<string> codeFromFile;
            vector<int>  binaryCodeFromFile;
            vector<string> tests;
            vector<int> test;

            File codeFile2;
            codeFile2.openFile("kod.txt", false);
            File codeFile3;
            codeFile3.openFile("kod.txt", false);


            codeFile2.readFromFile(codeFromFile);
            codeFile3.readFromFile(tests);
            converter.BinaryFromFileToString(codeFromFile, binaryCodeFromFile);
            converter.BinaryFromFileToString(tests, test);
            randomError(test, binaryCodeFromFile);

            vector<int> to;
            vector<char> czary_mary;
            code.removeParityBits(test, to);
            converter.binaryToString(to, czary_mary);

            cout<<"\nZawartosc pliku przed korekcja bledow:"<<endl;
            printVector(czary_mary);
            cout<<endl;

            code.decode(binaryCodeFromFile);
            vector<char> bToS2;
            vector<int> finalResult;
            code.removeParityBits(binaryCodeFromFile, finalResult);
            converter.binaryToString(finalResult, bToS2);

            cout<<"Kod po korekcji bledow:"<<endl;
            printVector(bToS2);
            cout<<endl;


            break;
        }
    default:
        {
            cout<<"Brak poprawnej odpowiedzi";
            return 0;
        }
    }

    cout<<"\nNacisnij dowolny klawisz, aby zakonczyc...";
    getch();
    return 0;
}
