#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;


/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node *head = NULL;
    Node *temp1=head1,*temp2=head2;
    Node * temp = NULL;
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





Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

