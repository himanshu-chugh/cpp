#include<iostream>
using namespace std;
template < typename t,typename v>
class Pair{
    t x;
    v y;
    public:
    void setX( t x){
        this->x = x;
    }
    void setY( v y){
        this->y = y;
    }
    t getX(){
        return x;
    }
    v getY(){
        return y;
    }
};


int main(){
    
    Pair<Pair<int,int>,int> p;
    p.setY(10);
    Pair< int,int> p1;
    p1.setX(1);
    p1.setY(2);
    p.setX(p1);
    cout << p.getX().getX() << " " << p.getX().getY() << " " << p.getY() << endl;
    cout << " size of only int int "<< sizeof(p1) << " size of pai & int "<< sizeof(p);
    return 0;
}