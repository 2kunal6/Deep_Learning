#include <iostream> 
#include<vector>
#include<cmath>
// Copyright 2000 softSurfer, 2012 Dan Sunday
using namespace std; 
  
struct Point {
	int x;
	int y;
};

vector<Point> pgn;

int isLeft( Point P0, Point P1, Point P2 ) {
    return ( (P1.x - P0.x) * (P2.y - P0.y) - (P2.x -  P0.x) * (P1.y - P0.y) );
}

int cn_PnPoly( Point P, int n ) {
    int    cn = 0;
    for (int i=0; i<n; i++) {
       if (((pgn[i].y <= P.y) && (pgn[i+1].y > P.y)) || ((pgn[i].y > P.y) && (pgn[i+1].y <=  P.y))) { // a downward crossing
            float vt = (float)(P.y  - pgn[i].y) / (pgn[i+1].y - pgn[i].y);
            if (P.x <  pgn[i].x + vt * (pgn[i+1].x - pgn[i].x)) // P.x < intersect
                 ++cn; 
        }
    }
    return (cn&1);    

}
int isInside( Point P, int n ) {
    int    wn = 0;   

    for (int i=0; i<n; i++) {   // edge from V[i] to  V[i+1]
        if (pgn[i].y <= P.y) {          // start y <= P.y
            if (pgn[i+1].y  > P.y)      // an upward crossing
                 if (isLeft( pgn[i], pgn[i+1], P) > 0)  // P left of  edge
                     ++wn;            // have  a valid up intersect
        }
        else {                        // start y > P.y (no test needed)
            if (pgn[i+1].y  <= P.y)     // a downward crossing
                 if (isLeft( pgn[i], pgn[i+1], P) < 0)  // P right of  edge
                     --wn;            // have  a valid down intersect
        }
    }
    return wn;
}
bool isOnline(Point a, Point b, Point c) {
	long long crossproduct = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
    if(abs(crossproduct)!=0)return false;

    long long dotproduct = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y);
    if(dotproduct < 0)return false;

    long long squaredlengthba = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    if(dotproduct > squaredlengthba)return false;

    return true;
}
bool isOnAnyline(Point p, int n) {
	Point p1,p2;
	for(int i=1;i<n;i++) {
		p1.x=pgn[i-1].x; p1.y=pgn[i-1].y;
		p2.x=pgn[i].x; p2.y=pgn[i].y;
		if(isOnline(p1,p2,p))return true;
	}
	p1.x=pgn[n-1].x; p1.y=pgn[n-1].y;
	p2.x=pgn[0].x; p2.y=pgn[0].y;
	if(isOnline(p1,p2,p))return true;
	return false;
}
/*void testIsInside() {
	Point p1,p2,p3;
	p1.x=-2;p1.y=1;
	p2.x=-2;p2.y=0;
	p3.x=-1;p3.y=-1;
	if(cn_PnPoly(p1, 5))cout<<"yes"<<endl;
}*/
int main() {
	int n,xmin, xmax, ymin, ymax;
	cin>>n;
	Point p;

	for(int i=0;i<n;i++) {
		cin>>p.x>>p.y;
		pgn.push_back(p);
		if(i==0) {
			xmin=xmax=pgn[i].x;
			ymin=ymax=pgn[i].y;
		}
		if(pgn[i].x<xmin)xmin=pgn[i].x; if(pgn[i].x>xmax)xmax=pgn[i].x; if(pgn[i].y<ymin)ymin=pgn[i].y; if(pgn[i].y>ymax)ymax=pgn[i].y;
	}
	pgn.push_back(pgn[0]);
	long long ans=0;
	for(int i=xmin;i<=xmax;i++) {
		for(int j=ymin;j<=ymax;j++) {
			p.x=i;
			p.y=j;
			if(isOnAnyline(p, n) || isInside(p, n)) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
