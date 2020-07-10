#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	int area=0;
	for(int i=0;i<n-1;i++)area+=(x[i]*y[i+1]-x[i+1]*y[i]);
	area+=(x[n-1]*y[0]-x[0]*y[n-1]);
	
	cout<<abs(0.5*area)<<endl;
	//if(area%2==0)cout<<".0";
	//cout<<endl;
	return 0;
}
