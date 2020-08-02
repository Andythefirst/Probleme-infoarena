#include <iostream>
#include <fstream>
#include <stack>
 
using namespace std;
 
ifstream fin("editor.in");
ofstream fout("editor.out");
 
const int NMAX = 100005;
int q, n;
char s[NMAX];
char a[NMAX];
stack <char> st;
 
void clean_S()
{
    n = 0;
    for(int i = 1; s[i] != 0; i++)
    {
        if(s[i] == '*' && n > 0)
        {
            n--;
        }
        else
        {
            a[++n] = s[i];
        }
    }
    while(!st.empty())
    {
        st.pop();
    }
}
 
bool eval()
{
 
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == '(' || a[i] == '[')
        {
            st.push(a[i]);
        }
        else if(a[i] == ')' || a[i] == ']')
        {
            if(st.empty())
            {
                return false;
            }
            if((st.top() == '(' && a[i] == ')') || (st.top() == '[' && a[i] == ']'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
 
int main()
{
    fin >> q;
    while(q--)
    {
        fin >> (s + 1);
        clean_S();
        if(eval() == true)
        {
            fout << ":)\n";
        }
        else
        {
            fout << ":(\n";
        }
    }
    return 0;
}