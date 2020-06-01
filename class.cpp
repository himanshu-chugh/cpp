/**********
 
Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.

 ************/

#include<bits/stdc++.h>
using namespace std;


class ComplexNumbers {
    // Complete this class
    public:
    int real;
    int complex;
    ComplexNumbers(int r, int c){
        real = r;
        complex =c;
    }
    void print(){
        cout<<real<<" + i"<<complex<<endl;
    }
    void plus(ComplexNumbers const &cn){
        real += cn.real;
        complex += cn.complex;
    }
    void multiply(ComplexNumbers const &cn){
        int t = (real*cn.real) - (complex*cn.complex );
        complex = (real*cn.complex) + (complex*cn.real);
        real = t;
    }
};

 
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
