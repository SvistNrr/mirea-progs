#include <iostream>
using namespace std;
int main()
{
    long long n, k, result;
    cin >> n >> k;
    result = 1 + (n - 1) * k;
    for(int i = 0; i < k; ++i){
        result += i * (n - 2);
    }
    cout << result;
    return 0;
}