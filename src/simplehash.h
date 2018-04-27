#ifndef SIMPLEHASH_H
#define SIMPLEHASH_H

struct simplehash{
  bool operator()(const pair<int,int>&p)const{
        return p.first^p.second;
  }
};


#endif