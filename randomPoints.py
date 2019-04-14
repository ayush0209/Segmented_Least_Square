import numpy as np
import os

num =2
size=20
x= np.random.uniform(0,10,size);
y= np.random.uniform(0,10,size);

ordered_pair=[]
for i in range(size):
	ordered_pair.append((x[i],y[i]))
print(ordered_pair)
ordered_pair.sort()
print(ordered_pair)
f=open(os.getcwd()+'/input/input'+str(num)+'.txt',"w+")

f.write(str(size)+"\n")
for i in range(size):
	f.write(str(ordered_pair[i][0])+" "+str(ordered_pair[i][1])+"\n")

f.close()
#print(x)
#rint(y)