import bisect 
import time
import string

start_time = time.time()
a=[]
for i in range(1000000):
    s=bytearray(input(),'utf-8')
    #s.translate(maketrans('.', ' '))
    tbs=s[:-3]
    tbs+=s[-2:]
    a.append(int(tbs))
print("--- %s seconds ---" % (time.time() - start_time))

start_time = time.time()
b=[None]*1000000
for i in range(1000000):
    s=input()
    #lp=bisect.bisect_left(a, 1000000.00, i, 1000000)
    s=s.replace('.','')
    #b[i]=int("1000000000000000000000000000")
print("--- %s seconds ---" % (time.time() - start_time))

#print(int("1000000000000000000000000.05"))


# initializing list 
#li = [1, 7, 7, 14, 24, 36, 47] 
  
# using bisect() to find index to insert new element 
# returns 5 ( right most possible index ) 
#print ("The rightmost index to insert, so list remains sorted is  : ", end="") 
#print (bisect.bisect_right(li, 0)) 
  
# using bisect_left() to find index to insert new element 
# returns 2 ( left most possible index ) 
#print ("The leftmost index to insert, so list remains sorted is  : ", end="") 
#print (bisect.bisect_left(li, 20)) 
  
