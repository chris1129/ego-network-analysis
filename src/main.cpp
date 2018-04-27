//
//  draft.cpp
//  ego_construct
//
//  Created by Sheng-Yung Cheng on 2/13/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//
///////////This is a version which follows Prof's format

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <vector>
#include "egoConstruction.h"
#include "reorganize_and_run_kcore.h"
#include "reorganize_and_run_ktruss.h"
#include "reorganize_and_run_base34.h"
#include "egoFileWrite.h"

using namespace std;


int main(int argc, const char * argv[]) {
      
    
    string file_dir="data/";
    string file_name=argv[1];
    string alg=argv[2];
    ifstream edge_file(file_dir+file_name);
    if(edge_file.good())cout<<file_name<<" file open success"<<endl;
    else {
        cout<<"file open fail"<<endl;
        return 0;
    }
    
    cout<<"Start to construct ego network......."<<endl;
    int num_vertex;
    int num_edge;
    
    
    string edg_str;
    
    getline(edge_file,edg_str);

    stringstream ss(edg_str);

    ss>>num_vertex;

    ss>>num_edge;


    vector<vector<int> >neighbor(num_vertex+1,vector<int>());///////////////
    vector<unordered_map<int,vector<int>>>ego_net(num_vertex+1,unordered_map<int,vector<int> >());
    vector<int>degree(num_vertex+1,0);


    while(getline(edge_file,edg_str)){
        //cout<<edg_str<<endl;
        stringstream ss(edg_str);
        int u;
        int v;
        ss>>u>>v;
        if(u>=num_vertex+1||v>num_vertex+1){
          cout<<"ERROR:The Id of node Exceed the defined number of vertex"<<endl;
          if(u>=num_vertex)cout<<"Node "<<u<<" exceeds "<<num_vertex<<endl;
          else cout<<"Node "<<v<<" exceeds "<<num_vertex<<endl;
          return 0;
        }
        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
        degree[u]++;
        degree[v]++;
        
    }
    for(int i=0;i<neighbor.size();i++){
        sort(neighbor[i].begin(),neighbor[i].end());
    }



    build_ego(num_vertex,neighbor,degree,ego_net);
    OutputEgoFile(ego_net,file_name);

    if(alg=="12")reorganize_and_run_kcore(ego_net,file_name);
    if(alg=="23")reorganize_and_run_kruss(ego_net,file_name);
    if(alg=="34")reorganize_and_run_base34(ego_net,file_name);
   
   
   
    return 0;
}

// int main(int argc, const char * argv[]) {
      
    
//     string file_dir="data/";
//     string file_name=argv[1];
//     string alg=argv[2];
//     ifstream edge_file(file_dir+file_name);
//     if(edge_file.good())cout<<file_name<<" file open success"<<endl;
//     else {
//         cout<<"file open fail"<<endl;
//         return 0;
//     }
    
//     cout<<"Start to construct ego network......."<<endl;
//     int num_vertex;
//     int num_edge;
    
    
//     string edg_str;
    
//     getline(edge_file,edg_str);

//     stringstream ss(edg_str);

//     ss>>num_vertex;

//     ss>>num_edge;


//     unordered_map<int,unordered_set<int> >neighbor;///////////////
//     unordered_map<int,unordered_map<int,unordered_set<int>>>ego_net;
//     unordered_map<int,int>degree;


//     while(getline(edge_file,edg_str)){
//         //cout<<edg_str<<endl;
//         stringstream ss(edg_str);
//         int u;
//         int v;
//         ss>>u>>v;
//         if(u>=num_vertex+1||v>num_vertex+1){
//           cout<<"ERROR:The Id of node Exceed the defined number of vertex"<<endl;
//           if(u>=num_vertex)cout<<"Node "<<u<<" exceeds "<<num_vertex<<endl;
//           else cout<<"Node "<<v<<" exceeds "<<num_vertex<<endl;
//           return 0;
//         }
//         if(neighbor[u].count(v)==0){
//             neighbor[u].push(v);
//             degree[u]++;
//         }
//         if(neighbor[v].cout(u)==0){
//             neighbor[v].push(u);
//             degree[v]++;
//         }
        
        
//     }

//     //auto neighbor_original=neighbor;

//     build_ego(num_vertex,neighbor,degree,ego_net);
//     if(alg=="12")reorganize_and_run_kcore(ego_net,file_name);
//     if(alg=="23")reorganize_and_run_kruss(ego_net,file_name);
//     if(alg=="34")reorganize_and_run_base34(ego_net,file_name);
   
   
   
//     return 0;
// }

