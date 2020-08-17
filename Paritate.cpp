#include <iostream>
#include <fstream>
#include <cstring>
 
using namespace std;
 
ifstream fin("paritate.in");
ofstream fout("paritate.out");
 
char s[8*60005];
int n;
 
void citire()
{
    fin >> s;
    n = strlen(s);
}
///0   1  0  1  0 0 0 0
///128 64 32 16 8 4 2 1
int getCode(int poz)
{
    int cont = 0, sol = 0, p2 = 1;
    for(int i = poz + 1; i <= poz + 7; i++)
    {
        if(s[i] == '1')
        {
            cont++;
        }
    }
    if((s[poz] == '0' && cont % 2 == 1) || (s[poz] == '1' && cont % 2 == 0))
    {
        return -1;
    }
    for(int i = poz + 7; i > poz; i--)
    {
       if(s[i] == '1')
       {
           sol += p2;
       }
       p2 *= 2;
    }
    return sol;
}
 
void solve()
{
    int ok = 1;
    for(int i = 0; i < n; i += 8)
    {
        if(getCode(i) == -1)
        {
            ok = 0;
        }
    }
    if(ok == 0)
    {
        fout << "NU\n";
        for(int i = 0; i < n; i += 8)
        {
            if(getCode(i) == -1)
            {
                fout << i / 8 << " ";
            }
        }
    }
    if(ok == 1)
    {
        fout << "DA\n";
        for(int i = 0; i < n; i += 8)
        {
            fout << (char)getCode(i);
        }
    }
}
 
int main()
{
    citire();
    solve();
    return 0;
}