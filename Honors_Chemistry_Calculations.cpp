#include <iostream>
#include <vector>
using namespace std;
//t = test cases
//n = numeber of people in the class
//k = your rank
//s = the percent of people that can pass
//g = students grades
//e = ec values
int main() {
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		double s; cin >> s;
		vector<double> g;
		for (int i = 0; i < n; i++){
			double next;
			cin >> next;
			g.push_back(next);
		}
		sort(g.begin(), g.end());
		vector<double> e;
		for (int i = 0; i < n; i++){
			double next;
			cin >> next;
			e.push_back(next);
		}
		vector<double> scoresWEC((size_t) n - 1);
		vector<double> withoutYou(g);
		withoutYou.erase(withoutYou.begin() + k - 1);
		vector<double> withoutBestEC(e);
		withoutBestEC.erase(withoutBestEC.begin());
		for (size_t i = 0; i < (size_t) n - 1; i++){
			scoresWEC[i] = withoutYou[i] + withoutBestEC[i];
		} 
		double newScore = g[(size_t) k - 1] + e[0];
		int passers = (int)(s/100.0 * n);
		scoresWEC.push_back(newScore);
		sort(scoresWEC.rbegin(), scoresWEC.rend());
		vector<double> passingScores((size_t) passers);
		for (size_t i = 0; i < (size_t) passers; i++){
			passingScores[i] = scoresWEC[i];
		} 

		auto it = find(passingScores.begin(), passingScores.end(), newScore);
		if (it != passingScores.end()) {
			cout << "1";
		} else cout << "0";
	}
}