import java.util.*;

public class pnt_lies_in_poly {
	static int area(int x[], int y[], int n) {
          	int area=0;
          	for(int i=0;i<n-1;i++)area+=(x[i]*y[i+1]-x[i+1]*y[i]);
          	area+=(x[n-1]*y[0]-x[0]*y[n-1]);
		return Math.abs(area);	
	}
	public static void main(String args[]) {	 
		Scanner in=new Scanner(System.in);
		int n,xmin=100000,xmax=-100000,ymin=100000,ymax=-100000;
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

          	int tot_area=area(x,y,n), ans=0;
		for(int i=xmin;i<=xmax;i++) {
			for(int j=ymin;j<=ymax;j++) {
				int tx[]=new int[3];
				int ty[]=new int[3];
				tx[2]=i;ty[2]=j;
				tx[0]=x[n-1];ty[0]=y[n-1];
				tx[1]=x[0];ty[1]=y[0];
				int area_by_t=area(tx,ty,3);
				for(int k=1;k<n;k++) {
					tx[0]=x[k-1];ty[0]=y[k-1];
					tx[1]=x[k];ty[1]=y[k];
					
					area_by_t+=(area(tx,ty,3));
				}
				if(tot_area==area_by_t) {
					ans++;
					//System.out.println(i+" "+j);
				}
				
			}
		}
		//System.out.println(Math.abs(0.5*area));
		System.out.println(ans);	
 
	}
}
