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
node *reversek(node* &head, int k)
{
    node* prev = NULL;
    node* curr = head;
    node* next;
    int c=0;
    while(curr!=NULL && c<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    if(next!=NULL)
    {
        head->next = reversek(next,k);
    }
    return prev;
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
    create(head,1);
    create(head,2);
    create(head,3);
    create(head,4);
    create(head,5);
    create(head,6);
    node* newhead = reversek(head, 2);
    display(newhead);
    return 0;
}