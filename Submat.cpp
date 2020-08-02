#include <iostream>
#include <fstream>
#include <algorithm>
 
using namespace std;
 
ifstream fin("submat.in");
ofstream fout("submat.out");
 
int n, m;
int fr[1005];
 
 
void citire()
{
    int x;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            fin >> x;
            if(x == 0)
            {
                fr[i]++;
            }
        }
    }
    sort(fr+1,fr+n+1,greater<int>());
}
 
void rezolva()
{
    int sol = 0, ar;
    for(int i = 1; i <= n; i++)
    {
       ar = fr[i] * i;
       sol = max(ar, sol);
    }
    fout << sol;
}
 
int main()
{
    citire();
    rezolva();
    return 0;
}