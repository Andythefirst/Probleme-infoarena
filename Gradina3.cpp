#include <iostream>
#include<fstream>
 
using namespace std;
 
ifstream fin("gradina3.in");
ofstream fout("gradina3.out");
 
int n, p, k, cont;
long long a[1005][1005];
long long arie, maxx = -1;
 
void citire()
{
    int x, y;
    fin >> n >> p >> k;
    for(int i = 1; i <= p; i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
    }
}
 
void rezolva()
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
        }
    }
    for(int i = k; i <= n; i++)
    {
        for(int j = k; j <= n; j++)
        {
            arie = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
            if(arie > maxx)
            {
                maxx = arie;
                cont = 1;
            }
            else if(arie == maxx)
            {
                cont++;
            }
        }
    }
    fout << maxx << "\n" << cont << "\n";
}
 
int main()
{
    citire();
    rezolva();
    return 0;
}