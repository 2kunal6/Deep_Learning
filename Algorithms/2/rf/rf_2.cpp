#include<iostream>
#include<string>
#include<vector>

using namespace std;

int rc[2001][2001];
int main() {
	int r;
	cin>>r;
	vector<string> pf;
	string temp;
	for(int i=0;i<r;i++) {
		cin>>temp;
		pf.push_back(temp);
	}
	long long ans=0;
	for(int i=0;i<r;i++) {
		for(int j=i+1;j<r;j++) {
			if(pf[i][i]=='1' && rc[0][j]=='1')
		}
	}
		for(int j=i+1;j<r;j++) {
			int match=0;
			for(int k=0;k<r;k++) {
				//cout<<pf[i][k]<<" "<<pf[j][k]<<endl;
				if(pf[i][k]=='1' && pf[j][k]=='1')match++;
			}
			//cout<<match<<" "<<comb[match]<<endl;
			if(match>1)ans+=comb[match];
		}
	}
	cout<<ans<<endl;
	return 0;
}
