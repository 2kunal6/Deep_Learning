#include<iostream>
#include<iomanip>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> pnt,zos;
int d;

long long dist(vector<long long> tv) {
	long long ans=0,tmp;
	for(int i=0;i<d;i++) {
		tmp=pnt[i]-tv[i];
		ans+=(tmp*tmp);
	}
	return ans;
}

int main() {
	long long iwid, dcnt=0;
	cin>>d;
	pnt.resize(d);
	zos.resize(d);
	double wid,x;
	cin>>wid;
	iwid=wid*1000;
	iwid=iwid*iwid;
	multimap<long long, vector<long long> > mp;
	multimap<long long, vector<long long> >::iterator low,up,it;

	while(cin>>x) {
		pnt[dcnt]=x*1000;
		dcnt++;
		if(dcnt%d!=0)continue;
		dcnt=0;
		
		long long dtc=dist(zos);
		if(mp.size()==0) {
			mp.insert(pair<long long, vector<long long> >(dtc, pnt));
			continue;
		}
		up=mp.upper_bound(dtc+iwid);
		if(dtc<=iwid)low=mp.begin();
		else low=mp.lower_bound(dtc-iwid);
		bool found=0;
		
		cout<<dtc<<":";	
		
		for(it=low;it!=up;it++) {
			cout<<it->second[0]<<" "<<it->second[1]<<endl;
			if(dist(it->second)<=iwid) {
				found=1;
				break;
			}
		}
		if(found==0) {
			mp.insert(pair<long long, vector<long long> >(dtc, pnt));
		}
	}
	cout<<mp.size()<<endl;
	return 0;
}
