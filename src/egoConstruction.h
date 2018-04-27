#ifndef EGOCONSTRUCTION_H
#define EGOCONSTRUCTION_H
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
void deletenode(int vertex, vector<vector<int>>&neighbor,vector<int>&degree,vector<unordered_map<int,vector<int>>>&ego_net){
    auto nei=neighbor[vertex];//v's neighbor
    for(int i=0;i<nei.size();i++){
        for(int j=i+1;j<nei.size();j++){
            int u=nei[i];
            int v=nei[j];
            auto it1=find(neighbor[u].begin(),neighbor[u].end(),v);
            //may be slow by using find in vector           
            if(it1!=neighbor[u].end()){
                ego_net[vertex][u].push_back(v);
                ego_net[vertex][v].push_back(u);
                ego_net[u][v].push_back(vertex);
                ego_net[u][vertex].push_back(v);
                ego_net[v][u].push_back(vertex);
                ego_net[v][vertex].push_back(u);
            }
        }
    }
    
    for(auto n:neighbor[vertex]){
        degree[n]--;
        auto pos=find(neighbor[n].begin(),neighbor[n].end(),vertex);
        if(pos!=neighbor[n].end())neighbor[n].erase(pos);
    }
}


void build_ego(int num_vertex,vector<vector<int>>&neighbor,vector<int>&degree,vector<unordered_map<int,vector<int>>>&ego_net){
	 for(int i=0;i<num_vertex;i++){
       int min_degree=INT_MAX;
       int min_degree_vertex;
       for(int j=0;j<degree.size();j++){
           if(degree[j]<min_degree&&degree[j]!=-1){
               min_degree=degree[j];
               min_degree_vertex=j;
           }
       }
       degree[min_degree_vertex]=-1;
       deletenode(min_degree_vertex,neighbor,degree,ego_net);

   }
}




// void deletenode(int vertex, unordered_map<int,unordered_set<int>>&neighbor,unordered_map<int,int>&degree,unordered_map<int,unordered_map<int,unordered_set<int>>>&ego_net){
//     unordered_set<int> nei=neighbor[vertex];//v's neighbor
//     for(auto u:nei){
//         for(auto v:nei){
//             //auto it1=find(neighbor[u].begin(),neighbor[u].end(),v);
//             //may be slow by using find in vector           
//             if(u!=v&&neighbor[u].count(v)!=0&&neighbor[v].count(u)!=0){
//                 ego_net[vertex][u].push(v);
//                 ego_net[vertex][v].push(u);
//                 ego_net[u][v].push(vertex);
//                 ego_net[u][vertex].push(v);
//                 ego_net[v][u].push(vertex);
//                 ego_net[v][vertex].push(u);
//             }
//         }
//     }
    
//     for(auto n:neighbor[vertex]){
//         degree[n]--;
//         if(neighbor[n].find(vertex)!=neighbor[n].end())
//           neighbor[n].erase(vertex);
//         //auto pos=find(neighbor[n].begin(),neighbor[n].end(),vertex);
//         //if(pos!=neighbor[n].end())neighbor[n].erase(pos);
//     }
// }


// void build_ego(int num_vertex,unordered_map<int,unordered_set<int>>&neighbor,unordered_map<int,int>&degree,unordered_map<int,unordered_map<int,unordered_set<int>>>&ego_net){
//    for(int i=0;i<num_vertex;i++){
//        int min_degree=INT_MAX;
//        int min_degree_vertex;
//        for(auto d:degree){
//            if(d.second<min_degree&&d.second!=-1){
//                min_degree=d.second;
//                min_degree_vertex=d.first;
//            }
//        }
//        degree[min_degree_vertex]=-1;
//        deletenode(min_degree_vertex,neighbor,degree,ego_net);

//    }
// }

#endif
