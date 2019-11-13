#include<iostream>
#include<vector>

using namespace std;

long long kadane(vector<long long> v) {
	long long ans=-10000000000ll,sum=0;
	for(int i=0;i<v.size();i++) {
		sum+=v[i];
		if(sum>ans)ans=sum;
		if(sum<0)sum=0;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	long long mt[n][n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)cin>>mt[i][j];
	}
	long long ans=0;
	for(int i=0;i<n;i++) {
		vector<long long> temp(n,0);
		for(int j=i;j<n;j++) {
			for(int k=0;k<n;k++)temp[k]+=mt[k][j];
			long long val=kadane(temp);
			if(val>ans)ans=val;
		}
	}
	cout<<ans<<endl;
	return 0;
}
