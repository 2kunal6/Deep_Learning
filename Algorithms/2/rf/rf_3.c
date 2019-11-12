#include<stdio.h>
#include<time.h>
int main() {
	clock_t begin = clock();
	
	int r,i,j,k,l;
	scanf("%d", &r);
	
	char pf[r][r];
	for(i=0;i<r;i++)scanf("%s", pf[i]);
	
	long long ans=0;
        int ones[2001];
	for (i = 0; i < r - 1; i++) {
            int onesc=0;
	    for (k = 0; k < r; k++) {
		    if (pf[i][k]=='1') {
		    	ones[onesc]=k;
	    		onesc++;
	    	}
	    }
            for (j = i + 1; j < r; j++) {
                long long cnt = 0;
                for (l = 0; l < onesc; l++) {
                    if (pf[j][ones[l]]=='1') cnt++;
                }
                ans += cnt * (cnt - 1) / 2;
            }
	    //if(i%100==0)cout<<ans<<endl;
        }
        printf("%llu\n", ans);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n", time_spent);
	
	return 0;
}
