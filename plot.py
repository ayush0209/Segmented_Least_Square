import matplotlib.pyplot as plt
import os
num=2
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

	c=[0.500000,1.000000,2.000000,3.500000,5.000000,8.000000,10.000000,15.000000,20.000000,25.000000,30.000000,50.000000,100.000000]
	for cval in c:
		pathSegments=os.getcwd()+'/output/outputSegmentsC:'+str('%.6f'%cval)+'.txt'
		segments=[]
		segmentsFile=open(pathSegments,'r')
		len=0
		for segment in reversed(segmentsFile.readlines()):
			# print(line)
			segments.append((int)(segment.split(" ")[0]))
			segments.append((int)(segment.split(" ")[1]))
			len+=1
		print(segments)
		pathLines=os.getcwd()+'/output/outputLinesC:'+str('%.6f'%cval)+'.txt'
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
		for i in range(lines.__len__()):
			print(segments.__len__())
			print(segments[2*i]-1)
			print(segments[2*i+1]-1)
			print(pointsXFull[segments[2*i]-1]),
			print(pointsXFull[segments[2*i+1]-1])
			plt.plot([pointsXFull[segments[2*i]-1],pointsXFull[segments[2*i+1]-1]],[pointsXFull[segments[2*i]-1]*lines[i][1]+lines[i][0],pointsXFull[segments[2*i+1]-1]*lines[i][1]+lines[i][0]])
		# plt.show()
		plt.savefig(os.getcwd()+'/images/SLSoutput'+str(num)+'c:'+str('%.6f'%cval)+'.png')
		plt.clf()