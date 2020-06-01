#include <iostream>
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


node* deletenn(node*head , int n){
    if(!head){
        return head;
    }
    node*temp = head , *temp1;
    while (temp && n--)
    {
        temp1 = temp;
        temp = temp->next;
        delete temp1;
    }
    return temp;
    
}

int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    print(head);
    cout << endl;
    head= deletenn(head , n);
    print(head);
    return 0;
}
