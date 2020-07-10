#include<iostream>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

int main() {
	clock_t begin = clock();
	long long x=(long long)2000;
	x*=(long long)2000;
	x*=(long long)500;
	for(int i=0;i<x;i++){}	
	clock_t end = clock();
  		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout<<elapsed_secs<<endl;
	/*int r;
	cin>>r;
	vector<string> pf;
	string temp;
	for(int i=0;i<r;i++) {
		cin>>temp;
		pf.push_back(temp);
	}
	int comb[r+1];
	comb[2]=1;
	for(int i=3;i<=r;i++)comb[i]=(comb[i-1]+i-1);
	//for(int i=3;i<=r;i++)cout<<comb[i]<<" ";
	long long ans=0;
	cout<<"here"<<endl;
	for(int i=0;i<r;i++) {
		for(int j=i+1;j<r;j++) {
			int match=0;
			for(int k=0;k<r;k++) {
				//cout<<pf[i][k]<<" "<<pf[j][k]<<endl;
				if(pf[i][k]=='1' && pf[j][k]=='1')match++;
			}
			//cout<<match<<" "<<comb[match]<<endl;
			if(match>1)ans+=comb[match];
		}
		clock_t end = clock();
  		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		if(i==5)cout<<elapsed_secs<<endl;
	}
	cout<<ans<<endl;*/
	return 0;
}
