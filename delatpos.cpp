#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertattail(node* &head, int val)
{
    node *n = new node(val);
    if(head==NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void deletion(node* &head, int pos)
{
    node* temp = head;
    int i=1;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    node* todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}
void display(node *head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
signed main()
{
    node *head = NULL;
    insertattail(head, 10);
    insertattail(head, 20);
    insertattail(head, 30);
    insertattail(head, 40);
    display(head);
    cout<<endl;
    deletion(head, 2);
    display(head);
    return 0;
}