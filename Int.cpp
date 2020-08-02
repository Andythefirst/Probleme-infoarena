#include <iostream>
#include <fstream>
#include <algorithm>
 
using namespace std;
 
ifstream fin("int.in");
ofstream fout("int.out");
 
const int NMAX = 50005;
int n;
 
struct Interval{
   int st, dr;
};
 
bool Compara(const Interval A, const Interval B)
{
    return A.dr < B.dr;
}
 
Interval t[NMAX];
 
void citire()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> t[i].st >> t[i].dr;
    }
}
 
void solve()
{
    sort(t+1,t+n+1,Compara);
    int cnt = 1, dreapta = t[1].dr;
    for(int i = 2; i <= n; i++)
    {
        if(t[i].st >= dreapta)
        {
            cnt++;
            dreapta = t[i].dr;
        }
    }
    fout << cnt << "\n";
}
 
int main()
{
    citire();
    solve();
    return 0;
}