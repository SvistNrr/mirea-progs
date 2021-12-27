#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> b(1000000);
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    ++b[2];
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n == 2){
        cout << 3;
        return 0;
    }
    int k = 2;
    while(n != a.size()){
        if(b[k] > 0)
            a.push_back(a[k - 1] + 3);
        else
            a.push_back(a[k - 1] + 2);
        ++b[a[k] - 1];
        ++k;
    }
    cout << a[n - 1];
    return 0;
}