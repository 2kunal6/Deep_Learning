#include<iostream>
#include<iomanip>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	long long d, ans=0, iwid;
	cin>>d;
	double wid,x;
	cin>>wid;
	iwid=wid*1000;
	while(cin>>x) {
		cin>>x>>y;
		ix=x*100;
		iy=y*100;
		cout << fixed << setprecision(2);
		if(ix%iwid!=0) {
			xd=ix/iwid;
			if(ix<0)xd--;
			cout<<(xd*iwid)/100.00;
		} else {
			cout<<x;
		}
		cout<<" ";
		if(iy%iwid!=0) {
			yd=iy/iwid;
                        if(iy<0)yd--;
                        cout<<(yd*iwid)/100.00;
		} else {
			cout<<y;
		}
		cout<<endl;
	}
	return 0;
}
