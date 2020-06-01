//bubble sort iterative
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

//head is the head of the linked list
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
node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node*temp = head , *temp1 , *prev = NULL ;
    while(temp->next){
        temp1 = head;
        prev = NULL;
        while (temp1->next){
            if(temp1->data > temp1->next->data){
                if(temp1 == head){
                    node*t = temp1->next;
                    temp1->next = t->next;
                    t->next = temp1;
                    head = t;
                    temp1 = head;
                    temp = head;
                }
                else{
                    
                    node*t = temp1->next;
                    temp1->next = t->next;
                    t->next = temp1;
                    temp1 = t;
                    prev->next = temp1;
                }
            }
            prev = temp1;
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    
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
        cout<<temp<<" "<<temp->data<<" \n";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    cout << "\t before sorting \n";
    print(head);
    head=bubble_sort_LinkedList_itr(head);
    cout << "\t after sorting \n";
    print(head);
}
