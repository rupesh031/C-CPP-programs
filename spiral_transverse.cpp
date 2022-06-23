#include <iostream>
using namespace std;
int main(){
    
    int arr[4][3]={{4,5,6},{8,9,10},{9,5,13},{1,2,3}};
    int upper,lower,right,left;
    upper=0;
    lower=3;
    left=0;
    right=2;
    int i=0,j=0,f=1;
    while(left<=right && lower>=upper)
    {
        if(f==1)
        {
            if(j<=right)
            {
                cout<<arr[i][j]<<" ";
                j+=1;
            }
            else
            {
                j--;
                i++;
                f=2;
                right-=1;
            }
            
        }
        if(f==-1)
        {
            if(j>=left)
            {
                cout<<arr[i][j]<<" ";
                j-=1;

            }
            else
            {
                f=-2;
                j++;
                i-=1;
                left+=1;
            }
        }
        if (f==2)
        {
            if(i<=lower)
            {
                
                cout<<arr[i][j]<<" ";     
                i+=1;
            }
            else
            {
                f=-1;
                j-=1;
                i--;
                lower-=1;
            }
        }
        if (f==-2)
        {
            if(i>upper)
            {
                cout<<arr[i][j]<<" ";
                i-=1;
            }
            else
            {
                f=1;
                j+=1;
                i+=1;
                upper+=1;
            }
        }

        
        
    }
    
    return 0;


}