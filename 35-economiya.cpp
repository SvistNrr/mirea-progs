#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int min_in_array(int arr[],int n){
    int min = 101;
    int rtn = -1;
    for (int i = 0; i < n; i++){
        if (arr[i]<min){
            min=arr[i];
            rtn=i;
        }
    }
    return rtn;
}
int main(){
    int n,k,tmp;
    cin>>n>>k;
    vector <int> c;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        c.push_back(tmp);
    }
    int p[k];
    for (int i = 0; i < k; i++){
        p[i]=0;
    }
    long long int ans = 0;
    sort(c.begin(),c.end());
    for (int i = n-1; i >= 0; i--){
        int q=min_in_array(p,k);
        ans+=(p[q]+1)*c[i];
        p[q]+=1;
    }
    cout<<ans;
}