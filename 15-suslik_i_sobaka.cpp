#include <iostream>
#include "cmath"
using namespace std;
int main(){
    int x_suslik,y_suslik,x_sobaka,y_sobaka;
    cin>>x_suslik>>y_suslik>>x_sobaka>>y_sobaka;
    int n;
    cin>>n;
    int x,y;
    bool f = false;
    for (int i = 0; i < n; i++){
        cin>>x>>y;
        if (2*sqrt(pow(abs(x-x_suslik),2)+pow(abs(y-y_suslik),2))<=sqrt(pow(abs(x-x_sobaka),2)+pow(abs(y-y_sobaka),2))){
            cout<<i+1;
            f=true;
            break;
        }

    }
    if (!f){
        cout<<"NO";
    }
}