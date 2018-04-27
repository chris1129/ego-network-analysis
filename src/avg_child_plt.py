import matplotlib.pyplot as plt
import numpy as np


def avgChild(dir):
	filename=dir+"/avg_#children.txt"
	file=open(filename,'r')
	raw_data=[line.split() for line in file.readlines()]
	data=np.array(raw_data[1:])[:,-2].astype(np.float)
	plt.figure(figsize=(12,6))
	bins=np.arange(0.0,1.1,0.05)
	arr=plt.hist(data, bins)
	plt.xticks(arr[1])
	
	for j in range(len(arr[0])):
		if(arr[0][j]>0):
			plt.text(arr[1][j],arr[0][j]+10,int(arr[0][j]),color='blue', fontweight='bold')
	plt.ylabel('amount')
	plt.xlabel('avg_#children (#children/#Node)')
	title=dir[dir.rfind('/'):]
	plt.title(title)
	plt.xticks(rotation=90)
	plt.tight_layout()

	plt.savefig(dir+'/avg_#children.png',dpi=199)
	
