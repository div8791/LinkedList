#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertathead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    if(head!=NULL)
    {
        head -> prev = n;
    }
    head = n;
}
void insertatail(node* &head, int val)
{
    if(head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void deleteathead(node* &head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node* &head, int pos)
{
    if(pos==1)
    {
        deleteathead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp!=NULL && count!=pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;

}
void display(node* head)
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
    node* head = NULL;
    insertatail(head, 10);
    insertatail(head, 20);
    insertatail(head, 30);
    insertatail(head, 40);
    display(head);
    cout<<endl;
    deletion(head,4);
    display(head);
    return 0;
}