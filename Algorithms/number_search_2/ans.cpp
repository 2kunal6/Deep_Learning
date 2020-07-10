#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

bool fnd;
long long ans2,ans3,u,v,w;
vector<string> ans(3);

bool compare(vector<string> a, vector<string> b) {
	if(a[0]<b[0])return 1;
	if(a[0]>b[0])return 0;
	if(a[1]<b[1])return 1;
	if(a[1]>b[1])return 0;
	if(a[2]<b[2])return 1;
	return 0;
}

void find(long long i) {
	long long um=(u-i)*(u-i);
	long long temp=um-(w-(i*i)), lov, thirdn;
	lov=v/i;
	/*if(i==2 || i==-2) {
		cout<<temp<<" "<<lov<<endl;
	}*/
	if(2ll*lov!=temp)return;
	for(int j=1;j<=sqrt(abs(lov));j++) {
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
			ans[0]=to_string(i);
			ans[1]=to_string(ans2);
			ans[2]=to_string(ans3);
			break;
		}
	}

}

int main() {
	//clock_t begin = clock();
	int t;
	cin>>t;
	while(t--) {
		long long cbrtv;
		fnd=0;

		cin>>u>>v>>w;

		cbrtv=cbrt(v);
		for(int i=1;i<=cbrtv;i++) {
			if(i==0)continue;
			if(v%i!=0)continue;
			find(i);
			if(fnd==1)break;
			find(-i);
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
