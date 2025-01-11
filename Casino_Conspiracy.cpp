#include <iostream>
#include <set>
using namespace std;

int main() {
	int t; cin >> t;
	set<int> arr;
	while(t--){
		int n; cin >> n;
		vector<int> values;
		for(int i = 0; i < n; i++){
			int temp; cin >> temp;
			values.push_back(temp);
		}
		int sum = 0;
		int ans = 0;
		arr.insert(0);
		for(size_t i = 0; i < values.size(); i++) {
			sum += values[i];
			if(arr.find(sum) != arr.end()){ 
				ans += 1;
				arr.clear();
				sum = 0;
				arr.insert(0);
			} else{
				arr.insert(sum);
			}
		}
		cout << ans << endl;
		arr.clear();
	}
}
/*
iter 1: sum = 0, ans = 0, <0> --> sum = 2, ans = 0, <0, 2>
iter 2: sum = 2, ans = 0, <0, 2> --> sum = 3, ans = 0, <0, 2, 3>
iter 3: sum = 3, ans = 0, <0, 2, 3> --> sum = 0, ans = 1, <0>
iter 4: ... nothing else important happens
*/