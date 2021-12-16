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
node* merge(node* &head1, node* &head2)
{
    node* p1 = head1;
    node* p2 = head2;
    node* dummynode = new node(-1);
    node* p3 = dummynode;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1!=NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummynode->next;
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
    node *head1 = NULL;
    node *head2 = NULL;
    create(head1,1);
    create(head1,2);
    create(head1,4);
    create(head1,7);
    create(head2,3);
    create(head2,6);
    node* newh = merge(head1, head2);
    display(newh);
    return 0;
}