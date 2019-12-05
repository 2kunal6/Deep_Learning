#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n,pc=0,ans=0;
	cin>>n;
	map<string, int> mp;
	map<string, int>::iterator it;
	vector<vector<int> > glv;
	vector<bool> eo(n, 0);
	for(int i=0;i<n;i++) {
		vector<int> lv;
		string ln,tmp="";
		getline(cin, ln);
		for(int j=0;j<ln.size();j++) {
			if(ln[j]==' ') {
				int numofp;
				it=mp[tmp];
				if(it==mp.end()) {
					mp[tmp]=pc;
					numofp=pc;
					pc++;
				} else numofp=it->second;
				lv.push_back(numofp);
				tmp="";
			} else tmp+=ln[j];
		}
		sort(lv.begin(), lv.end());
		glv.push_back(lv);
		if(tmp=="odd")eo[i]=1;
	}
	for(int i=0;i<1000000000;i++) {
		vector<bool> bit;
		int j=i,setbitssize=0;
		while(j) {
			if(j%2==0)bit.push_back(0);
			else bit.push_back(1);
			if(bit.size()>mp.size())break;
		}
		reverse(bit.begin(), bit.end());
		vector<int> setbits;
		for(j=0;j<bit.size();j++) {
			if(bit[j])setbits.push_back(j);
		}
		bool sbeo=1;
		setbitssize=setbits.size();
		if(setbitssize%2==0)sbeo=0;
		bool found=1;
		for(int j=0;j<n;j++) {
			int nf=0,s;
			vector<int> lv=glv[j];
			for(int k)

			if((nf%2==0 && eo[j]%2==1) || (nf%2==1 && eo[j]%2==0)) {
				found=0;
				break;
			}
		}
		if(found && setbitssize>ans)ans=setbitssize;
	}
	cout<<ans<<endl;
	return 0;
}
