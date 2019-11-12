import java.util.*;

public class area_under_poly_3 {
	public static void main(String args[]) {	 
		Scanner in=new Scanner(System.in);
		int n;
		n=in.nextInt();
		int x[]=new int[n];
		int y[]=new int[n];
		for(int i=0;i<n;i++) {
			x[i]=in.nextInt();
			y[i]=in.nextInt();
		}

          	int area=0;
          	for(int i=0;i<n-1;i++)area+=(x[i]*y[i+1]-x[i+1]*y[i]);
          	area+=(x[n-1]*y[0]-x[0]*y[n-1]);
		
		System.out.println(Math.abs(0.5*area));
 
          //if(area%2==0)cout<<".0";
          //cout<<endl;
	}
}
