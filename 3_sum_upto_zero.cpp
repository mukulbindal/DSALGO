/*
Author: Mukul Bindal
Time :: 21:00 29-08-2019
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*  input  */
    stack<int> stk;
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    /*------------*/
    for(i = 0;i<n;i++)
    {
        if(a[i]>=0){
            stk.push(a[i]);
        }
        else{
            int sum = 0;
            while(sum!=-a[i])
            {
                sum+=stk.top();
                stk.pop();
            }
        }
    }
    // Only those elements which were not part of any zero-sum-group are left in stack
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;

}
/*
Sample input
11
4 6 -10 8 9 10 -19 10 -18 20 25
*/
