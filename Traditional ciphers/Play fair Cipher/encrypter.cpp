#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define opt()                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

vector<vector<int>> key = {
    {11, 6, 3, 1, 0},
    {16, 12, 7, 4, 2},
    {20, 17, 13, 8, 5},
    {23, 21, 18, 14, 10},
    {25, 24, 22, 19, 15}};

pair<int,int>see(int c)
{
    if(c==9)
    {
        return{2,3};
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
           if(key[i][j]==c)
           {
             return{i,j};
           }
        }
    }
    return{-1,-1};
}

pair<int,int>encrypt(int c1,int c2)
{
    pair<int,int>res;
    pair<int,int>pos1=see(c1);
    pair<int,int>pos2=see(c2);
    if(pos1.first==pos2.first)
    {
       res.first=key[pos1.first][(pos1.second+1)%5];
       res.second=key[pos2.first][(pos2.second+1)%5];
    }
    else if(pos1.second==pos2.second)
    {
        res.first=key[(pos1.first+1)%5][pos1.second];
        res.second=key[(pos2.first+1)%5][pos2.second];
    }
    else
    {
        res.first=key[pos1.first][pos2.second];
        res.second=key[pos2.first][pos1.second];
    }
    return res;
}

vector<char> playfair(vector<char> p)
{
    vector<char> c;
    int n = p.size();
    if (n % 2 != 0)
    {
        p.push_back('x');
    }
    for (int i = 0; i < n; i = i + 2)
    {
        int f1 = 0,f2=0;
        int c1 = p[i], c2 = p[i + 1];
        if (c1 < 90)
        {
            c1 = c1 - 65;
        }
        else
        {
            c1 = c1 - 97;
            f1 = 1;
        }
        if (c2 < 90)
        {
            c2 = c2 - 65;
        }
        else
        {
            c2 = c2 - 97;
            f2 = 1;
        }
        pair<int,int>res=encrypt(c1,c2);
        c1=res.first,c2=res.second;
        f1==1?(c1=c1+97):(c1=c1+65);
        f2==1?(c2=c2+97):(c2=c2+65);
        c.push_back(c1);
        c.push_back(c2);
    }
    return c;
}

int main()
{
    opt();
    vector<char> p;
    ifstream inFile("plain.txt");
    char ch, prev = '1';
    while (inFile.get(ch))
    {
        if (ch != ' ')
        {
            if (ch == prev)
            {
                p.push_back('x');
            }
            p.push_back(ch);
            prev = ch;
        }
    }
    inFile.close();
    vector<char> c;
    c = playfair(p);
    int n=c.size();

    ofstream outFile("cipher.txt");
    for(int i=0;i<n;i++)
    {
        outFile.put(c[i]);
    }

}