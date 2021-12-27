#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector <int> arr;
    int n,tmp;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    int sh=0,kr=0;
    for (int i=0;i<n/2;i++){
        sh+=arr[n/2+i];
        kr+=arr[i];
    }
    cout<<sh-kr;
}