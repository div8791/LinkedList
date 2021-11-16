#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void inserattail(node *&head, int val)
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
void insertathead(node* &head, int val)
{
   node *n  = new node(val);
   n->next = head;
   head = n;
}   
void insertatpos(node* &head, int val, int pos)
{
   int i=1;
   node *n = new node(val);
   n->next = NULL;
   node *temp = head;
   while(i<pos-1)
   {
       temp = temp->next;
       i++;
   }
   n->next = temp->next;
   temp->next = n;
}
bool search(node* head, int key)
{
    node *temp = head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void deletionathead(node *head)
{
    if(head==NULL)
    {
        return;
    }
    node *todel = head;
    head = head->next;
    delete todel;
}
void deletion(node* &head, int val)
{
    
    if(head->next==NULL)
    {
        deletionathead(head);
        return;
    }
    node *temp = head;
    while(temp->next->data!=val)
    {
        temp = temp->next;
    }
    node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}
void display(node *head)
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
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        inserattail(head,x);
    }
    insertathead(head, 70);
    
    display(head);
    cout<<endl;
    insertatpos(head, 60, 4);
    display(head);
    cout<<endl;
    cout<< search(head, 70);
    deletion(head, 60);
    deletionathead(head);
    cout<<endl;
    display(head);
    return 0;
}