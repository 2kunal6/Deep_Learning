#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int k,n;
int dp[1001][101];
int cdp[1001][1001];
vector<int> v;

void calc_cdp() {
	for(int i=0;i<n;i++) {
		int lris=1,ls=0,rs=0;
		cdp[i][i]=0;
		while(i-lris>=0 && i+lris<n) {
			ls+=(v[i-lris]);
			rs+=(v[i+lris]);
			cdp[i-lris][i+lris]=ls+rs;
			lris++;
		}
	}
}

int main() {
	int x;
	cin>>k>>n;
	for(int i=0;i<n;i++) {
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	calc_cdp();
	for(int i=1;i<=n;i++) {
		for(int m=1;m<=k;m++) {
			int minval=1000000000;
			for(int j=m;j<=i;j++) {
				int tmp = dp[j-1][m-1]+cdp[j][i];
				if(minval < tmp)minval=tmp;
			}
			dp[i][m]=minval;
		}
	}
	cout<<(25*n)-dp[n][k]<<endl;
	return 0;
}
