#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("cartele.in");
ofstream fout("cartele.out");
 
int n, c;
int sablon[55][55], cartela[55][55], aux[55][55];
 
void intoarce(int cartelaverif[55][55])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            aux[n-i+1][j] = cartelaverif[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cartelaverif[i][j] = aux[i][j];
        }
    }
}
 
void roteste(int cartelaverif[55][55])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            aux[j][n-i+1] = cartelaverif[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cartelaverif[i][j] = aux[i][j];
        }
    }
}
 
bool verificare(int cartelaverif[55][55])
{
    bool ok;
    for(int k = 1; k <= 4; k++)
    {
        ok = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(cartelaverif[i][j] != sablon[i][j])
                {
                    ok = false;
                }
            }
        }
        if(ok)
        {
            return true;
        }
        else
        {
            roteste(cartelaverif);
        }
    }
    return false;
}
 
void rezolva()
{
    fin >> n >> c;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            fin >> sablon[i][j];
        }
    }
    while(c--)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                fin >> cartela[i][j];
            }
        }
        if(verificare(cartela))
        {
            fout << 1 << "\n";
        }
        else
        {
            intoarce(cartela);
            if(verificare(cartela))
            {
                fout << 1 << "\n";
            }
            else
            {
                fout << 0 << "\n";
 
            }
        }
    }
}
 
int main()
{
    rezolva();
    return 0;
}