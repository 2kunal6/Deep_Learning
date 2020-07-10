#include<iostream>
#include<algorithm>

using namespace std;

int rg[1001][1001],n,m;
long long dp[1001][1001];

int backtrack(int a, int b) {
	if(a==n-1 && b==m-1) {
		dp[a][b]=rg[a][b];
		return rg[a][b];
	}
	long long a1=dp[a+1][b], b1=dp[a][b+1];
	if(a1<0)a1=backtrack(a+1, b);
	if(b1<0)b1=backtrack(a, b+1);
	if(a==n-1) {
		return rg[a][b]+b1;
	}
	if(b==m-1) {
		return rg[a][b]+a1;
	}
	dp[a][b]=rg[a][b]+max(b1,a1);
	return dp[a][b];
}
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)cin>>rg[i][j];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)dp[i][j]=-1;
	}
	cout<<backtrack(0,0)<<endl;
	return 0;
}
