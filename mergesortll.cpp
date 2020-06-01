//merge sort recursive
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

node* mergeTwoLLs(node *head1, node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    node *head = NULL;
    node *temp1=head1,*temp2=head2;
    node * temp = NULL;
    while(temp1!= NULL || temp2 != NULL){
        if(temp1==NULL){
            if(head == NULL){
                head = temp2;
                temp2 = NULL;
            }
            else{
                temp->next = temp2;
                temp2 = NULL;
            }
        }
        else if(temp2 == NULL){
            if(head == NULL){
                head = temp1;
                temp1 = NULL;
            }
            else
            {
                temp->next = temp1;
                temp1 = NULL;
            }
        }
        else{
            if(temp1->data > temp2->data){
                if(head == NULL){
                    head = temp2;
                    temp = temp2;
                    temp2 = temp2->next;
                }
                else{
                    temp->next = temp2;
                    temp2 = temp2->next;
                    temp = temp->next;
                }
            }
            else{
                if(head == NULL){
                    head = temp1;
                    temp = head;
                    temp1 = temp1->next;
                }
                else{
                    temp->next = temp1;
                    temp1 = temp1->next;
                    temp = temp->next;
                }
            }
        }
    }
    return head;
    
}


node* mergeSort(node *head) {
    //write your code here
        if(head->next == NULL){
            return head;
        }
        else{
            node* slow = head, *fast = head;
            while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            node* head2 = slow->next;
            slow->next = NULL;
            head = mergeSort(head);
            head2 = mergeSort(head2);
            return mergeTwoLLs(head,head2);
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
    head= mergeSort(head);
    print(head);
    return 0;
}

