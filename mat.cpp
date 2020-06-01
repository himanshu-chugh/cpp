#include<psh.h>
#include<bits/stdc++.h>

using namespace std;
class Mat{
public:
int **arr;
int m , n;
Mat(int a , int b){
m = a;
n = b;
arr = new int*[m];
for(int i = 0; i < m; i++){
arr[i] = new int[n];
}
}
~Mat(){
for(int i = 0; i < m; i++){
delete[] arr[i];
}
delete[] arr;
}
};

Mat* matMulti(Mat& a , Mat &b){
if(a.n != b.m){
return NULL;
}
Mat *c = new Mat(a.m , b.n);
for(int i = 0; i < a.m; i++){
for(int j = 0; j < b.n; j++){
int sum = 0;
for(int k = 0; k < a.n; k++){
sum += (a.arr[i][k] * b.arr[k][j]);
}
c->arr[i][j] = sum;
}
}
return c;
}


int main(){
srand(time(NULL));
time_t start , finish;
clock_t begin , end;
begin = clock();
time(&start);
while(1){

int m1 =rand()%1000 , m2 = rand()%1000 , n1 , n2 = rand()%1000;
n1 = m2;
Mat a(m1 , n1) , b(m2 , n2) , *c;

for(int i = 0; i < a.m; i++){
for(int j = 0; j <a.n; j++){
//cin >> a.arr[i][j];
a.arr[i][j] = rand()%1000;
}
}
for(int i = 0; i < b.m; i++){
for(int j = 0; j <b.n; j++){
//cin >> b.arr[i][j];
b.arr[i][j] = rand()%1000;
}
}

c = matMulti(a , b);
if(c == NULL){
cout << " multiply not possible " << endl;
return 0;
}
cout << endl;
for(int i = 0; i < c->m; i++){
for(int j = 0; j < c->n; j++){
cout << c->arr[i][j] << " ";
}
cout << endl;
}
delete c;
cout << endl;
cout << " time took " << (double)difftime(finish , start) << endl;
cout << " time took " << (float)(end-begin)/CLOCKS_PER_SEC << endl;
cout << endl;
}
return 0;
}
