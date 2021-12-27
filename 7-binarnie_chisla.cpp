#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if (n>1&&(n&(n-1))==0){
        cout<<"YES";
    }
    else if (n==1){
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
    
}