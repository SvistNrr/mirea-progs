#include <iostream>
using namespace std;
int main(){
    int s=0;
    int tmp;
    for (int i = 0; i < 31; i++){
        cin>>tmp;
        s+=tmp;
    }
    cout<<s/27;
}