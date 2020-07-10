#include<iostream>
#include<stack>
#include<bitset>
#include<vector>

using namespace std;

int vlen;
vector<bitset<2> > v;

bool bal(stack<bitset<2> > ls, int ind) {
	if(ind==vlen)return ls.empty();
	bitset<2> top;
	bool res;
	if(v[ind][0]==1) {
		ls.push(v[ind]);
		return bal(ls, ind+1);
	} else if(v[ind][1]==1) {
		if(ls.empty())return 0;
		top=ls.top();
		ls.pop();
		return bal(ls, ind+1);
	} else {
		stack<bitset<2> > tmp=ls;
		tmp.push(v[ind]);
		res=bal(tmp, ind+1);
		if(res)return 1;
		if(ls.empty())return 0;
		ls.pop();
		return bal(ls, ind+1);
	}
}

int main() {
	char c;
	stack<bitset<2> > s;
	while(std::cin>>c) {
		if(c=='(')v.push_back(bitset<2>(1));
		if(c==')')v.push_back(bitset<2>(2));
		if(c=='?')v.push_back(bitset<2>(0));
	}
	vlen=v.size();
	if(bal(s, 0))cout<<1;
	else cout<<0;
	cout<<endl;
	return 0;
}
