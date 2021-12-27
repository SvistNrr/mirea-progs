#include <iostream>
#include <vector>
using  namespace std;
int main(){
    vector <int> even;
    vector <int> odd;
    int n,ans,tmp;
    cin>>n;
    for (int i = 0; i< n; i++){
        cin>>tmp;
        if (tmp%2==0){
            even.push_back(tmp);
        }
        else{
            odd.push_back(tmp);
        }
    }
    for (int i = 0; i < odd.size(); i++){
        cout<<odd[i]<<" ";
    }
    if (odd.size()>0){
        cout<<"\n";
    }
    for (int i = 0; i < even.size(); i++){
        cout<<even[i]<<" ";
    }
    cout<<"\n";
    if (even.size()>=odd.size()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}