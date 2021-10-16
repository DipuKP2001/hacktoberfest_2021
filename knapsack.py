n=int(input("no. of items: "))
val=[]
wt=[]
for i in range(n):
    k=int(input("value: "))
    val.append[i]
    
for i in range(n):
    k=int(input("weight: "))
    wt.append[i]
    

bag=int(input())

def knapSack(W, wt, val, n):
 
   
    if n == 0 or W == 0:
        return 0
 

    if (wt[n-1] > W):
        return knapSack(W, wt, val, n-1)
 
    
    else:
        return max(
            val[n-1] + knapSack(
                W-wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1))
 
k=knapSack(bag, wt, val, n)
print(k)