#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int N;
bool judge(string word);
int main() {
    cin >> N;
    string w;
    for (int i = 1; i <= N; ++i) {
        cin >> w;
        if (judge(w)) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }
}
bool judge (string word) {
    stack<char> s;
    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (c=='('||c==')'||c=='<'||c=='>'||c=='{'||c=='}'||c=='['||c==']') {
            switch (c) {
                case '(':
                case '{':
                case '[':
                case '<': {
                    s.push(c);
                    break;
                }
                case ')':{
                    if (s.size()) {
                        char t = s.top();
                        if(t!='(') return false;
                    }
                    else return false;
                    s.pop();
                    break;
                }
                case '}':{
                    if (s.size()) {
                        char t = s.top();
                        if(t!='{') return false;
                    }
                    else return false;
                    s.pop();
                    break;
                }
                case ']':{
                    if (s.size()) {
                        char t = s.top();
                        if(t!='[') return false;
                    }
                    else return false;
                    s.pop();
                    break;
                }
                case '>': {
                    if (s.size()) {
                        char t = s.top();
                        if(t!='<') return false;
                    }
                    else return false;
                    s.pop();
                    break;
                }
            }
        }
    }
    if (s.size()) return false;
    return true;
}
