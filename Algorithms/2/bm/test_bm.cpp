#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <bitset>
#include<map>

using namespace std;


int main() {
	clock_t begin = clock();
	map<string, vector<string> > mp;
	for(int i=-110;i<=110;i++) {
		for(int j=-110;j<=110;j++) {
			if(i==j)continue;
			for(int k=-110;k<=110;k++) {
				if(i==k || j==k)continue;
				int sm=i+j+k, pdt=i*j*k, ss=i*i+j*j+k*k;
				if(sm>12000 || sm<1 || pdt>12000 || pdt<1 || ss>12000 || ss<1)continue;
				string uvw=(to_string(i+j+k) + " " + to_string(i*j*k) + " " + to_string(i*i+j*j+k*k));
				vector<string> v(3);
				v[0]=to_string(i); v[1]=to_string(j); v[2]=to_string(k);
				sort(v.begin(), v.end());
				if(mp.find(uvw)==mp.end()) {
					mp[uvw]=v;
				} else {
					if(mp[uvw][0]==v[0])continue;
					if(mp[uvw][1]==v[1])continue;
					if(mp[uvw][2]==v[2])continue;
					cout<<uvw<<" "<<mp[uvw][0]<<" "<<mp[uvw][1]<<" "<<mp[uvw][2]<<"|"<<i<<" "<<j<<" "<<k<<endl;
				}
			}
		}
	}
	clock_t end = clock();
  	cout<<double(end - begin) / CLOCKS_PER_SEC<<endl;
}
