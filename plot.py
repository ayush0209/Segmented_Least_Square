import matplotlib.pyplot as plt
import os
num=1
if __name__=='__main__':
	pathPoints=os.getcwd()+'/input/input'+str(num)+'.txt'
	points=[] 
	pointsXFull=[]
	pointsYFull=[]
	pointsFile=open(pathPoints,'r')
	for point in pointsFile.readlines()[1:]:
		print(point[:-1].split(" "))
		points.append([(float)(point[:-1].split(" ")[0]),(float)(point[:-1].split(" ")[1])])
		pointsXFull.append((float)(point[:-1].split(" ")[0]))
		pointsYFull.append((float)(point[:-1].split(" ")[1]))
	pathLines=os.getcwd()+'/output/outputLines.txt'
	lines=[]
	linesFile=open(pathLines,'r')
	len=0
	for line in reversed(linesFile.readlines()):
		# print(line)
		if(len==0):
			lines.append((int)(line.split(" ")[0]))
		lines.append((int)(line.split(" ")[1]))
		len+=1
	plt.scatter(pointsXFull,pointsYFull)
	for i in range(lines.__len__()-1):
		plt.plot([pointsXFull[lines[i]],pointsXFull[lines[i+1]]],[pointsYFull[lines[i]],pointsYFull[lines[i+1]]])	
	plt.savefig('fig1.png')