#include<iostream>
#include<bitset>
#include<vector>
#include<string>

using namespace std;

int main() {
	int r;
	cin>>r;
	vector<bitset<2000> > pf(r);
	for(int i=0;i<r;i++) {
		cin>>pf[i];
	}
	
	long long ans=0;
	for (int i = 0; i < r - 1; i++) {
            for (int j = i + 1; j < r; j++) {
                long long cnt = (pf[i]&pf[j]).count();
                ans += cnt * (cnt - 1) / 2;
            }
        }
        cout<<ans<<endl;
	return 0;
}
