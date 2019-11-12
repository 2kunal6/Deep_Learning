import java.util.*;

public class road_6 {
	public static void main(String args[]) {	 
		Scanner in=new Scanner(System.in);
		int n;
		n=in.nextInt();
		long x[]=new long[n];
		long y[]=new long[n];
		for(int i=0;i<n;i++) {
			x[i]=in.nextInt();
			y[i]=in.nextInt();
		}

          	long area=0, bp=0, ip=0;
          	for(int i=0;i<n-1;i++)area+=(x[i]*y[i+1]-x[i+1]*y[i]);
          	area+=(x[n-1]*y[0]-x[0]*y[n-1]);

		area=Math.abs(area);
		
		area+=2;

		for(int i=1;i<n;i++)bp+=(getCount(x[i-1], y[i-1], x[i], y[i]));
		bp+=(getCount(x[n-1], y[n-1], x[0], y[0]));
		bp+=n;

		ip=(long)(0.5*(area-bp));
		System.out.println(ip+bp);
		
		//System.out.println(area-2+" "+ip+" "+bp);
 		
          //if(area%2==0)cout<<".0";
          //cout<<endl;
	}
	static long gcd(long a, long b) {
    		if (b == 0)return a;
    		return gcd(b, a%b);
	}

	static long getCount(long x1, long y1, long x2, long y2) {
    		if (x1==x2)return Math.abs(y1 - y2) - 1;
		if (y1==y2)return Math.abs(x1-x2) - 1;
		return gcd(Math.abs(x1-x2), Math.abs(y1-y2))-1;
	}
}
