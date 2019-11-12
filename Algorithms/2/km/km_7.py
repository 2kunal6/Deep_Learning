cpr=input().split(' ')
c=int(cpr[0])
p=int(cpr[1])
r=int((cpr[2].replace('.', '')))

cs=[]
for i in range(c):
    cs.append(int(input().replace('.', '')))

cs.sort()
qp=[]
posdi={}
for i in range(p):
    iv=int(input().replace('.', ''))
    qp.append(iv)
    posdi[iv]=i

qp.sort()

i=0
j=0
diff=r
ansdi=["none in range"]*p
while i<c and j<p:
    ans=""
    if(qp[j]>cs[i]):
        i+=1
        continue
    if(abs(qp[j]-cs[i])<=diff):
        ans=cs[i]
        diff=abs(qp[j]-cs[i])
    if(i>0 and abs(qp[j]-cs[i-1])<=diff):
        ans=cs[i-1]
    if(ans!=""):
        ansdi[posdi[qp[j]]]=("{0:.2f}".format(ans/100))
    j+=1
    diff=r
while j<p:
    if(abs(cs[c-1]-qp[j])<=r):
        ansdi[posdi[qp[j]]]=("{0:.2f}".format(cs[c-1]/100))
    else:
        break
    j+=1

for i in range(p):
    print(ansdi[i])
