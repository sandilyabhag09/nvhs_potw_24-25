#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool test_case_passed(int n, int k, vector<int>& t) {
     priority_queue<int, vector<int>, greater<int>> q(t.begin(), t.end());
     while (q.size() != 1) {
        int smallest = q.top(); q.pop();
        int second_smallest = q.top(); q.pop();
        int new_average = (smallest + second_smallest) / 2;
        q.push(new_average);
     }
     return (q.top() >= k);
}
int main() {
    int c; cin >> c;
    int count = 0;
    while(c--){
        int n; int k; cin >> n >> k;
        vector<int> t;
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            t.push_back(temp);
        }
        if(test_case_passed(n, k, t)) count++;
    }
    cout << count << endl;
}
/* According to the logic that you have graciously provided (jk):
    average first two elements pop back and do it until there is one element left
    so for the data 
    1 4 5 7 8 
    1 4 turns into 2
    2 5 7 8 
    2 5 turns into 3
    3 7 8 
    3 7 turns into 5
    5 8 --> 6 >= 6 so we win
    him
*/