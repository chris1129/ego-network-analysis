#ifndef SIMPLEHASH_H
#define SIMPLEHASH_H

struct simplehash{
  template<class T1,class T2>
  bool operator()(const pair<T1,T2>&p)const{
  		hash<T1>h1;
  		hash<T2>h2;
        return h1(p.first)^h2(p.second);
  }
};


#endif