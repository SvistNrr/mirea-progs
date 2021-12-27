#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int max=0;
    int age,s;
    int ans=-1;
    for (int i = 1; i <= n; i++){
        cin>>age>>s;
        if (s&&age>max){
            max=age;
            ans=i;
        }
    }
    cout<<ans;
}