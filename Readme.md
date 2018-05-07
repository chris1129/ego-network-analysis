# Introduction:
This program will construct the ego-network for every node in the given network, run decomposition algorithm for each ego-network and output the distribution chart.

# How to compile?
1. Put data file under data directory
2. `$make`
3. `$ ./ego Filename Alg`

Alg can be 12,23,34. 12 is kcore,23 is ktruss, 34 is base34.

# Output:
## Distribution charts including the following:
1.Histogram for Ratio of node with more than 1 child
2.Histogram for Average number of Children for each ego
3.Histogram for Max k core

## .txt files including the following:
1.Average number of Children for each ego. (#children/#node)
2.Ratio of node with more than 1 child for each ego. (#more than 1 child/#node)
3.Max k core for each ego.
4.Number of leaf for each ego.
5.Number of vertices with max k value for each ego.