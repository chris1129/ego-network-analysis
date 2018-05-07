#ifndef ANALYZE_H
#define ANALYZE_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>  

void analyze(string filename,int alg_para,string dirname){
	fstream ori_file;
	ofstream newfile;
	ori_file.open(filename);
	if (!ori_file.is_open()) {
		return ;
	} 
	int algo = alg_para;
	int num_leaves = 0, max_K = INT_MIN, v_withMaxK = -1, e_withMaxK = -1, size_limit = 10;
	int num_den_overlimit = 0, num_V_overlimit = 0, num_pass_both = 0, more1_children = 0, num_children = 0;
	float den_limit = 0.8;
	unordered_map<string, int> id_child_num;     // key = node id , value = num of children
	unordered_set<string>node_id;
	string linebuf;
	int id, k, numV, numE, leaf, parentId;
	float density;
	
	while (true) {
		if (ori_file.eof()) break;
		while (getline(ori_file, linebuf) && !ori_file.eof()) {
			stringstream ss(linebuf);
			ss >> id >> k >> numV >> numE >> density >> leaf >> parentId; 
			//num_subgraph++;
			
			if (numV == -1||parentId==-1) continue;
			node_id.insert(to_string(id));
			node_id.insert(to_string(parentId));
			if (max_K < k) {
				max_K = k;
				v_withMaxK = numV;
				e_withMaxK = numE;
			}

			if (numV > size_limit) num_V_overlimit++;
				
			if (density > den_limit) num_den_overlimit++;
			
			if (numV > size_limit && density > den_limit) num_pass_both++;

			if (leaf == 1) num_leaves++;
			id_child_num[to_string(parentId)]++;
			
		}
	}
	ori_file.close();

	for (auto iter = id_child_num.begin(); iter != id_child_num.end(); iter++) {
		int count = id_child_num[iter->first];
		num_children += count;
		if (count > 1){
			 more1_children++;
		}
	}


	ofstream kcore_summaryfile(dirname+"/max_kcore.txt",std::ios::app);
  	ofstream Num_leaf(dirname+"/Num_leaf.txt",std::ios::app);
  	ofstream avg_children(dirname+"/avg_#children.txt",std::ios::app);
  	ofstream avg_ExcessOneChildren(dirname+"/avg_#ExcessOneChildren.txt",std::ios::app);
  	// ofstream subden(dirname+"/avg_#DenExcessThold.txt",std::ios::app);
  	// ofstream subdensize(dirname+"/avg_#DenSizeExcessThold.txt",std::ios::app);
  	ofstream vmaxk(dirname+"/num_vWithMaxk.txt",std::ios::app);
  	//#ofchildren/#subgraph
  	int num_node=(int)node_id.size();
  	if(num_node==0)return ;
  	string fname=filename.substr(filename.find_last_of("/\\")+1);
	Num_leaf <<fname<< " #leaves: " + to_string(num_leaves) << endl;
	avg_children <<fname<< " avg_#children: " + to_string((float)num_children / (float)(num_node))<<" ("<<(float)num_children<<"/"<<(float)(num_node)<<")" << endl;
	avg_ExcessOneChildren <<fname<< " factor_of_#children > 1: " + to_string((float)more1_children / (float)num_node)<<" ("<<(float)more1_children<< "/"<< (float)num_node<<")" << endl;
	// subden <<fname<< " factor_of_density > 0.8: " + to_string((float)num_den_overlimit / (float)num_node)<<" ("<<(float)num_den_overlimit<<"/"<<(float)num_node<<")" << endl;
	// subdensize <<fname<< " factor_of_both: " + to_string((float)num_pass_both / (float)num_node)<<" ("<<(float)num_pass_both<< "/"<< (float)num_node<<")" << endl;
	kcore_summaryfile <<fname<< " max_K: " + (max_K>0?to_string(max_K):"0") << endl;
	if (algo == 12)    // k-core
		vmaxk <<fname<< " Vertices_with_max_K: " +(v_withMaxK>=0?to_string(v_withMaxK):"0")  << endl;
	else if (algo == 23)  // k-truss
		vmaxk <<fname<< " Edges_with_max_K: " + (e_withMaxK>=0?to_string(e_withMaxK):"0") << endl;

}

#endif
