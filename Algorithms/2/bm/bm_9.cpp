#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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
		int u,v,w;
		cin>>u>>v>>w;
		vector<string> ans(3);
		ans[0]="aaaa";ans[1]="aaaaa";ans[2]="aaaa";
		for(int i=-110;i<=110;i++) {
			for(int j=-110;j<=110;j++) {
				if(i==j)continue;
				//if(i==1 && j==2)cout<<u-(i+j)<<endl;
				int k=u-(i+j);
				if(k==0 || i==k || j==k)continue;
				if(i*j*k!=v)continue;
				if(i*i+j*j+k*k!=w)continue;
				
				ans[0]=std::to_string(i);
				ans[1]=std::to_string(j);
				ans[2]=std::to_string(k);
				break;
			}
			if(ans[0]!="aaaa")break;
		}
		if(ans[0]=="aaaa")cout<<"empty set";
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
