#include<iostream>
#include<iomanip>
#include<map>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

vector<double> pnt,zos;
int d;

double dist(vector<double> tv) {
	double ans=0,tmp;
	for(int i=0;i<d;i++) {
		tmp=pnt[i]-tv[i];
		ans+=(tmp*tmp);
	}
	return sqrt(ans);
}

int main() {
	long long  dcnt=0;
	cin>>d;
	pnt.resize(d);
	zos.resize(d);
	double iwid,wid,x;
	cin>>wid;
	iwid=wid;
	iwid=iwid*iwid;
	multimap<double, vector<double> > mp;
	multimap<double, vector<double> >::iterator low,up,it;

	while(cin>>x) {
		pnt[dcnt]=x;
		dcnt++;
		if(dcnt%d!=0)continue;
		dcnt=0;
		
		double dtc=dist(zos);
		if(mp.size()==0) {
			mp.insert(pair<double, vector<double> >(dtc, pnt));
			continue;
		}
		up=mp.upper_bound(dtc+iwid);
		if(dtc<=iwid)low=mp.begin();
		else low=mp.lower_bound(dtc-iwid);
		bool found=0;
		
		//cout<<dtc+iwid<<" "<<dtc-iwid<<endl;
		//cout<<pnt[0]<<" "<<pnt[1]<<" "<<dtc<<" "<<low->second[0]<<" "<<low->second[1]<<endl;
			
		for(it=low;it!=up;it++) {
			//cout<<pnt[0]<<" "<<pnt[1]<<" "<<it->second[0]<<" "<<it->second[1]<<endl;
			if(dist(it->second)<=iwid) {
				found=1;
				break;
			}
		}
		if(found==0) {
			mp.insert(pair<double, vector<double> >(dtc, pnt));
		}
	}
	cout<<mp.size()<<endl;
	return 0;
}
