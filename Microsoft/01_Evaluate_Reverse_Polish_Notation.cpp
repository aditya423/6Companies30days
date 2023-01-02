#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens){

    stack<int> st;
    for(auto s : tokens){

        if(s.size()>1 || isdigit(s[0]))
            st.push(stoi(s));
        else {
            auto num2 = st.top();
            st.pop();
            auto num1 = st.top();
            st.pop();
            switch(s[0]){
                case '+':
                    num1 += num2;
                    break;
                case '-':
                    num1 -= num2;
                    break;
                case '*':
                    num1 = (long long)(num1*num2);
                    break;
                case '/':
                    num1 /= num2;
                    break;
            }
            st.push(num1);
        }
    }

    return st.top();
}

// TC --> O(N)
// SC --> O(N)

int main() {

    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout<<evalRPN(tokens)<<endl;

    return 0;
}