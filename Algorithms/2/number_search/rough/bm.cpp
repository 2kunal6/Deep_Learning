#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long u,v,w,found=0;
		cin>>u>>v>>w;
		for(long long i=1;i<=110;i++) {
			for(long long j=i+1;j<=110;j++) {
				for(long long k=j+1;k<=110;k++) {
					if((((i*i)+(j*j)+(k*k))==w) && (i*j*k==v) && (i+j+k==u)) {
						//std::to_string(12)
						cout<<i<<" "<<j<<" "<<k<<endl;
						found=1;
						break;
					}
				}
				if(found==1)break;
			}
			if(found==1)break;
		}
		if(found==0)cout<<"empty set"<<endl;
	}
	return 0;
}
