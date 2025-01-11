#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t; cin >> t; 
    int num = 0;
    stack<char> st; 
	while (t--){
		string s;
		cin >> s;
		bool invalid = false;
		for (char c : s){
			if ((st.empty()) && (c == '+' || c == '-' || c == '*' || c == '/' || c == ')')){
                invalid = true;
			} else if ((!st.empty()) && 
			(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') && 
			(c == '+' || c == '-' || c == '*' || c == '/' || c == ')')){
				invalid = true;
			} else if((!st.empty()) && (st.top() == '(') && (c == ')')){
				invalid = true;
			} else if ((!st.empty()) && (st.top() == ')') && (c == '(')){
				invalid = true;
			} else {
				st.push(c);
				continue;
			}
		}
		if (invalid == false) {
			num++;
		}

		while (!st.empty()) {
			st.pop();
		}
	}
	cout << num << endl;
}