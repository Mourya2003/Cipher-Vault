#include <bits/stdc++.h>
#include<fstream>
using namespace std;

#define opt()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int k1=7,k2=2;

int extended_euclidean()
{
    int r1 = 26, r2 = k1, r, q;
    int t1 = 0, t2 = 1, t;
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - (q * r2);
        r1 = r2;
        r2 = r;
        t = t1 - (q * t2);
        t1 = t2;
        t2 = t;
    }
    if(t1<0)
    {
        t1=26+t1;
    }
    return t1;
}

char affine(char c)
{
    int x=c,flag=0;
    if(x<=90)
    {
      x-=65;
    }
    else
    {
      x-=97;
      flag=1;
    }
    x=x+(26-k2);
    x=x*extended_euclidean();
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
           outFile.put(affine(ch));
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}