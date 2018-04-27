# Introduction:
This program will construct the ego-network for every node in the given network, run decomposition algorithm for each ego-network and output the distribution chart.

# How to compile?
1. Put data file under data directory
2. `$make`
3. `$ ./ego Filename Alg`

Alg can be 12,23,34. 12 is kcore,23 is ktruss, 34 is base34.

# Output:
A folder conatining all .txt files and all figure