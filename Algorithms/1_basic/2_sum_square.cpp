#include<iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++) {
		long long x1,x2;
		cin>>x1>>x2;
		ans+=(x1*x1);
		ans+=(x2*x2);
	}
	cout<<ans<<".000000000000000000000000000000"<<endl;
}
