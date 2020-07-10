#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<bitset>

using namespace std;

int main() {
	int n,pc=0,ans=0,tot_names;
	string strn;
	getline(cin, strn);
	n=stoi(strn);
	map<string, int> mp;
	map<string, int>::iterator it;
	vector<bool> eo(n, 0);
	vector<bitset<10000> > rset(n);
	for(int i=0;i<n;i++) {
		string ln,tmp="";
		getline(cin, ln);
		vector<int> lv;
		for(int j=0;j<ln.size();j++) {
			if(ln[j]==' ') {
				int numofp;
				it=mp.find(tmp);
				if(it==mp.end()) {
					mp[tmp]=pc;
					numofp=pc;
					pc++;
				} else numofp=it->second;
				rset[i].set(numofp);
				tmp="";
			} else tmp+=ln[j];
		}
		if(tmp=="odd")eo[i]=1;
	}
	tot_names=mp.size();
	long long combi=1;
	while(1) {
		bitset<10000> comb(combi);
		bool corr=1;
		for(int j=0;j<n;j++) {
			int matches=(comb & rset[j]).count();
			if(matches%2 != eo[j]) {
				corr=0;
				break;
			}
		}
		if(corr==1 && comb.count()>ans) {
			ans=comb.count();
			break;
		}
		if(comb.count()==tot_names)break;
		combi++;
	}
	cout<<ans<<endl;
	return 0;
}
