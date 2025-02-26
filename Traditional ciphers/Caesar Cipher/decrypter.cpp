#include <bits/stdc++.h>
#include<fstream>
using namespace std;

#define opt()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int key=15;
int k=26-key;
char ceaser(char c)
{
    int x=c,flag=0;;
    if(x<=90)
    {
      x-=65;
    }
    else
    {
      x-=97;
      flag=1;
    }
    x=x+k;
    x=x%26;
    if(flag)
    {
        x+=97;
    }
    else
    {
        x+=65;
    }
    char res=x;
    return res;
}
int main()
{
    opt();
    ifstream inFile("cipher.txt");
    ofstream outFile("plain.txt");

    char ch;
    while(inFile.get(ch))
    {
        if(ch!=' ')
        {
           outFile.put(ceaser(ch));
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}