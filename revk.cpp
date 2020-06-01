//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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

//head is the head of the linked list, n is number of elements to be reversed
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

node* rev(node*head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    node*t = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return t;
}

node* kReverse(node*head,int n){
    if(head==NULL || head->next == NULL || n<=1){
        return head;
    }
    int i = 0;
    node*temp = head;
    while(temp && (i<(n-1))){
        i++;
        temp = temp->next;
    }
    if(i<(n-1)){
        return rev(head);
    }
    if(i==n-1 && temp == NULL){
        return rev(head);
    }
    if(i == (n-1) && temp->next==NULL){
        return rev(head);
    }
    node*nextHead = temp->next;
    temp->next = NULL;
    temp = head;
    head = rev(head);
    temp->next = kReverse(nextHead , n);
    return head;
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
    head=kReverse(head,n);
    print(head);
    return 0;
}
