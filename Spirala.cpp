#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("spirala.in");
ofstream fout("spirala.out");
 
const int NMAX = 105;
int n, m;
int a[NMAX][NMAX];
bool blocat[NMAX][NMAX];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int v[NMAX * NMAX];
 
void citire()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            fin >> a[i][j];
        }
    }
}
 
void bordare()
{
    for(int i = 0; i <= n + 1; i++)
    {
        blocat[i][0] = 1;
        blocat[i][m+1] = 1;
    }
    for(int j = 0; j <= m + 1; j++)
    {
        blocat[0][j] = 1;
        blocat[n+1][j] = 1;
    }
}
 
void avanseaza(int &x, int &y, int dir)
{
    x += dx[dir];
    y += dy[dir];
}
 
void parcurge()
{
    int x = 1, y = 1, dir = 0;
    for(int i = 1; i <= n * m; i++)
    {
        v[i] = a[x][y];
        blocat[x][y] = 1;
        if(blocat[x+dx[dir]][y+dy[dir]])
        {
            dir = (dir + 1) % 4;
        }
        avanseaza(x,y,dir);
    }
}
 
void progresie()
{
    int x = 0, r = v[2] - v[1];
    bool ok = false;
    for(int i = 2; i < n * m && !ok; i++)
    {
        x = v[i+1] - v[i];
        if(x != r)
        {
            fout << "NU\n";
            fout << v[i] << " " << v[i+1] << "\n";
            ok = true;
        }
    }
    if(!ok)
    {
        fout << "DA\n";
        fout << v[n * m] << "\n";
    }
}
 
int main()
{
    citire();
    bordare();
    parcurge();
    progresie();
    return 0;
}