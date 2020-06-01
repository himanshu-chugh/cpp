#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'findSpecialProduct' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY inputArray as parameter.
 */

vector<int> findSpecialProduct(vector<int> arr) {
    if(arr.size() == 0 || arr.size() == 1){
        return arr;
    }
    int n = arr.size();

    int *left = new int[sizeof(int)*n];  
    int *right = new int[sizeof(int)*n]; 
      
    int *prod = new int[sizeof(int)*n]; 
      
    int i, j;  
      
    left[0] = 1;  
      
    right[n - 1] = 1;  
      
    for(i = 1; i < n; i++)  
        left[i] = arr[i - 1] * left[i - 1];  
      
    for(j = n - 2; j >= 0; j--)  
        right[j] = arr[j + 1] * right[j + 1];  
    
    for (i = 0; i < n; i++)  
        prod[i] = left[i] * right[i];  
      
    vector<int> toreturn;
    for (i = 0; i < n; i++)  
        toreturn.push_back(prod[i]);  
    delete[] left , right , prod;  
    return toreturn;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string inputArray_count_temp;
    getline(cin, inputArray_count_temp);

    int inputArray_count = stoi(ltrim(rtrim(inputArray_count_temp)));

    vector<int> inputArray(inputArray_count);

    for (int i = 0; i < inputArray_count; i++) {
        string inputArray_item_temp;
        getline(cin, inputArray_item_temp);

        int inputArray_item = stoi(ltrim(rtrim(inputArray_item_temp)));

        inputArray[i] = inputArray_item;
    }

    vector<int> result = findSpecialProduct(inputArray);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
