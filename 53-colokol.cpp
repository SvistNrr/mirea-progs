#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,tmp;
    cin>>n;
    vector <int> a;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    int b[n],_n=0,_k=n-1;
    for (int i = 0; i < n; i++){
        if (i%2==0){
            b[_n]=a[i];
            _n++;
        }
        else{
            b[_k]=a[i];
            _k--;
        }
    }
    for (int i = 0; i < n; i++){
        cout<<b[i]<<" ";
    }
}