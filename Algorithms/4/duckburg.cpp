#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int k,n;
int dp[1002][102];
int cdp[1002][1002];
vector<int> v;

void calc_cdp() {
	for(int i=1;i<n;i++) {
		int lris=1,ls=0,rs=0;
		cdp[i-1][i]=v[i]-v[i-1];
		while(i-lris>=0 && i+lris<n) {
			ls+=(v[i]-v[i-lris]);
			rs+=(v[i+lris]-v[i]);
			cdp[i-lris][i+lris]=ls+rs;
			cdp[i-lris][i+lris+1]=ls+rs+(v[i+lris+1]-v[i]);
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

	/*for(int i=0;i<n+2;i++) {
		for(int j=0;j<n+2;j++)cout<<cdp[i][j]<<" ";
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++) {
		for(int m=1;m<=k;m++) {
			if(m>i)continue;
			if(m==1) {
				dp[i][m]=cdp[0][i-1];
				//cout<<i<<" "<<m<<" "<<dp[i][m]<<endl;
				continue;
			}
			int minval=1000000000;
			for(int j=m;j<=i;j++) {
				int tmp = dp[j-1][m-1]+cdp[j-1][i-1];
				if(tmp < minval)minval=tmp;
			}
			dp[i][m]=minval;
			//cout<<i<<" "<<m<<" "<<dp[i][m]<<endl;
		}
	}
	//cout<<dp[n][k]<<" "<<(25*n)-dp[n][k]<<endl;
	cout<<(25*n)-dp[n][k]<<endl;
	return 0;
}
