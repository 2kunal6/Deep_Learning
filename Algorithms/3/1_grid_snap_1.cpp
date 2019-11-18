#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	//cout<<0.30/0.10<<" "<<0.3/0.1<<endl;
	
	int n,xd,yd,iwid,ix,iy;
	cin>>n;
	float wid,x,y;
	cin>>wid;
	iwid=wid*100;
	for(int i=0;i<n;i++) {
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
