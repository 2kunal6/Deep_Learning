#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
	int c,p;
	double ri,temp,ans;
	cin>>c>>p>>ri;

	vector<double> ci(c);

	for(int i=0;i<c;i++) {
		cin>>ci[i];
	}
	sort(ci.begin(), ci.end());
	for(int i=0;i<p;i++) {
		cin>>temp;
		double diff=ri;	
		bool found=0;
		vector<double>::iterator it = lower_bound(ci.begin(), ci.end(), temp); 
		int pos=it-ci.begin();
		//cout<<pos<<endl;
		if(pos<c && abs(ci[pos]-temp)<=ri) {
			ans=ci[pos];
			diff=abs(ci[pos]-temp);
			found=1;
		}
		if(pos>0 && abs(temp-ci[pos-1])<=diff) {
			ans=ci[pos-1];
			found=1;
		}

		
		cout << fixed << setprecision(2);
		if(found==0)cout<<"none in range";
		else cout<<ans;
		cout<<endl;
	}
	return 0;
}
