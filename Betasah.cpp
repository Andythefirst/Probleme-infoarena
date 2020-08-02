#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("betasah.in");
ofstream fout("betasah.out");
 
const int NMAX = 1005;
int a[NMAX][NMAX];
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int n, d, k;
///0 = liber
///1 = patrat gri
///2 = dama
///3 = accesibil
struct dama
{
    int x, y;
};
 
dama D[NMAX];
 
void citire()
{
    int x, y;
    fin >> n >> d >> k;
    for(int i = 1; i <= d; i++)
    {
        fin >> D[i].x >> D[i].y;
        a[D[i].x][D[i].y] = 2;
    }
    for(int i = 1; i <= k; i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
    }
}
 
void cerinta1()
{
    int cont, sol = 0;
    for(int i = 1; i <= n; i++)
    {
        cont = 0;
        for(int j = 1; j <= i; j++)
        {
            if(a[i][j] == 0 || a[i][j] == 2)
            {
                cont++;
            }
        }
        if(sol < cont)
        {
            sol = cont;
        }
    }
    fout << sol << "\n";
}
 
void bordare()
{
    for(int i = 0; i <= n+1; i++)
    {
        a[n+1][i] = 1;
        a[i][0] = 1;
        a[0][i] = 1;
        a[i][i+1] = 1;
    }
}
 
bool ok(int x, int y)
{
    return(1 <= x && x <= n && 1 <= y && y <= x && a[x][y] != 1 && a[x][y] != 2);
}
 
void cerinta2()
{
    int nra = 0;
    bordare();
    for(int i = 1; i <= d; i++)
    {
        for(int dir = 0; dir <= 8; dir++)
        {
            int x = D[i].x;
            int y = D[i].y;
            int xnext = x + dx[dir];
            int ynext = y + dy[dir];
            while(ok(xnext,ynext))
            {
                a[xnext][ynext] = 3;
                x = xnext;
                y = ynext;
                xnext = x + dx[dir];
                ynext = y + dy[dir];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(a[i][j] == 3)
            {
                nra++;
            }
        }
    }
    fout << nra << "\n";
}
 
int main()
{
    citire();
    cerinta1();
    cerinta2();
    return 0;
}