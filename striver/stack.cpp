#include<iostream>
#include<cstring>
using namespace std;
bool doing_operation(const char* c,char* s, int* top )
{   
int i=0;
while(c[i]!='\0')
 {
if(c[i]=='(')
{
    s[++(*top)] ='(';
}
else if(c[i]==')')
{
    if(*top <0 || s[*top]!='(')
    {
        return false;
    }
    (*top)--;
}
i++;
 }
 return *top ==-1;
}

int main()
{
    char stac[14];
    int top=-1;
    char s[14];
    cin.getline(stac, sizeof(s)/sizeof(stac[0]) );
    bool isBalanced = doing_operation(stac, s, &top);

    if (isBalanced && top == -1) {
        cout << "Balanced Parentheses" << endl;
    } else {
        cout << "Unbalanced Parentheses" << endl;
    }

    return 0;
}