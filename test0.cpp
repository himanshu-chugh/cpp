// CPP program to illustrate 
// Private Destructor 

#include <bits/stdc++.h> 
using namespace std; 

class Test { 
public: 
	Test() // Constructor 
	{ 
		cout << "Constructor called\n"; 
	} 

private: 
	~Test() // Private Destructor 
	{ 
		cout << "Destructor called\n"; 
	} 
}; 

class Pair{
  public :
  int first;
  int second;
};

int main(){

  Pair *p1 = new Pair;
  Pair p2;
  p1 = &p2;
  return 0;
}
