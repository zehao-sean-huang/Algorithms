#include <iostream>
#include <stack>
#include <string>
using namespace std;
int N;
int main() {
    stack<int> s;
    scanf("%d",&N);
    int result=0;
    for (int i=1;i<N;++i){
        int temp;
        cin >> temp;
        if(!s.size()) s.push(temp);
        else {
            while (s.size()&&s.top()<temp){
                s.pop();
            }
            s.push(temp);
        }
        result+=s.size();
    }
    cout<<result<<endl;
}