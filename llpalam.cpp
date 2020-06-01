//Check if a linked list is a palindrome
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


//head is the head of you linked list
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


node* revll(node*head){
    node *a,*b,*c;
    b = head->next;
    c = head;
    while(b!=NULL){
        a = b;
        b = b->next;
        a->next = c;
        c = a;
    }
    head ->next = NULL;
    return a;

}


bool check_palindrome(node* head)
{
    //write your code here
    int count = 0;
    node * temp = head;
    while(temp!=0){
        temp = temp->next;
        count++;
    }
    int mid = count/2;
    node *a = head;
    for(int i=0;i<mid-1;i++){
        a=a->next;
    }
    node *b = a->next;
    a->next = NULL;
    a = b;
    if(count%2 == 1){
        a = a->next;
    }
    node *head2 = revll(a);
    while(head != NULL && head2 != NULL){
        if(head->data != head2->data){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
    

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

int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}
