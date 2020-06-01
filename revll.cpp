#include<iostream>
using namespace std;


class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};


// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here
    if(head == NULL || head->next==NULL){
        return head;
    }
    node* a=head,*b=head->next,*c;
    head->next = NULL;
    while(b!=NULL){
        c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
    cout<<endl;
    return a;
}



node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node*head=takeinput();
    print(head);
    cout<<endl;
    head = rev_linkedlist_itr(head);
    print(head);
    return 0;
}
