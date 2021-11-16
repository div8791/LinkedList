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
void insert(node* &head, int val)
{
    node *n = new node(val);
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
// node* reverse(node* &head)
// {
//     node *curr = head;
//     node *prev, *next;
//     prev = NULL; 
//     next = NULL;
//     while(curr!=NULL)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }
node* reverse(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* nhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return nhead;
}
void display(node* &head)
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
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    display(head);
    cout<<endl;
    //node *nhead = reverse(head);
    node *nhead = reverse(head);
    display(nhead);
    return 0;
}