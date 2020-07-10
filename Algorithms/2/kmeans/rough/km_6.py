import bisect 
import time


start_time=time.time()

cpr=input().split(' ')
c=int(cpr[0])
p=int(cpr[1])
r=int((cpr[2].replace('.', '')))

cs=[]
for i in range(c):
    cs.append(int(input().replace('.', '')))

cs.sort()
#print("cs" + str(cs))
#print("r" + str(r))
for i in range(p):
    ans=""
    pt=int(input().replace('.', ''))

    #print(pt)
    lp=bisect.bisect_left(cs, pt)
    #print(cs)
    #print(lp)
    diff=r
    
    #print("pt" + str(pt))
    #print("abs.." + str(abs(pt-cs[0])))
    if(lp<c and abs(pt-cs[lp])<=diff):
        ans=cs[lp]
        diff=abs(pt-cs[lp])
    if(lp>0 and abs(pt-cs[lp-1])<=diff):
        ans=cs[lp-1]
    
    if(ans==""):
        print("none in range")
    else:
        print("{0:.2f}".format(ans/100))

print("--- %s seconds ---" % (time.time() - start_time))
