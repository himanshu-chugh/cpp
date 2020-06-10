#include<bits/stdc++.h>
#define ll long long 
#define P pair<ll , ll>

using namespace std;

class region{
    public:
    int start ,end , size;
    region(){
        start = 0;
        end = 0;
        size = 0;
    }
    region(int d, int e){
        start = d;
        end = e;
        size = e-d+1;
    }
    void printregion(){
        cout << start << " " << end << " total elements: " << size << endl;
    }

};
class mids{
    public:
    int totalcount = 0;
    int lmid , rmid , mid;
    mids(int a , int b , int c){
        lmid = a;
        mid = b;
        rmid = c;
    }
    mids(){
        lmid = 0;
        rmid = 0;
        mid = 0;
    }
};

bool comp(region &r1 , region &r2){
    return r1.start < r2.start;
}



mids getmids(vector<region> &v){
    sort(v.begin() , v.end() , comp);
    mids ans;
    int totalcounter = 0, leftregioncounter = 0 , rightregioncounter = 0;
    for(int i = 0; i< v.size(); i++){
        totalcounter += v[i].size;
    }
    // if(totalcounter < 4){
    //     ans.totalcount = totalcounter;
    //     return ans;
    // }
    int temp = totalcounter/2;
    if(totalcounter%2){
        temp++;
    }
    leftregioncounter = temp-1;
    rightregioncounter = totalcounter - temp;
    int temp1 = leftregioncounter/2;
    if(leftregioncounter%2){
        temp1++;
    }
    int temp2 = rightregioncounter/2;
    if(rightregioncounter%2){
        temp2++;
    }
    temp2 += temp;
    bool lnotfound = 1 , rnotfound = 1, mnotfound = 1;
    
    for(int i =0; i<v.size();i++){
        if(mnotfound and v[i].size >= temp){
            ans.mid = v[i].start + temp -1;
            mnotfound = 0;
        }
        else{
            temp -= v[i].size;
        }

        if(lnotfound and v[i].size >= temp1){
            ans.lmid = v[i].start + temp1 -1 ;
            lnotfound = 0;
        }
        else{
            temp1 -= v[i].size;
        }

        if(rnotfound and v[i].size >= temp2){
            ans.rmid = v[i].start + temp2 -1;
            rnotfound = 0;
        }
        else{
            temp2 -= v[i].size;
        }
        if(!(mnotfound or lnotfound or rnotfound)){
            break;
        }
    }
    return ans;
}


void solvefr(vector<region> &tr , vector<region> &fr){

}

void solvetr(vector<region> &tr , vector<region> &fr){
    // this function  will work only when fr is empty
    if(fr.size() != 0){
        solvefr(tr , fr);
    }
    
    mids ans = getmids(tr);
    if(tr.size() <= 1 and tr[0].size < 3){
        for(int i =tr[0].start; i<=tr[0].end; i++){
        // tr[0].printregion();
            cout << i << endl;
            char cc;
            cin >> cc;
            if(cc == 'E'){
                exit(4);
            }
        }
    }
    cout << ans.mid << endl;
    char c1 , c2;
    cin  >> c1;
    if(c1 == 'E'){
        exit(0);
    }
    else if(c1 == 'G'){
        cout << ans.lmid << endl;
        cin >>  c2;
        if(c2 == 'E'){
            exit(1);
        }
        else if(c2 == 'G'){
            int nodestodelete = 0;
            for(int i = 0; i< tr.size(); i++){
                if(tr[i].end <= ans.lmid){
                    nodestodelete++;
                }
                else{
                    break;
                }
                tr.erase(tr.begin() , tr.begin()+nodestodelete);
                tr[0].start = ans.lmid+1;
                tr[0].size = tr[0].end - tr[0].start + 1;
            }
        }
        else{
            while(tr.back().start >= ans.mid+1){
                region r= tr.back();
                fr.push_back(r);
                tr.pop_back();
            }
            if(tr.back().end >= ans.mid+1 and tr.back().start <= ans.mid+1){
                region r= tr.back();
                r.start = ans.mid+1;
                r.size = r.end - r.start +1;
                fr.push_back(r);
                tr.pop_back();
            }
            sort(fr.begin() , fr.end() , comp);
            for(int i =0; i < tr.size(); i++){
                if(tr[i].start <= ans.lmid-1){
                    continue;
                }
                else{
                    
                }
            }

        }

    }
    else{
        cout << ans.rmid << endl;
        cin >> c2;
        if(c2 == 'E'){
            exit(1);
        }
        else if(c2 == 'L'){
            while(tr.back().start >= ans.rmid){
                tr.pop_back();
            }
            int s = tr.size()-1;
            if(tr[s].start < ans.rmid and tr[s].end >= ans.rmid){
                tr[s].end = ans.rmid-1;
                tr[s].size = tr[s].end - tr[s].start +1;
            }
        }
        else{
            // complete code (HARD)
        }
    }

}

int main(){
    vector<region> tr , fr;
    int  n;
    // cin >> n;
    n = 300;
    region r(200, 200);
    region rr(201 , 203);
    tr.push_back(r);tr.push_back(rr);
    
    while(tr.size()!= 0)
    {for(int i = 0; i < tr.size();  i++){
        tr[i].printregion();
    }
    cout <<  "tr region " << tr.size() << endl;
    
    solvetr(tr , fr);
    cout <<  "tr region " << tr.size() << endl;
    for(int i = 0; i < tr.size();  i++){
        tr[i].printregion();
    }}

}