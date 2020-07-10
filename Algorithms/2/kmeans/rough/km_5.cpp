#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSmaller(string str1, string str2) {
	
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2)return true; 
    if (n2 < n1)return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return false; 
} 
  
// Function for find difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i=0; i<n2; i++) 
    { 
        // Do school mathematics, compute difference of 
        // current digits 
          
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

int main() {
	long long c,p;
	string ans="none in range";
	string r,temp;
	cin>>c>>p>>r;
	
	//r[r.size()-3]='0';

	vector<string> ctr(c);
	for(int i=0;i<c;i++) {
		cin>>ctr[i]=temp;
		if(i==0)ans=ci[0];dd
		if(ansl<ci[i])ansl=ci[i];
	}
	for(int i=0;i<p;i++) {
		cin>>temp;
		temp[temp.size()-3]='0';
		bool found = 0;
		long long dist=ri, templ=stol(temp);
		for(int j=0;j<c;j++) {
			int diff=abs(templ-ci[j]);
			if((diff<dist) || (diff==dist && ansl>=ci[j])) {
				ans=anss[j];
				ansl=ci[j];
				dist=diff;
				found = 1;
			}
		}
		if(found==0)cout<<"none in range";
		else cout<<ans;
		cout<<endl;
	}
	return 0;
}
