#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("cool.in");
ofstream fout("cool.out");
 
const int NMAX = 5005;
 
int p, n, k;
int a[NMAX], fr[NMAX];
 
void citire()
{
    fin >> p >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
}
 
void cerinta1()
{
    int nrdistincte = 0;
    bool ok = false;
    for(int i = 1; i <= k; i++)
    {
        fr[a[i]]++;
    }
    int i = 1, cont = 0;
    while(fr[i] == 0)
    {
        i++;
    }
    while(fr[i] == 1)
    {
        i++;
        cont++;
    }
    if(cont == k)
    {
        fout << i - 1 << "\n";
    }
    else
    {
        for(int i = 1; i <= 1000; i++)
        {
            if(fr[i] == 1)
            {
                nrdistincte++;
            }
        }
        fout << nrdistincte << "\n";
    }
}
 
void cerinta2()
{
    int maxx, minn, lgmax = 0, nrsecv = 0;
    bool ok;
    for(int i = 1; i <= n; i++)
    {
        maxx = a[i];
        minn = a[i];
        for(k = 1; k <= 1000; k++)
        {
            fr[k] = 0;
        }
        ok = true;
        for(int j = i; j <= n && ok == true; j++)
        {
            if(fr[a[j]])
            {
                ok = false;
            }
            else
            {
                fr[a[j]]++;
                maxx = max(maxx, a[j]);
                minn = min(minn, a[j]);
                if(maxx - minn == j - i)
                {
                    if(j - i + 1 > lgmax)
                    {
                        lgmax = j - i + 1;
                        nrsecv = 1;
                    }
                    else if(j - i + 1 == lgmax)
                    {
                        nrsecv++;
                    }
                }
            }
        }
    }
    fout << lgmax << "\n" << nrsecv << "\n";
}
 
int main()
{
    citire();
    if(p == 1)
    {
        cerinta1();
    }
    else
    {
        cerinta2();
    }
    return 0;
}