#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("maxsecv.in");
ofstream fout("maxsecv.out");
 
const int NMAX = 1000005;
int n;
int a[NMAX];
 
void citire()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
}
 
void rezolva()
{
    int cont = 0, sol1 = 0, sol2 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 1)
        {
            cont++;
        }
        else
        {
            cont = 0;
        }
        if(cont > sol1)
        {
            sol1 = cont;
        }
        else if(cont > sol2)
        {
            sol2 = cont;
        }
    }
    fout << sol1 + sol2;
}
 
int main()
{
    citire();
    rezolva();
    return 0;
}