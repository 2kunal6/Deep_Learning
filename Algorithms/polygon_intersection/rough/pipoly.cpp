#include <iostream> 
#include<vector>

using namespace std; 
  
struct Point {
	int x;
	int y;
};

vector<Point> polygon;

bool isInside(vector<point>int n, Point p) { 
	
}

int main() {
	int n,xmin, xmax, ymin, ymax;
	cin>>n;
	Point p;
	for(int i=0;i<n;i++) {
		cin>>p.x>>p.y;
		polygon.push_back(p);
		if(i==0) {
			xmin=xmax=polygon[i].x;
			ymin=ymax=polygon[i].y;
		}
		if(polygon[i].x<xmin)xmin=polygon[i].x;
		if(polygon[i].x>xmax)xmax=polygon[i].x;
		if(polygon[i].y<ymin)ymin=polygon[i].y;
		if(polygon[i].y>ymax)ymax=polygon[i].y;
	}
	long long ans=0;
	p.x=0;p.y=0;
	cout<<isInside(n,p)<<endl;
	for(int i=xmin;i<=xmax;i++) {
		for(int j=ymin;j<=ymax;j++) {
			p.x=i;
			p.y=j;
			if(isInside(n, p)) {
				ans++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;

}
