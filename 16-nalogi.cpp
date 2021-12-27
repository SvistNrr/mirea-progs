#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int v[n],p[n],q[n],tmp;
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    for (int i = 0; i < n; i++){
        cin>>p[i];
    }
    for (int i = 0; i < n; i++){
        q[i]=p[i]*v[i];
    }
    int max=-1;
    int ans;
    for (int i = 0; i < n; i++){
        if (q[i]>max){
            max = q[i];
            ans = i;
        }
    }
    cout<<ans+1;
}