import matplotlib.pyplot as plt
import numpy as np
import max_kcore_plt as MK
import avg_child_plt as AC
import moreThan1child as MT1C
import matplotlib
import sys


dir=sys.argv[1]
MK.maxkcore(dir)
AC.avgChild(dir)
MT1C.RatioMoreThanOneChild(dir)

