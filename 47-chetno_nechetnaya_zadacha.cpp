#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool digit(long long a)
{
    bool c = false;
    vector<int> b;
    while(a >= 0 && b.size() <= 2){
        b.push_back(a % 8);
        a/=8;
    }
    if(b[2] % 2)
        c = true;
    return c;
}
int main()
{
    long long n, k;
    cin >> n;
    vector<long long> a;
    vector<long long> b;
    for(long long i = 0; i < n; ++i){
        cin >> k;
        a.push_back(k);
    }
    for(long long i = 0; i < a.size(); ++i){
        if(!(a[i] % 2)){
            if(digit(a[i]))
                b.push_back(a[i]);
        }
    }
    sort(b.begin(),b.end());
    cout << b.size() << endl;
    for(long long i = 0; i < b.size(); ++i)
        cout << b[i] << " ";
    return 0;
}