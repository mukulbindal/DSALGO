/*
Author: Mukul Bindal
Time :: 20:27 29-08-2019
*/
#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *down , *right;
};
struct node* create(int data)
{
    struct node* temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->right = NULL;
    temp->down = NULL;
}
node * mergelist(node * head)
{
    node *a , *b , *c , *cur;
    c = NULL;
    a = head;
    b = head->right;
    while(a&&b)
    {
        if(a->data<=b->data)
        {
            c = a;
            a = a->down;
        }
        else
        {
            if(c==NULL)
            {
                int t = a->data;
                a->data = b->data;
                b->data = t;
                continue;
            }
            cur = b;
            b=b->down;
            cur->down = a;
            c->down = cur;

        }
    }
    if(a==NULL)
    {
        c->down = b;
    }
    head->right = head->right->right;
    return head;
}
int main()
{
    struct node *head , *temp , *th , *th2;
    //temp = create(4);
    head = th = th2=NULL;
    int i , n , m , d;
    cout<<"Enter Number of horizontal nodes";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter vertical nodes number";
        cin>>m;
        for(int j = 0;j<m;j++)
        {

            //cout<<"enter::";
            cin>>d;

            temp = create(d);
            if(th == NULL)
            {
                th= temp;
                if(head==NULL)
                {head= th;th2 = th;}
                else{
                    th2->right = th;
                    th2 = th2->right;

                    }
                continue;
            }

            th->down = temp;

            th = temp;
        }

        th = NULL;


    }

    cout<<"list created successfully...\n";
    cout<<"merging nodes...\n";
    while(head->right!=NULL)
    {
        head = mergelist(head);
    }
    cout<<"nodes merged successfully\nprinting nodes....\n";
    while(head)
    {
        cout<<head->data<<" ";
        head = head->down;
    }
    cout<<"done!\n";
}
/*
sample input
3
6
5 7 8 10 20 30
3
19 22 50
2
28 35

*/
