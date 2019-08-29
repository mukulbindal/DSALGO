/*
Author: Mukul Bindal
Time :: 20:27 29-08-2019
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*input part*/
    list<int> l;
    int i,d,n;
    cin>>n;
    for(i = 0;i<n;i++)
    {
        cin>>d;
        l.push_back(d);
    }
    /*-------------*/
    list<int> :: iterator slow,fast;
    slow = l.begin();
    fast = l.begin();
    while(fast!=l.end() && fast!= (--l.end()))
    {
        slow++;
        ++fast;
        ++fast;
        cout<<*slow<<" "<<*fast<<endl;
    }
    cout<<(*slow)<<endl;
}
