#include<iostream>
using namespace std;




/*************
 Driver program to test below functions

****************/

class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    
    // Complete the class
    int capacity;

                //default cons

    Polynomial(){
        degCoeff = new int[5]{0};
        capacity = 5;    
    }
    Polynomial(int n){
        degCoeff = new int[n]{0};
        capacity = n;    
    }

                 // copy cons
    
    Polynomial(Polynomial const &p){
        capacity = p.capacity;
        degCoeff = new int[capacity];
        for(int i=0;i<capacity;i++){
            degCoeff[i] = p.degCoeff[i];
        }    
    }

    void setCoefficient(int const &deg , int const &coef){
        if(deg<capacity){
            degCoeff[deg] = coef;
        }
        else {
            int n = deg/coef;
            int *temp = new int[(n+1)*capacity];
            for(int i=0; i<capacity; i++){
                temp[i] = degCoeff[i];
            }
            for(int i = capacity; i<(n+1)*capacity;i++){
                temp[i] = 0;
            }
            temp[deg] = coef;
            delete [] degCoeff;
            degCoeff = temp;
            capacity *= (n+1);
        }
    }

    Polynomial operator+(Polynomial const &p){
        
        if(capacity > p.capacity){
            Polynomial new_p(*this);
            for(int i=0;i<p.capacity;i++){
                new_p.degCoeff[i] += p.degCoeff[i];
            }
            return new_p;
        }
        else{
            Polynomial new_p(p);
            for(int i=0;i<capacity;i++){
                new_p.degCoeff[i] += degCoeff[i];
            }
            return new_p;
        }
    }



    Polynomial operator-(Polynomial const &p){
        
        if(capacity > p.capacity){
            Polynomial new_p(*this);
            for(int i=0;i<p.capacity;i++){
                new_p.degCoeff[i] -= p.degCoeff[i];
            }
            return new_p;
        }
        else{
            Polynomial new_p(p);
            for(int i=0;i<capacity;i++){
                new_p.degCoeff[i] -= degCoeff[i];
            }
            return new_p;
        }
    }


    void operator=(Polynomial const &p){
        if(capacity == p.capacity){
            for(int i=0;i<capacity;i++){
                degCoeff[i] = p.degCoeff[i];
            }
        }
        else{
            delete[] degCoeff;
            degCoeff = new int[p.capacity];
            capacity = p.capacity;
            for(int i=0;i<capacity;i++){
                degCoeff[i] = p.degCoeff[i];
            }
        }
    }


    Polynomial operator*(Polynomial const &p){
        Polynomial newp(capacity+p.capacity) ;
        for(int i=0;i<capacity;i++){
            for(int j=0;j<p.capacity;j++){
                int kk = j+i;
                newp.setCoefficient(kk , newp.degCoeff[i+j] + (degCoeff[i] * p.degCoeff[j]) );
            }
        }
        return newp;
    }

    void print(){
        for(int i=0;i<capacity;i++){
            if(degCoeff[i] != 0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }  
        }cout<<endl;
    }



};


 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}