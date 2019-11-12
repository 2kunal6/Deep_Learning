#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	clock_t begin = clock();
	map<string, vector<string> > mp;
	/*for(int i=-110;i<=110;i++) {
		for(int j=-110;j<=110;j++) {
			if(i==j)continue;
			for(int k=-110;k<=110;k++) {
				if(i==k || j==k)continue;
				int ss=(i*i)+(j*j)+(k*k),pdt=i*j*k,sm=i+j+k;
				if(ss>12000 || ss<1 || pdt>12000 || pdt<1 || sm>12000 || sm<1)continue;

				cout<<i<<" "<<j<<" "<<k<<endl;
			
				vector<string> c(3);
				c[0]=std::to_string(i);
				c[1]=std::to_string(j);
				c[2]=std::to_string(k);

				sort(c.begin(), c.end());
				string ipt=std::to_string(sm)+" "+std::to_string(pdt)+" "+std::to_string(ss);
				
				//if(ss==5298)cout<<ipt<<endl;

				//if(ipt=="88 1136 5298")cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
				
				if(mp.find(ipt)==mp.end()) {
					mp[ipt]=c;
					continue;
				}

				vector<string> pv=mp[ipt];
					
				if(c[0]>pv[0])continue;
				if(c[1]>pv[1])continue;
				if(c[2]>pv[2])continue;
				mp[ipt]=c;
			}
		}
		//if(i%10==0)cout<<i<<endl;
	}*/
	clock_t end = clock();
  	cout<<double(end - begin) / CLOCKS_PER_SEC<<endl;
	int t;
	cin>>t;
	while(t--) {
		int u,v,w;
		cin>>u>>v>>w;
		string ips=std::to_string(u)+" "+std::to_string(v)+" "+std::to_string(w);
		if(mp.find(ips)!=mp.end()) {
			for(int i=0;i<3;i++)cout<<mp[ips][i]<<" ";
		}
		else cout<<"empty set";
		cout<<endl;
	}
	return 0;
}
