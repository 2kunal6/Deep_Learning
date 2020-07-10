#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int n,xd,yd;
	cin>>n;
	double wid,x,y;
	cin>>wid;
	for(int i=0;i<n;i++) {
		cin>>x>>y;
		xd=x/wid;
		yd=y/wid;
		if(x>0 && y>0) {
			//if(yd*wid==y)yd--;
			//if(xd*wid==x)xd--;
			//cout<<xd*wid<<" "<<yd*wid<<endl;
		} else if(x>0 && y<0) {
			//if(xd*wid==x)xd--;
			if(yd*wid!=y)yd--;
			//cout<<xd*wid<<" "<<yd*wid<<endl;
		} else if(x<0 && y<0) {
			if(xd*wid!=x)xd--;
			if(yd*wid!=y)yd--;
			//cout<<xd*wid<<" "<<yd*wid<<endl;
		} else {
			//if(yd*wid==y)yd--;
			if(xd*wid!=x)xd--;
			//cout<<xd*wid<<" "<<yd*wid<<endl;
		}
		cout << fixed << setprecision(2);
		cout<<xd*wid<<" "<<yd*wid<<endl;
	}
	return 0;
}
