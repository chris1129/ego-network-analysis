import matplotlib.pyplot as plt
import numpy as np

def maxkcore(dir):
	filename=dir+"/max_kcore.txt"
	file=open(filename,'r')
	raw_data=[line.split() for line in file.readlines()]
	data=np.array(raw_data[1:])[:,-1].astype(np.float)
	plt.figure(figsize=(12,6))
	maxk=max(data)
	bins=np.arange(maxk+2)
	#print(bins)
	arr=plt.hist(data, bins)
	plt.xticks(arr[1])
	for j in range(len(arr[0])):
		if(arr[0][j]>0):
			plt.text(arr[1][j],arr[0][j]+1,int(arr[0][j]),color='blue', fontweight='bold')

	plt.ylabel('Frequency')
	plt.xlabel('max_k')
	title=dir[dir.rfind('/'):]
	plt.title(title)
	plt.xticks(rotation=90)
	plt.tight_layout()
	plt.savefig(dir+'/max_kcore.png',dpi=199)
	