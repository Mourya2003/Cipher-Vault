#include <bits/stdc++.h>
#include<fstream>
using namespace std;

#define opt()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int key=12;

char auto_key(char c)
{
    int temp=key;
    int x=c;
    x-=97;
    key=x;
    x=x+temp;
    x=x%26;
    x+=97;
    char res=x;
    return res;
}

int main()
{
    opt();
    ifstream inFile("plain.txt");
    ofstream outFile("cipher.txt");

    char ch;

    while(inFile.get(ch))
    {
        if(ch!=' ')
        {
           outFile.put(auto_key(ch));
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}