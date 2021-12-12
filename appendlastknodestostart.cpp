#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void create(node* &head, int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
int length(node* &head)
{
    int l = 0;
    node* temp = head;
    while(temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
node* kappend(node* &head, int k)
{
    node* newhead;
    node* newtail;
    node* tail = head;
    int l = length(head);
    k = k%l;
    int c = 1;
    while(tail->next!=NULL)
    {
        if(c == l-k)
        {
            newtail = tail;
        }
        if(c == l-k+1)
        {
            newhead = tail;
        }
        tail = tail->next;
        c++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
void display(node* head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
signed main()
{
    node *head = NULL;
    create(head, 10);
    create(head, 20);
    create(head, 30);
    create(head, 40);
    create(head, 50);
    create(head, 60);
    display(head);
    cout<<endl;
    node *nhead = kappend(head,4);
    display(nhead);
    return 0;
}