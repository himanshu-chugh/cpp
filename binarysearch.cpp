#include<iostream>
using namespace std;


int binarySearch(int input[], int size, int element) {
    // Write your code here
    
    if(size>0){
        int mid;
        if(size%2 == 1){
            mid = size/2;
        }
        else{
            mid = (size - 1) /2;
        }

        if(input[mid] == element){
            return mid;
        }
        else if( input[mid] > element){
            return binarySearch(input , mid , element);
        }
        else{
            int m = binarySearch(input + mid +1, size - mid -1 , element);
            if(m > -1){
                return mid + 1 + m;
            }
            else{
                return m;
            } 
        }
    }

    else{
        return -1;
    }

}


int main(){
    int a[] = {1,2,3,4,7,8,9 , 11};
    //int b[] = {26, 27, 31 ,31 ,31 ,32 ,37, 38, 44 ,44 ,47 ,51 ,52 ,58 ,69, 70, 71, 73, 83, 84, 91, 94, 95, 97, 103 ,104 ,106 ,111 ,118 ,130 ,132 ,134 ,140 ,141, 144, 148, 162, 163, 166 ,175 ,179 ,180 ,181 ,182 ,183 ,184 ,184 ,185 ,186 ,190 ,192 ,195, 197 ,199 ,204 ,209 ,211 ,214 ,216 ,218, 222, 232, 239 ,242 ,244 ,245 ,248 ,250 ,258 ,258 ,268, 270 ,274 ,276 ,277, 291, 295, 297, 301, 302, 312 ,313, 316, 322 ,328 ,331 ,333 ,334 ,335 ,337 ,347 ,350 ,350, 353, 353, 354, 357 ,358 ,363 ,364 ,369, 382, 390, 393, 396, 400, 401, 403, 414 ,418 ,419 ,421 ,424 ,430 ,432, 440 ,444 ,464, 464, 467 ,479 ,488 ,490 ,492 ,492, 495 ,500};
    int i;
    cin >> i;
    cout<< binarySearch( a, 8 , i )<<endl;
    return 0;
}