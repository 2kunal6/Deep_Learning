#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
vector<pair<int, int> > es;
vector<int> pn;

bool isposs() {
	//for(int i=0;i<pn.size();i++)cout<<pn[i]<<" ";
	//cout<<endl;
	for(int i=0;i<m;i++) {
		if((find(pn.begin(), pn.end(), es[i].first)==pn.end()) && (find(pn.begin(), pn.end(), es[i].second)==pn.end()))return 0;
	}
	return 1;
}

int main() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		es.push_back(make_pair(x, y));
	}
	/*for(int k=1;k<7;k++) {
		int set = (1 << k) - 1;
		int limit = (1 << n);
		while (set < limit) {
			int c = set & -set; 
        		int r = set + c; 
        		set = (((r^set) >> 2) / c) | r; 
    		} 
	}*/
	for(int i=0;i<n;i++) {
		pn.push_back(i);
		if(isposs()) {cout<<"possible"<<endl;return 0;}
		pn.pop_back();
	}
	for(int i=0;i<n-1;i++) {
		pn.push_back(i);
		for(int j=i+1;j<n;j++) {
			pn.push_back(j);
			if(isposs()) {cout<<"possible"<<endl;return 0;}
			pn.pop_back();
		}
		pn.pop_back();
	}
	for(int i=0;i<n-2;i++) {
		pn.push_back(i);
		for(int j=i+1;j<n-1;j++) {
			pn.push_back(j);
			for(int k=j+1;k<n;k++){
				pn.push_back(k);
				if(isposs()) {cout<<"possible"<<endl;return 0;}
				pn.pop_back();
			}
			pn.pop_back();
		}
		pn.pop_back();
	}
	for(int i=0;i<n-3;i++) {
		pn.push_back(i);
		for(int j=i+1;j<n-2;j++) {
			pn.push_back(j);
			for(int k=j+1;k<n-1;k++){
				pn.push_back(k);
				for(int l=k+1;l<n;l++) {
					pn.push_back(l);
					if(isposs()) {cout<<"possible"<<endl;return 0;}
					pn.pop_back();
				}
				pn.pop_back();
			}
			pn.pop_back();
		}
		pn.pop_back();
	}
	for(int i=0;i<n-4;i++) {
		pn.push_back(i);
		for(int j=i+1;j<n-3;j++) {
			pn.push_back(j);
			for(int k=j+1;k<n-2;k++){
				pn.push_back(k);
				for(int l=k+1;l<n-1;l++) {
					pn.push_back(l);
					for(int m=l+1;m<n;m++) {
						pn.push_back(m);
						if(isposs()) {cout<<"possible"<<endl;return 0;}
						pn.pop_back();
					}
					pn.pop_back();
				}
				pn.pop_back();
			}
			pn.pop_back();
		}
		pn.pop_back();
	}
	for(int i=0;i<n-5;i++) {
		pn.push_back(i);
		for(int j=i+1;j<n-4;j++) {
			pn.push_back(j);
			for(int k=j+1;k<n-3;k++){
				pn.push_back(k);
				for(int l=k+1;l<n-2;l++) {
					pn.push_back(l);
					for(int m=l+1;m<n-1;m++) {
						pn.push_back(m);
						for(int nn=m+1;nn<n;nn++) {
							pn.push_back(nn);
							if(isposs()) {cout<<"possible"<<endl;return 0;}
							pn.pop_back();
						}
						pn.pop_back();
					}
					pn.pop_back();
				}
				pn.pop_back();
			}
			pn.pop_back();
		}
		pn.pop_back();
	}
	cout<<"impossible"<<endl;
	return 0;
}
