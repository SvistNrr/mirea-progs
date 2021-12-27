#include <iostream>
#include <string>
#include <cmath>
  
using namespace std;
  
int main() {
    string str; cin >> str;
    int minN = 0, maxN = 0, n = 0;
 
    for (char c : str) {
        if (c == '1') n++;
        else n--;
        maxN = max(maxN, n);
        minN = min(minN, n);
    }
 
    cout << maxN-minN+1;
}