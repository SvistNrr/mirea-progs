#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a=1,b=1,tmp;
    if (n==0||n==1){
        b=1;
    }
    else{
        for (int i = 1; i < n; i++){
            tmp=(a+b)%10;
            a=b;
            b=tmp;
        }
    }
    cout<<b%10;
}