#include <iostream>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

struct node{
    string s ;
    node*lptr=NULL,*rptr=NULL;
};
void pr(node*t){
    if(t){
        pr(t->lptr);
        cout<<t->s <<" ";
        pr(t->rptr);
    }
}
void preo(node*t){
    if(t){
        cout<<t->s <<" ";
        pr(t->lptr);
        pr(t->rptr);
    }
}


int main() {
	string s;
	getline(cin , s);
	stack<node*> st;
	string pre ="";
	for(int i=0;i<s.length();i++){
	   
	    if(s[i] == '/' || s[i] == '*'|| s[i] == '+'|| s[i] == '-' || s[i] == '^'){
	        node *t1,*t2;
	        t1 =st.top();
	        st.pop();
	        t2 =st.top();
	        st.pop();
	        node *temp =new node;
	        temp->s=s[i];
	        temp->lptr=t2;
	        temp->rptr=t1;
	        st.push(temp);
	    }
	    else if(s[i]==' ' && !(s[i-1] == '/' || s[i-1] == '*'|| s[i-1] == '+'|| s[i-1] == '-' || s[i-1] == '^')){
	        node *temp =new node;
	        temp->s=pre;
	        cout<<pre<<endl;
	        pre="";
	        st.push(temp);
	    }
	    else{
	        pre=pre+s[i];
	    }
	}
	
	pr(st.top());
	cout<<endl;
	preo(st.top());
	cout<<endl;
	
	    
	
	return 0;
}
