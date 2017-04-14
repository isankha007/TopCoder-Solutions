#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


class P8XGraphBuilder {
public:
	
		int dp[52][102];
		vector <int> scores;
	
	int solve(vector <int> scores){
		memset(dp,-1,sizeof(dp));
		this->scores = scores;
		return calculate(scores.size()+1,2*scores.size());
	}
	int calculate(int vertexLeft,int sum){
		if(vertexLeft !=0 && sum<=0)
		return -9999999;
		if(vertexLeft==0 && sum!=0)
		return -9999999;
		if(vertexLeft==0 && sum==0)
		return 0;
		if(dp[vertexLeft][sum]!=-1)
		return dp[vertexLeft][sum];
		int maximum=-99999;
		for(int i = 0 ; i<scores.size() ; i++){
			int local = calculate(vertexLeft-1,sum-(i+1));
			if(local>=0){
				local+=scores[i];
				if(local>maximum)
				maximum=local;
			}
		}
		return dp[vertexLeft][sum]=maximum;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	P8XGraphBuilder *obj;
	int answer;
	obj = new P8XGraphBuilder();
	clock_t startTime = clock();
	answer = obj->solve(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	
	
	{
	// ----- test 3 -----
	int t0[] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};

			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 510000;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!