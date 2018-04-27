import matplotlib.pyplot as plt
import numpy as np

def num_vWithMaxk(dir):
	filename=dir+"/num_vWithMaxk.txt"
	file=open(filename,'r')
	raw_data=[line.split() for line in file.readlines()]
	data=np.array(raw_data[1:])[:,-1].astype(np.float)
	plt.figure(figsize=(12,6))
	arr=plt.hist(data, bins='sqrt')

	plt.xticks(arr[1])
	for j in range(len(arr[0])):
		if(arr[0][j]>0):
			plt.text(arr[1][j],arr[0][j]+1,int(arr[0][j]),color='blue', fontweight='bold')

	plt.ylabel('amount')
	plt.xlabel('number of vertices with maxK')
	title=dir[dir.rfind('/'):]
	plt.title(title)
	plt.xticks(rotation=90)
	plt.tight_layout()
	plt.savefig(dir+'/num_vWithMaxk.png',dpi=199)
