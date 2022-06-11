#include <iostream>
using namespace std;

int mod(int x,int y)
{
    int res=1;
    int a=x;
    while (x>0)
    {
        if(x&1)
        {
            res=res*a;
        }
         a=a*a;
         x>>=1;
    }
    return res;

}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<mod(a,b);


}

