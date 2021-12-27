#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n, c = 0, cc = 0;
    cin >> n;
    bool b = false;
    vector<int> a;
    while(a.size() != n){
        vector<int> arr(10);
        ++cc;
        c = cc;
        b = 0;
        while(c){
            ++arr[c % 10];
            c/=10;
        }
        for(int i = 0; i < arr.size(); ++i)
            if(arr[i] > 1){
                b = true;
                break;
            }
        if(!b)
            a.push_back(cc);
    }
    cout << a[n - 1];
    return 0;
}