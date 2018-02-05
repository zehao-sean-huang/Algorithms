#include <iostream>
using namespace std;
int c(int a) {
    if (a>=0) return 5;
    return 1+c(a+1)+c(a+2);
}
int main(){
    int t;
    cin >> t;
    cout << c(t) << endl;
}