#include"BST.h"
#include<iostream>
using namespace std;


int main(){
    BinarySearchTree<int> t1;
    int a[] = {15,3,6,8,2,7,17,5,432,118 ,252,19};
    /*
    t1.insert(2);
    t1.insert(1);
    t1.insert(3);
    t1.print(); */
    //cout<<t1.hasData(1);

    for(int i=0;i<12;i++){
        cout<<"entering : "<<a[i]<<endl;
        t1.insert(a[i]);

    }
    t1.print();
    //cout<<endl;
    //root = deleteFromBst(root , 118);
    //printBst(root);

    /*    
    for(int i=0;i<12;i++){
        cout<<endl;
        root = deleteFromBst(root , a[i]);
        printBst(root);
    }
    
    cout<<endl;
    */ 
   for(int i = 0 ; i < 12 ; i++){
       t1.deleteData(a[11-i]);
       cout << "deleteing "<< a[11-i] <<"  and checking   "<< a[i] << " in bst ans-" << t1.hasData(a[i]) << endl; 
   }
    

}