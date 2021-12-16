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
int intersection(node* &head1, node* &head2)
{
    int l1 = length(head1), l2 = length(head2);
    int d = 0;
    node* ptr1;
    node* ptr2;
    if(l1>l2)
    {
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l2;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d)
    {
        ptr1 = ptr1->next;
        if(ptr1==NULL)
        {
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
void intersect(node* &head1, node* &head2, int pos)
{
    node* temp1 = head1;
    pos--;
    while(pos--)
    {
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
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
    create(head1,3);
    create(head1,4);
    create(head1,5);
    create(head1,6);
    create(head2,9);
    create(head2,10);
    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;
    intersect(head1, head2, 4);
    cout<<intersection(head1, head2)<<endl;
    return 0;
}