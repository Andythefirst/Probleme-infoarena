#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("defrag.in");
ofstream fout("defrag.out");
 
int v, p, s, c, x, y;
int mat[105][735];
 
void citire()
{
    fin >> v >> p >> s >> c;
    for(int i = 1; i <= c; i++)
    {
        fin >> x >> y;
        mat[x][y] = 1;
        mat[x][0]++;
        mat[x][y+s] = 1;
    }
}
 
void p1()
{
    int cont = 0;
    for(int i = 1; i <= p; i++)
    {
        if(mat[i][0] == 0)
        {
            cont++;
        }
    }
    fout << cont;
}
 
void p2()
{
    int lg, cont, sol;
    for(int i = 1; i <= p; i++)
    {
        lg = mat[i][0];
        cont = 0;
        for(int j = 1; j <= lg; j++)
        {
            if(mat[i][j] == 0)
            {
                cont++;
            }
        }
        sol = cont;
        for(int j = lg + 1; j <= 2 * s; j++)
        {
            if(mat[i][j] == 0)
            {
                cont++;
            }
            if(mat[i][j-lg] == 0)
            {
                cont--;
            }
            if(sol > cont)
            {
                sol = cont;
            }
        }
        fout << sol << " ";
    }
}
 
int main()
{
    citire();
    if(v == 1)
    {
        p1();
    }
    else
    {
        p2();
    }
    return 0;
}