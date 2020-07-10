#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	long long c,p,ri,ansl;
	string ans="";
	string r,temp;
	cin>>c>>p>>r;
	
	//r.erase(std::remove(r.begin(), r.end(), '.'), r.end());
	r[r.size()-3]='0';
	ri=stol(r);

	vector<long long> ci(c);
	vector<string> anss(c);

	for(int i=0;i<c;i++) {
		cin>>temp;
		//temp.erase(std::remove(temp.begin(), temp.end(), '.'), temp.end());
		temp[temp.size()-3]='0';
		ci[i]=stol(temp);
		temp[temp.size()-3]='.';
		anss[i]=temp;
		if(i==0)ansl=ci[0];
		if(ansl<ci[i])ansl=ci[i];
	}
	//sort(ci.begin(), ci.end());
	//reverse(ci.begin(), ci.end());
	for(int i=0;i<p;i++) {
		cin>>temp;
		//temp.erase(std::remove(temp.begin(), temp.end(), '.'), temp.end());
		temp[temp.size()-3]='0';
		bool found = 0;
		long long dist=ri, templ=stol(temp);
		for(int j=0;j<c;j++) {
			//cout<<abs(pix-ci[j])<<" "<<ri<<endl;
			long long diff=abs(templ-ci[j]);
			//cout<<diff<<" "<<dist<<endl;
			if((diff<dist) || (diff==dist && ansl>=ci[j])) {
				ans=anss[j];
				ansl=ci[j];
				dist=diff;
				found = 1;
			}
		}
		//cout << fixed << setprecision(2);
		if(found==0)cout<<"none in range";
		else cout<<ans;
		cout<<endl;
	}
	return 0;
}
