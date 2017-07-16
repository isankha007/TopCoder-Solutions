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


class SymmetryDetection {
public:
	string detect(vector <string> board) {
		
		bool hor=true;
		bool ver=true;
		int n = board.size();
		int m = board[0].size(); 
		
		/* Horizontal symmetry */
		
		int up,down,left,right;
		
		if(n%2==0){
			up=n/2-1;
			down=n/2;
		}
		else{
			up=n/2-1;
			down=n/2+1;
		}
		if(m%2==0){
			left=m/2-1;
			right=m/2;
		}
		else{
			left=m/2-1;
			right=m/2+1;
		}	
		
		for(int i = 0 ; i<m ; i++){
			int j = up;
			int k = down;
			for( ; j>=0 && k<n ; j--,k++){
				if(board[j][i]!=board[k][i]){
					hor=false;
					break;
				}
			}
		}
		
		/* Vertical Symmetry*/
		
		for(int i = 0 ; i< n ; i++){
			int j = left;
			int k = right;
			for( ; j>=0 && k < m ; j--,k++){
				if(board[i][j]!=board[i][k]){
					ver=false;
					break;
				}
			}
		}
		
		if(hor && ver)
		return "Both";
		if(hor)
		return "Horizontally symmetric";
		if(ver)
		return "Vertically symmetric";
		return "Neither";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SymmetryDetection *obj;
	string answer;
	obj = new SymmetryDetection();
	clock_t startTime = clock();
	answer = obj->detect(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	vector <string> p0;
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"#####",".###.","..#.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Vertically symmetric";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"#####","#...#","#####"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Both";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"#..","#..","#.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Horizontally symmetric";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"#.",".#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Neither";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"#######","#..#..#","#######","...#...","#######"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Vertically symmetric";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"#.....#","#.....#","#######","#...#.#","#.....#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Neither";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"#######.#.....#","...#....#.....#",".#####..#######","...#....#.....#","#######.#.....#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Horizontally symmetric";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	string t0[] = {"."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Both";
	all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
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
