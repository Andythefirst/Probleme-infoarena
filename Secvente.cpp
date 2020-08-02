#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("secvente.in");
ofstream fout("secvente.out");
 
int n;
 
void rezolva()
{
    int x, s = 0;
    bool rest1 = false;
    bool rest2 = false;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> x;
        s = s + x % 3;
        if(x % 3 == 1)
        {
            rest1 = true;
        }
        if(x % 3 == 2)
        {
            rest2 = true;
        }
    }
    if(s % 3 == 0)
    {
        fout << n << "\n";
    }
    else if(s % 3 == 1)
    {
        if(rest1 == true)
        {
            fout << n - 1 << "\n";
        }
        else
        {
            fout << n - 2 << "\n";
        }
    }
    else
    {
        if(rest2 == true)
        {
            fout << n - 1 << "\n";
        }
        else
        {
            fout << n - 2 << "\n";
        }
    }
}
 
int main()
{
    rezolva();
    rezolva();
    rezolva();
    return 0;
}
