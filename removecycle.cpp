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
void makecycle(node* &head, int pos)
{
    node* temp = head;
    node *startnode;
    int c = 1;
    while(temp->next!=NULL)
    {
        if(c==pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        c++;
    }
    temp->next = startnode;
}
void removecycle(node* &head)
{
    node* fast = head;
    node* slow = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast = head;
    while(slow->next!=fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
bool detectcycle(node* &head)
{
    node *slow = head;
    node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
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
    create(head,10);
    create(head,20);
    create(head,30);
    create(head,40);
    create(head,50);
    create(head,60);
    makecycle(head,3);
    //display(head);
    cout<<detectcycle(head)<<endl;
    removecycle(head);
    cout<<detectcycle(head)<<endl;
    return 0;
}