#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <bitset>
#include<map>
#include<limits>

using namespace std;


int main() {
	cout<<1+2+2236067977ll<<" "<<1*2*2236067977ll<<" "<<1+4+(2236067977ll*2236067977ll)<<endl;

	//vector<int> v(1,5, 10);
	//auto it = v.lower_bound()
	//for(int i=0;i<800000;i++)cout<<"1000000000000000000000000000000000000"<<i<<".00"<<endl;
	//cout<<stol("100000000000000000000000000.05")<<endl;
	/*cout<<std::numeric_limits<float>::max()<<endl;
	cout<<std::numeric_limits<float>::min()<<endl;
	cout<<std::numeric_limits<long long>::max()<<endl;
	cout<<std::numeric_limits<long long>::min()<<endl;
	*///cout<<stol("100.05");
	/*clock_t begin = clock();
	map<string, int > mp;
	for(int i=-110;i<=110;i++) {
		for(int j=-110;j<=110;j++) {
			if(i==j)continue;
			for(int k=-110;k<=110;k++) {
				if(i==k || j==k)continue;
				string uvw=(to_string(i+j+k) + " " + to_string(i*j*k) + " " + to_string(i*i+j*j+k*k));
				if(mp.find(uvw)!=mp.end()) {
					mp[uvw]++;
					if(mp[uvw]>6)cout<<"FOUND:"<<uvw<<endl;
				} else {
					mp[uvw]=1;
				}
			}
		}
		if(i%10==0)cout<<i<<endl;
	}
	cout<<mp.begin()->second<<endl;
	map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            if(it->second!=6)cout<<it->first<<endl;
        }
	clock_t end = clock();
  	cout<<double(end - begin) / CLOCKS_PER_SEC<<endl;*/

	/*char a='0',b='1';
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;*/
	/*int x;
	x=-1.2/0.75;
	cout<<x<<endl;
	x=1.2;
	cout<<x<<endl;*/

	/*string a = std::to_string(12);
	string b = std::to_string(2);
	vector<string> v;
	v.push_back(b);
	v.push_back(a);
	sort(v.begin(), v.end());
	cout<<v[0]<<" "<<v[1]<<endl;*/

	/*string s = "10000000000000.05"; 
	cout<<s<<endl;
	s.erase(std::remove(s.begin(), s.end(), '.'), s.end());
	cout<<s<<endl;
	long long l=stol(s);
	cout<<l<<" "<<l+5<<endl;*/

	/*int x;
	cin>>x;
	cout<<x<<" "<<x+5<<endl;*/

	/*string a="-2", b="-10";
	std::cout << std::lexicographical_compare(b.begin(), b.end(), a.begin(), a.end())<<endl;*/
	return 0;
}
