//Append the last n elements of a linked list to the front
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


//head is the head of the linked list and n is  how many element you want to append from the last to the front
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

node* append_LinkedList(node* head,int n)
{
    //write your code here
    node *lastAddress = NULL, *temp = head , *listLast = NULL;
    while(temp != NULL){
        if(temp->data == n){
            lastAddress = temp;
            //cout<< temp->data <<" " << temp << endl; 
        }
        listLast = temp;
        temp = temp->next;
    }
    
    if(lastAddress == NULL){
        return head;
    }
    else if(lastAddress == head){
        return  head;
    }
    else{
        temp = head;
        listLast->next = temp;
        node *help = temp;
        while(temp != lastAddress){
            help = temp;
            temp = temp->next;
        }
        help->next = NULL;
        return lastAddress;
    }
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
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
