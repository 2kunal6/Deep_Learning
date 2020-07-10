#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int u,v,w,found=0;
		cin>>u>>v>>w;
		vector<string> ans(3);
		ans[0]="aaa";ans[1]="aaa";ans[2]="aaa";
		for(int i=-110;i<=110;i++) {
			for(int j=-110;j<=110;j++) {
				if(i==j)continue;
				for(int k=-110;k<=110;k++) {
					if(i==k || j==k)continue;
					if((((i*i)+(j*j)+(k*k))==w) && (i*j*k==v) && (i+j+k==u)) {
						vector<string> c(3);
						c[0]=std::to_string(i);
						c[1]=std::to_string(j);
						c[2]=std::to_string(k);
						ans[0]=c[0];ans[1]=c[1];ans[2]=c[2];
						found=1;
						break;
					}
				}
				if(found==1)break;
			}
			if(found==1)break;
		}
		if(ans[0]=="aaa")cout<<"empty set"<<endl;
		else {
			sort(ans.begin(), ans.end());
			cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
		}
	}
	return 0;
}
