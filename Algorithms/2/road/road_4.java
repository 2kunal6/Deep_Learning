import java.util.*;

public class road_4 {
	static int side(int x1, int y1, int x2, int y2, int x3, int y3) {
		return ((x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1));
	}
	static boolean isInside(int x[], int y[], int x3, int y3, int n) {
		List<Integer> side = new ArrayList<Integer>();
		for(int i=0;i<n-1;i++) {
			side.add(side(x[i],y[i],x[i+1],y[i+1],x3,y3));
		}
		side.add(side(x[n-1],y[n-1],x[0],y[0],x3,y3));
		Collections.sort(side);
		if(side.get(0)<0 && side.get(side.size()-1)>0)return false;
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
				//if(onAnyLine(x,y,i,j,n) || isInside(x,y,i,j,n)) {
				if(isInside(x,y,i,j,n)) {
					ans++;
					//System.out.println(i+" "+j);
				}
				
			}
		}
		//System.out.println(Math.abs(0.5*area));
		System.out.println(ans);	
 
	}
}
