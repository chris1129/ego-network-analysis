#ifndef EGOFILEWRITE_H
#define EGOFILEWRITE_H
#include "simplehash.h"

void OutputEgoFile(vector<unordered_map<int,vector<int>>>&ego_net,string file_name){
  system("mkdir data/temp");
  for(int i=0;i<ego_net.size();i++){
    ofstream out_file("data/temp/"+file_name+"_ego_"+to_string(i)+"_minus_ego.mtx");
    if(out_file.good()){

    }
    else {
        cout<<"ego_"+to_string(i)+"_minus_ego.mtx"+" file open fail"<<endl;
        return ;
    }
    int counter=1;
    unordered_set<pair<int,int>,simplehash>edge;
    unordered_map<int,int>rename_mapping;
    for(auto h:ego_net[i]){
      for(auto nei:h.second){

          int u=h.first;
          int v=nei;
          if(rename_mapping.find(u)==rename_mapping.end()){
            rename_mapping[u]=counter++;
          }
          if(rename_mapping.find(v)==rename_mapping.end()){
            rename_mapping[v]=counter++;
          }
          u=rename_mapping[u];
          v=rename_mapping[v];
          pair<int,int> p=u<v?make_pair(u,v):make_pair(v,u);
          edge.insert(p);

      }
    }

    out_file<<ego_net[i].size()+1<<" "<<edge.size()<<'\n'; 
    for(auto p:edge){
      out_file<<p.first<<" "<<p.second<<'\n';
    }
  }
}

#endif