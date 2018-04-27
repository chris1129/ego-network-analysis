#ifndef REORGANIZEANDRUNBASE34_H
#define REORGANIZEANDRUNBASE34_H


#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include "analyze.h"
#include "simplehash.h"


using namespace std; 
void reorganize_and_run_base34(vector<unordered_map<int,vector<int>>>&ego_net,string file_name){

//output each ego's graph save in temp dir
  // system("mkdir data/temp");
  // for(int i=0;i<ego_net.size();i++){
  //   ofstream out_file("data/temp/"+file_name+"_ego_"+to_string(i)+"_minus_ego.mtx");
  //   if(out_file.good()){

  //   }
  //   else {
  //       cout<<"ego_"+to_string(i)+"_minus_ego.mtx"+" file open fail"<<endl;
  //       return ;
  //   }
  //   int counter=1;
  //   unordered_set<pair<int,int>,simplehash>edge;
  //   unordered_map<int,int>rename_mapping;
  //   for(auto h:ego_net[i]){
  //     for(auto nei:h.second){

  //         int u=h.first;
  //         int v=nei;
  //         if(rename_mapping.find(u)==rename_mapping.end()){
  //           rename_mapping[u]=counter++;
  //         }
  //         if(rename_mapping.find(v)==rename_mapping.end()){
  //           rename_mapping[v]=counter++;
  //         }
  //         u=rename_mapping[u];
  //         v=rename_mapping[v];
  //         pair<int,int> p=u<v?make_pair(u,v):make_pair(v,u);
  //         edge.insert(p);

  //     }
  //   }

  //   out_file<<ego_net[i].size()+1<<" "<<edge.size()<<'\n'; 
  //   for(auto p:edge){
  //     out_file<<p.first<<" "<<p.second<<'\n';
  //   }



  // }

  string dirname=file_name+"_base34";
  string cmd1="rm -r "+dirname;
  system(cmd1.c_str());
  string cmd2="mkdir "+dirname;
  system(cmd2.c_str());
  string cmd3="mkdir "+dirname+"/base34_out";
  system(cmd3.c_str());

  //Run kcore_decomposition which generate each ego's huerarchy and nucleius
  //kcore_decomposition also output 
  ofstream kcore_summaryfile;
  kcore_summaryfile.open(dirname+"/max_kcore.txt");
  kcore_summaryfile<<"#"<<file_name<<" ego max k core "<<'\n';
  kcore_summaryfile.close();

  ofstream Num_leaf;
  Num_leaf.open(dirname+"/Num_leaf.txt");
  Num_leaf<<"#"<<file_name<<" Number of leaf for each ego "<<'\n';
  Num_leaf.close();

  ofstream avg_children;
  avg_children.open(dirname+"/avg_#children.txt");
  avg_children<<"#"<<file_name<<" Average number of Children for each ego. (#children/#subgraph) "<<'\n';
  avg_children.close();

  ofstream avg_ExcessOneChildren;
  avg_ExcessOneChildren.open(dirname+"/avg_#ExcessOneChildren.txt");
  avg_ExcessOneChildren<<"#"<<file_name<<" Average of subgraph with more than 1 child (#more than 1 child/#subgraph)"<<'\n';
  avg_ExcessOneChildren.close();

  ofstream subden;
  subden.open(dirname+"/avg_#DenExcessThold.txt");
  subden<<"#"<<file_name<<" Average of num subgraph with dense>threshold (#subgraph with den>thold/#subgraph)"<<'\n';
  subden.close();

  ofstream subdensize;
  subdensize.open(dirname+"/avg_#DenSizeExcessThold.txt");
  subdensize<<"#"<<file_name<<" average number of subgraph with dense>thold and size>thold (#subgraph with den>thold&&size>thold/#subgraph)"<<'\n';
  subdensize.close();

  ofstream vmaxk;
  vmaxk.open(dirname+"/num_vWithMaxk.txt");
  vmaxk<<"#"<<file_name<<" Number of vertices with max k value"<<'\n';
  vmaxk.close();


//run base34
  for(int i=0;i<ego_net.size();i++){
    string cmd="./nd/nucleus ./data/temp/"+file_name+"_ego_"+to_string(i)+"_minus_ego.mtx 34 YES "+dirname;
    system(cmd.c_str());
  }

  cout<<"Output the analysis data....."<<endl;

  //toy_dataset.txt_ego_4_minus_ego.mtx_12_NUCLEI
  for(int i=0;i<ego_net.size();i++){
    string fname=file_name+"_ego_"+to_string(i)+"_minus_ego.mtx_34_NUCLEI";
    analyze("./"+dirname+"/base34_out/"+fname,34,dirname);
  }

  cout<<"Romoving temp data......"<<endl;
  system("rm -r data/temp");

  string cmd_figureLayout="python histo.py "+dirname;
  system(cmd_figureLayout.c_str());

}


#endif

