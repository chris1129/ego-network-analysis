import matplotlib.pyplot as plt
import numpy as np
import num_VwithMaxk_plt as NV
import max_kcore_plt as MK
import avg_DenSize_plt as ADS
import avg_child_plt as AC
import moreThan1child as MT1C
import matplotlib
import sys


dir=sys.argv[1]
print(dir)
#NV.num_vWithMaxk(dir)
MK.maxkcore(dir)
ADS.avgDenSize(dir)
AC.avgChild(dir)
MT1C.RatioMoreThanOneChild(dir)

#plt.plot(data,'o')
# plt.ylabel('avg_#children')
# plt.xlabel('ego')
# plt.show()
