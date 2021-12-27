#include <iostream>
 
using namespace std;
 
bool cot(int n) {
    int s = 0;
    int count = 0;
    while (n>0) {
        s+=n%10;
        count++;
        n/=10;
    }
    return (s%count)==0;
}
 
int main() {
    int n, k = 0, num = 0; cin >> n;
    while (k<n) {
        num++;
        if (cot(num)) k++;
    }   
    cout << num;
}