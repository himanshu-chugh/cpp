#include<iostream>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
         ll p, q, r, a, b, c;
        cin >> p >> q >> r >> a >> b >> c;
        if(p==a && q==b && r == c)  { cout << 0 << endl; continue;}
        else if((p == a && q == b) || (q == b && r == c) || (p == a && r == c)) { cout << 1 << endl; continue;}
        else if(p == a)
        {
            if((!q || !r) && q - b == r - c)  { cout << 1 << endl; continue;}
            else if(q && r && (q - b == r - c || (b / q == c / r && b % q == 0 && c % r == 0))) { cout << 1 << endl; continue;}
            else  { cout << 2 << endl; continue;}
        }
        else if(q == b)
        {
            if((!p || !r) && p - a == r - c)  { cout << 1 << endl; continue;}
            else if(p && r && (p - a == r - c || (a / p == c / r && a % p == 0 && c % r == 0))) { cout << 1 << endl; continue;}
            else  { cout << 2 << endl; continue;}
        }
        else if(r == c)
        {
            if((!p || !q) && p - a == q - b)  { cout << 1 << endl; continue;}
            else if(p && q && (p - a == q - b || (b / q == a / p && b % q == 0 && a % p == 0))) { cout << 1 << endl; continue;}
            else  { cout << 2 << endl; continue;}
        }

        else if(p && q && r && b / q == c / r && a / p == c / r && b / q == a / p && a % p == 0 && b % q == 0 && c % r == 0)  { cout << 1 << endl; continue;}
        else if((p - a == q - b) && (q - b == r - c) && (r - c == p - a)) { cout << 1 << endl; continue;}
        else if((p - a == q - b) || (q - b == r - c) || (r - c == p - a)) { cout << 2 << endl; continue;}
        else if(q && p && b / q == a / p && b % q == 0 && a % p == 0) { cout << 2 << endl; continue;}
        else if(q && r && b / q == c / r && b % q == 0 && c % r == 0) { cout << 2 << endl; continue;}
        else if(p && r && a / p == c / r && a % p == 0 && c % r == 0) { cout << 2 << endl; continue;}
        else if(p - a == q - b + r - c || q - b == p - a + r - c || r - c == p - a + q - b) { cout << 2 << endl; continue;}
        else if((p && q && r && a % p == 0 && b % q == 0 && c % r == 0) && (a / p * b / q == c / r || b / q * c / r == a / p || c / r * a / p == b / q))  { cout << 2 << endl; continue;}
        else
        {
            if(p && a % p == 0)
            {
                ll valt = a / p;
                if(q * valt - b == r - c || r * valt - c == q- b) { cout << 2 << endl; continue;}
                else if(valt && ((c % valt == 0 && q - b == r - c / valt) || (b % valt == 0 && r - c == q - b / valt))) { cout << 2 << endl; continue;}
            }
            if( q && b % q == 0)
            {
                ll valt = b / q;
                if(p * valt - a == r - c || r * valt - c == p- a) { cout << 2 << endl; continue;}
                else if(valt && ((a % valt == 0 && r - c == p - a / valt) || (c % valt == 0 && p - a == r - c / valt))) { cout << 2 << endl; continue;}
            }
            if( r && c % r == 0)
            {
                ll valt = c / r;
                if(p * valt - a == q - b || q * valt - b == p- a) { cout << 2 << endl; continue;}
                else if(valt && ((b % valt == 0 && p - a == q - b / valt) || (a % valt == 0 && q - b == p - a / valt))) { cout << 2 << endl; continue;}
            }
            if( (p != q) && (a - b) % (p- q) == 0)
            {
                ll valt =  (a - b) / (p - q);
                if(p * valt - a == r * valt - c)  { cout << 2 << endl; continue;}
                else if(p * valt - a == r - c)  { cout << 2 << endl; continue;}
                else if(r * valt == c)  { cout << 2 << endl; continue;}
                else if(valt && a % valt == 0 && b % valt == 0 && c - r == a / valt - p && c- r == b / valt - q)  { cout << 2 << endl; continue;}
            }
            if( (q != r) && (b- c) % (q- r) == 0)
            {
                ll valt =  (b-c) / (q-r);
                if(q * valt - b == p * valt - a)  { cout << 2 << endl; continue;}
                else if(q * valt - b == p - a)  { cout << 2 << endl; continue;}
                else if(p * valt == a)  { cout << 2 << endl; continue;}
                else if(valt && c % valt == 0 && b % valt == 0 && a - p == b / valt - q && a - p == c / valt - r) { cout << 2 << endl; continue;}
            }
            if( (r != p) && (c- a) % (r- p) == 0)
            {
                ll valt =  (c - a) / (r - p);
                if(r * valt - c == q * valt - b)  { cout << 2 << endl; continue;}
                else if(r * valt - c == q - b)  { cout << 2 << endl; continue;}
                else if(q * valt == b)  { cout << 2 << endl; continue;}
                else if(valt && a % valt == 0 && c % valt == 0 && b - q == a / valt - p && b - q == c / valt - r) { cout << 2 << endl; continue;}
            }
            cout << 3 << endl; continue;
        }
    }
}