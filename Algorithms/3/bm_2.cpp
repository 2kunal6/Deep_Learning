#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

bool compare(vector<string> a, vector<string> b) {
	if(a[0]<b[0])return 1;
	if(a[0]>b[0])return 0;
	if(a[1]<b[1])return 1;
	if(a[1]>b[1])return 0;
	if(a[2]<b[2])return 1;
	return 0;
}

int main() {
	//clock_t begin = clock();
	int t;
	cin>>t;
	while(t--) {
		long long u,v,w,cbrtv;
		vector<string> ans(3);
		bool fnd=0;
		
		cin>>u>>v>>w;

		cbrtv=cbrt(v);
		for(int i=-cbrtv;i<=cbrtv;i++) {
			if(i==0)continue;
			if(v%i!=0)continue;
			long long temp=u-i-(w-(i*i)), lov, thirdn,ans2,ans3;
			if(2ll*v != temp)continue;
			lov=v/i;
			for(int j=1;j<=sqrt(lov);j++) {
				if(lov%j==0) {
					thirdn=lov/j;
					if(i+j+thirdn==u) {
						ans2=j;ans3=thirdn;
						fnd=1;
					} else if(i-j+thirdn==u) {
						ans2=-j;ans3=thirdn;
						fnd=1;
					} else if(i+j-thirdn==u) {
						ans2=j;ans3=-thirdn;
						fnd=1;
					} else if(i-j-thirdn==u) {
						ans2=-j;ans3=-thirdn;
						fnd=1;
					}
				}
				if(fnd==1) {
					break;
					ans[0]=to_string(i);
					ans[1]=to_string(ans2);
					ans[2]=to_string(ans3);
				}
			}
			if(fnd==1)break;
		}
		if(fnd==0)cout<<"empty set";
		else {
			vector<string> final_ans=ans;
			do {
				if(compare(ans, final_ans))final_ans=ans;
  			} while ( std::next_permutation(ans.begin(), ans.end()) );
			cout<<final_ans[0]<<" "<<final_ans[1]<<" "<<final_ans[2];
		}
		cout<<endl;
	}
	//clock_t end = clock();
  	//cout<<double(end - begin) / CLOCKS_PER_SEC<<endl;
	return 0;
}
