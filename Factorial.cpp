#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("fact.in");
ofstream fout("fact.out");
 
int p;
 
int nrz(int x)
{
    int s = 0;
    while(x)
    {
        s += x / 5;
        x /= 5;
    }
    return s;
}
 
int main()
{
    int st = 1, dr = 2000000000, mij, sol = -1, nr;
    fin >> p;
    while(st <= dr)
    {
        mij = (st + dr) / 2;
        nr = nrz(mij);
        if(nr < p)
        {
            st = mij + 1;
        }
        else if(nr > p)
        {
            dr = mij - 1;
        }
        else
        {
            sol = mij;
            dr = mij - 1;
        }
    }
    fout << sol;
    return 0;
}