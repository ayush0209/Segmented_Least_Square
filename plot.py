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
	pathSegments=os.getcwd()+'/output/outputSegments.txt'
	segments=[]
	segmentsFile=open(pathSegments,'r')
	len=0
	for segment in reversed(segmentsFile.readlines()):
		# print(line)
		if(len==0):
			segments.append((int)(segment.split(" ")[0]))
			segments.append((int)(segment.split(" ")[1]))
			len+=1
			continue
		segments.append((int)(segment.split(" ")[1]))
		len+=1
	print(segments)
	pathLines=os.getcwd()+'/output/outputLines.txt'
	lines=[]
	linesFile=open(pathLines,'r')
	len=0
	for line in reversed(linesFile.readlines()):
		# print(line)
		# if(len==0):
		lines.append([(float)(line.split(" ")[0]),(float)(line.split(" ")[1])])
		len+=1
	print(lines)
	plt.scatter(pointsXFull,pointsYFull)
	for i in range(segments.__len__()-1):
		print(pointsXFull[segments[i]-1]),
		print(pointsXFull[segments[i+1]-1])
		plt.plot([pointsXFull[segments[i]-1],pointsXFull[segments[i+1]-1]],[pointsXFull[segments[i]-1]*lines[i][1]+lines[i][0],pointsXFull[segments[i+1]-1]*lines[i][1]+lines[i][0]])
	# plt.show()
	plt.savefig('fig1.png')