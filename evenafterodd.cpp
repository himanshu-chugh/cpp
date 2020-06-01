//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

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


node* arrange_LinkedList(node* head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *head1=NULL,*head2=NULL , *temp1,*temp2;
    while(head!=0){
        if(head->data % 2 == 0){
            if(head1 == NULL){
                head1 = head;
                temp1 = head;
            }
            else{
                temp1->next = head;
                temp1 = head;
            }
        }
        else{
            if(head2 == NULL){
                head2 = head;
                temp2 = head;
            }
            else{
                temp2->next = head;
                temp2 = head;
            }
        }
    head = head->next;
    }
    if(head1 == 0){
        return head2;
    }
    if(head2 == 0){
        return head1;
    }
    
    temp2->next = head1;
    temp1->next = NULL;
    return head2;
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
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
