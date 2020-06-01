#include<iostream>
using namespace std;




/*************
 Driver program to test below functions

****************/

class Polynomial {
    public:
    int *degCoeff;    
    int capacity;
    Polynomial(){
        degCoeff = new int[5]{0};
        capacity = 5;    
    }
    Polynomial(int n){
        degCoeff = new int[n]{0};
        capacity = n;    
    }
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
            int n = deg/capacity;
            int *temp = new int[(n+1)*capacity];
            for(int i=0; i<capacity; i++){
                temp[i] = degCoeff[i];
            }
            delete [] degCoeff;
            for(int i = capacity; i<(n+1)*capacity;i++){
                temp[i] = 0;
            }
            temp[deg] = coef;
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
            Polynomial new_p(p.capacity );
            int j=0;
            for(int i=0;i<p.capacity;i++){
                if(j<capacity){
                    new_p.degCoeff[i] =  degCoeff[j] - p.degCoeff[i];
                    j++;
                }else{
                    new_p.degCoeff[i] = 0 - p.degCoeff[i];
                }
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
    Polynomial p1;
    cout<<p1.capacity<<endl;
    p1.degCoeff[2] = 3;
    p1.degCoeff[1] = 2;
    p1.degCoeff[0] = 1;
    

    
    cout<<"p1 capacity "<<p1.capacity<<"\n  p1 : ";
    p1.print();

    Polynomial p2;
    //cout<<"p2 capacity "<<p2.capacity<<"\n  p1 : ";
    //p2.print();
    p2 = p1;
    cout<<"p2 capacity "<<p2.capacity<<"\n  p2 : ";
    p2.print();
    cout<<endl;
    //p2.print();
    //p2.setCoefficient(8,9);
    //p2.setCoefficient(4,22);
    //cout<< "capa  "<<p2.capacity<<endl<<"p2 : ";
    //p2.print();
    //cout<<"now addition\n";
    //Polynomial p3(p1 - p2);
    //p3.print();
    //cout<<"size p3 "<<p3.capacity<<endl;
    cout<<"p1 * p2 : \n";
    Polynomial p4 = p1*p2;
    p4.print();
    return 0;
}