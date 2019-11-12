#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>

using namespace std;

int main() {
	long long c,p,ri,ans;
	string r,temp;
	cin>>c>>p>>r;
	
	r.erase(std::remove(r.begin(), r.end(), '.'), r.end());
	ri=stol(r);;

	vector<long long> ci;

	for(int i=0;i<c;i++) {
		cin>>temp;
		temp.erase(std::remove(temp.begin(), temp.end(), '.'), temp.end());
		ci.push_back(stol(temp));
		if(i==0)ans=ci[0];
		if(ans<ci[i])ans=ci[i];
	}
	//sort(ci.begin(), ci.end());
	//reverse(ci.begin(), ci.end());
	for(int i=0;i<p;i++) {
		cin>>temp;
		temp.erase(std::remove(temp.begin(), temp.end(), '.'), temp.end());
		bool found = 0;
		long long dist=ri, templ=stol(temp);
		for(int j=0;j<c;j++) {
			//cout<<abs(pix-ci[j])<<" "<<ri<<endl;
			int diff=abs(templ-ci[j]);
			//cout<<diff<<" "<<dist<<endl;
			if((diff<dist) || (diff==dist && ans>=ci[j])) {
				ans=ci[j];
				dist=diff;
				found = 1;
			}
		}
		cout << fixed << setprecision(2);
		if(found==0)cout<<"none in range";
		else cout<<ans/100.00;
		cout<<endl;
	}
	return 0;
}
