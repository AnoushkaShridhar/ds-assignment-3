#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;
    for (char c : expr) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix expression: ";
    cin >> postfix;
    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}
