#include<bits/stdc++.h>
using namespace std;
class a{
    public:
    a(){
        cout << "inside a " << endl;
    }
    int vari;
    ~a(){
        cout << "   des inside a " << endl;
    }
};
class b : public a{
    public:
    b(){
        cout << "inside b " << endl;
    }
    ~b(){
        cout << "   des inside b " << endl;
    }
};
class c : public a{
    public:
    c(){
        cout << "inside c" << endl;
    }
    c(int a){
        cout << "inside c par" << endl;
    }
    ~c(){
        cout << "   des inside c" << endl;
    }
};

class d :public c , public b{
    public:
    d() : c(7){
        cout << "inside d" << endl;
    }

    ~d(){
        cout << "   des inside d" << endl;
    }

};
class base{
    public:
    int d1 , d2 , d3;
    void fun(int m){
        d1 = m;
        d2 = m;
        d3 = m;
    }
    void fun3(){
        d1--;
        d2--;
        d3--;
    }
};
class de : public base{
    public:
    fun3() = delete;
};
int main(){
    de obj;
    obj.fun(5);
    cout << obj.d1 << " " << obj.d2 << " " << obj.d3 << endl;
    obj.fun3();
    cout << obj.d1 << " " << obj.d2 << " " << obj.d3 << endl;
    return 0;
}