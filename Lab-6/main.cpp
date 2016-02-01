#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void PrintOptimalParens(vector< vector<int> > &s, int i, int j);

void MatrixChainOrder(int * p, int n) {
	int counts = 0, i, j, k, L, q;
	int m[n+1][n+1];
	vector <vector<int> > s;
	s.resize(n+1, vector<int>(n+1,0));
	for(i = 1; i <= n; i++){
		m[i][i] = 0;
	}
	for(L = 2; L <= n; L++) {
		for(i = 1; i <= n - L +1; i++) {
			j = i + L -1;
			m[i][j] = INT_MAX;
			for(k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout << m[1][n] <<endl;
	PrintOptimalParens(s,1,n);
	cout<<endl;
}

void PrintOptimalParens(vector< vector<int> > &s, int i, int j) {
	if(i == j) {
		cout << "A" << (i-1);
	} else {
		cout << "(";
		PrintOptimalParens(s,i,s[i][j]);
		PrintOptimalParens(s,s[i][j]+1,j);
		cout << ")";
	}
}

int main() {
	int count = 0, dimensions = 0;
	cin >> dimensions;
	int p[dimensions+1];
	for(int i = 0; i <= dimensions;i++) {
		cin >> p[i];
	}
	MatrixChainOrder(p, dimensions);
	return 0;
}
