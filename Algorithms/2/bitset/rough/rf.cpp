#include<iostream>
#include<vector>

using namespace std;

int main() {
	int r;
	cin>>r;
	/*vector<string> pf;
	string temp;
	for(int i=0;i<r;i++) {
		cin>>temp;
		pf.push_back(temp);
	}*/
	char pf[r][r];
	for(int i=0;i<r;i++)for(int j=0;j<r;j++)cin>>pf[i][j];
	/*int comb[r+1];
	comb[2]=1;
	for(int i=3;i<=r;i++)comb[i]=(comb[i-1]+i-1);
	//for(int i=3;i<=r;i++)cout<<comb[i]<<" ";
	long long ans=0;
	for(int i=0;i<r;i++) {
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
	cout<<ans<<endl;*/
	long long ans=0;
	for (int i = 0; i < r - 1; i++) {
            vector<int> ones;
            for (int k = 0; k < r; k++) if (pf[i][k]=='1') ones.push_back(k);
            for (int j = i + 1; j < r; j++) {
                long long cnt = 0;
                for (int l = 0; l < ones.size(); l++) {
                    if (pf[j][ones[l]]=='1') cnt++;
                }
                ans += cnt * (cnt - 1) / 2;
            }
	    //if(i%100==0)cout<<ans<<endl;
        }
        cout<<ans<<endl;
	return 0;
}
