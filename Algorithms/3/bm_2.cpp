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
		long long u,v,w;
		cin>>u>>v>>w;
		
		/*if(v>10000000000ll) {
			cout<<"empty set"<<endl;
			continue;
		}*/

		vector<string> ans(3);
		vector<long long> fs;

		for(long long i=1;i<sqrt(v);i++) {
			if(v%i==0) {
				fs.push_back(i);
				fs.push_back(-1*i);
				fs.push_back(v/i);
				fs.push_back(-1*(v/i));
			}
		}
		long long sqrtv=sqrt(v);
		if(sqrtv*sqrtv==v) {
			fs.push_back(sqrtv);
			fs.push_back(-1*sqrtv);
		}

		sort(fs.begin(), fs.end());

		bool fnd=0;
		for(int i=0;i<fs.size();i++) {
			for(int j=i+1;j<fs.size();j++) {
				for(int k=j+1;k<fs.size();k++) {
					if(fs[i]+fs[j]+fs[k]==u && (fs[i]*fs[j]*fs[k]==v) && (((fs[i]*fs[i])+(fs[j]*fs[j])+(fs[k]*fs[k]))==w)) {
						ans[0]=std::to_string(fs[i]);
						ans[1]=std::to_string(fs[j]);
						ans[2]=std::to_string(fs[k]);
						fnd=1;
						break;
					}
					//if(fs[i]+fs[j]+fs[k]>u || (((fs[i]*fs[i])+(fs[j]*fs[j])+(fs[k]*fs[k]))>w))break;
				}
				if(fnd==1)break;
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
