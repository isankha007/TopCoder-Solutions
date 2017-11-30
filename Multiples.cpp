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

using namespace std;


class Multiples {
public:
	int number(int min, int max, int factor) {
		if(min==max){
			if(min<0)
			min*=-1;
			return min%factor==0;
		}
		
		if((min<=0 && max<=0) || (min >=0 && max>=0)){
			return calculate(min,max,factor);
		}
		else{
			return calculate(min,-1,factor)+calculate(0,max,factor);
		}
	}
	int calculate(int min,int max,int factor){
			if(min<=0 && max<=0){
				min*=-1;
				max*=-1;
				int temp = min;
				min=max;
				max=temp;
			}
			int rem = min%factor;
			if(rem!=0)
				min=min+factor-rem;
			if(min>max)
			return 0;
			rem = max%factor;
			max=max-rem;
			if(min==max)
				return 1;
			else if(min>max)
			return 1;
			else
			 	{
			 		int div1 = min/factor;
			 		int div2 = max/factor;
			 		return div2-div1+1;
				 }
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	Multiples *obj;
	int answer;
	obj = new Multiples();
	clock_t startTime = clock();
	answer = obj->number(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	int p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 0;
	p1 = 14;
	p2 = 5;
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 7;
	p1 = 24;
	p2 = 3;
	p3 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = -123456;
	p1 = 654321;
	p2 = 997;
	p3 = 780;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = -75312;
	p1 = 407891;
	p2 = 14;
	p3 = 34515;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
