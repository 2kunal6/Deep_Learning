#include<iostream>
#include<iomanip>
#include<map>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

vector<long long> pnt,zos;
int d;

double dist(vector<long long> tv) {
	long long ans=0,tmp;
	for(int i=0;i<d;i++) {
		tmp=pnt[i]-tv[i];
		ans+=(tmp*tmp);
	}
	return (double)sqrt(ans);
}

int main() {
	long long iwid, dcnt=0;
	cin>>d;
	pnt.resize(d);
	zos.resize(d);
	double wid,x;
	cin>>wid;
	iwid=wid*1000;
	multimap<double, vector<long long> > mp;
	multimap<double, vector<long long> >::iterator low,up,it;

	while(cin>>x) {
		pnt[dcnt]=x*1000;
		dcnt++;
		if(dcnt%d!=0)continue;
		dcnt=0;
		
		double dtc=dist(zos);
		if(mp.size()==0) {
			mp.insert(pair<double, vector<long long> >(dtc, pnt));
			continue;
		}
		up=mp.upper_bound(dtc+iwid);
		if(dtc<=iwid)low=mp.begin();
		else low=mp.lower_bound(dtc-iwid);
		bool found=0;
		
		//cout<<dtc<<":";	
		
		for(it=low;it!=up;it++) {
			//cout<<it->second[0]<<" "<<it->second[1]<<endl;
			if(dist(it->second)<=iwid) {
				found=1;
				break;
			}
		}
		if(found==0) {
			mp.insert(pair<double, vector<long long> >(dtc, pnt));
		}
	}
	cout<<mp.size()<<endl;
	return 0;
}
