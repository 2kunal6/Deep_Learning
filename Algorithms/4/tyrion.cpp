#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int tot_names;
vector<vector<int> > glv;
void create_row_bit() {

}
int main() {
	int n,pc=0,ans=0;
	cin>>n;
	map<string, int> mp;
	map<string, int>::iterator it;
	vector<bool> eo(n, 0);
	for(int i=0;i<n;i++) {
		vector<int> lv;
		string ln,tmp="";
		getline(cin, ln);
		for(int j=0;j<ln.size();j++) {
			if(ln[j]==' ') {
				int numofp;
				it=mp.find(tmp);
				if(it==mp.end()) {
					mp[tmp]=pc;
					numofp=pc;
					pc++;
				} else numofp=it->second;
				lv.push_back(numofp);
				tmp="";
			} else tmp+=ln[j];
		}
		glv.push_back(lv);
		if(tmp=="odd")eo[i]=1;
	}
	tot_names=mp.size();
	vector<bitset<2000> > rset;
	for(int i=0;i<n;i++) {
		for(int j=0;j<glv[i].size();j++) {
			rset[i].set(glv[i][j]-1);
		}
	}
	for(int i=0;i<1000000000;i++) {
		bitset<2000> comb(i);
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
