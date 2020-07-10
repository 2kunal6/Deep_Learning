#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main() {
	long long c,p,ri,ans;
	double r,temp;
	cin>>c>>p>>r;
	
	ri=r*100;;

	vector<long long> ci;

	for(int i=0;i<c;i++) {
		cin>>temp;
		ci.push_back(temp*100);
		if(i==0)ans=ci[0];
		if(ans<ci[i])ans=ci[i];
	}
	for(int i=0;i<c;i++)cout<<ci[i]<<" ";
	cout<<endl;
	//sort(ci.begin(), ci.end());
	//reverse(ci.begin(), ci.end());
	for(int i=0;i<p;i++) {
		cin>>temp;
		bool found = 0;
		long long dist=ri, templ=temp*100;
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
