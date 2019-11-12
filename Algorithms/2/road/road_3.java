import java.util.*;

public class road_3 {
	static boolean side(int x1, int y1, int x2, int y2, int x3, int y3) {
		if(((x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)) > 0)return true;
		return false;
	}
	static double dist(int x1, int y1, int x2, int y2) {
		int x=x1-x2, y=y1-y2;
		return Math.sqrt((x*x)-(y*y));
	}
	static boolean online(int x1, int y1, int x2, int y2, int x3, int y3) {
		//if(x3==0 && y3==-2 && x1==1 && y1==-2 && x2==-1 && y2==-2)System.out.println("here");
		if(x3==-1 && y3==2)System.out.println("here");
		if(((x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)) == 0) {
			if(dist(x1, y1, x3, y3)+dist(x2, y2, x3, y3) > dist(x1, y1, x2, y2))return false;
			return true;
		}
		if(x3==-1 && y3==2)System.out.println("here 2");
		//if(x3==0 && y3==-2 && x1==1 && y1==-2 && x2==-1 && y2==-2)System.out.println("2 here");
		return false;
	}
	static boolean onAnyLine(int x[], int y[], int x3, int y3, int n) {
		if(x3==-1 && y3==2)System.out.println("oal");
		if(online(x[n-1],y[n-1],x[0],y[0],x3,y3))return true;
		if(x3==-1 && y3==2)System.out.println("oal 2");
		for(int i=0;i<n-1;i++) {
			if(online(x[i],y[i],x[i+1],y[i+1],x3,y3))return true;
		}
		if(online(x[0],y[0],x[n-1],y[n-1],x3,y3))return true;
		for(int i=n-1;i>0;i--) {
			if(online(x[i],y[i],x[i-1],y[i-1],x3,y3))return true;
		}
		return false;
	}
	static boolean isInside(int x[], int y[], int x3, int y3, int n) {
		boolean fside=side(x[0],y[0],x[1],y[1],x3,y3);
		for(int i=1;i<n-1;i++) {
			if(side(x[i],y[i],x[i+1],y[i+1],x3,y3)!=fside)return false;
		}
		if(side(x[n-1],y[n-1],x[0],y[0],x3,y3)!=fside)return false;
		return true;
	}
	public static void main(String args[]) {	 
		Scanner in=new Scanner(System.in);
		int n,xmin=100000,xmax=-100000,ymin=100000,ymax=-100000, ans=0;
		n=in.nextInt();
		int x[]=new int[n];
		int y[]=new int[n];
		for(int i=0;i<n;i++) {
			x[i]=in.nextInt();
			y[i]=in.nextInt();
			if(i==0) {
				xmin=xmax=x[i];
				ymin=ymax=y[i];
			}
			if(x[i]<xmin)xmin=x[i];
			if(x[i]>xmax)xmax=x[i];
			if(y[i]<ymin)ymin=y[i];
			if(y[i]>ymax)ymax=y[i];
		}
		for(int i=xmin;i<=xmax;i++) {
			for(int j=ymin;j<=ymax;j++) {
				if(onAnyLine(x,y,i,j,n) || isInside(x,y,i,j,n)) {
					ans++;
					//System.out.println(i+" "+j);
				}
				
			}
		}
		//System.out.println(Math.abs(0.5*area));
		System.out.println(ans);	
 
	}
}
