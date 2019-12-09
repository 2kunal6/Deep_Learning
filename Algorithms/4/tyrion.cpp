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
	vector<bitset<30> > rset(n);
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
	for(int i=0;i<1000000000;i++) {
		bitset<30> comb(i);
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
		}
		if(comb.count()==tot_names)break;
	}
	cout<<ans<<endl;
	return 0;
}
