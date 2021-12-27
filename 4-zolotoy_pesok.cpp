#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector <int> a;
    vector <int> b;
    int tmp;
    for (int i=0;i<3;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    for (int i=0;i<3;i++){
        cin>>tmp;
        b.push_back(tmp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<a[2]*b[2]+a[1]*b[1]+a[0]*b[0];
}