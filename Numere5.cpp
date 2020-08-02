#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("numere5.in");
ofstream fout("numere5.out");
 
int n;
bool fr[1000005];
 
void citire()
{
    int x;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            fin >> x;
            fr[x] = true;
        }
    }
}
 
void rezolva()
{
    for(int i = 1; i <= 500000; i++)
    {
        if(!fr[i])
        {
            fout << i << " ";
            break;
        }
    }
    for(int i = min(500000, n*n); i >= 1; i--)
    {
        if(!fr[i])
        {
            fout << i << "\n";
            break;
        }
    }
}
 
int main()
{
    citire();
    rezolva();
    return 0;
}