#include<stdio.h>
#include<queue>
using namespace std;

 vector<int>g[100] ;
 queue<int>Q ;
 int col[100], d[100], par[100] ;

 void bfs()
 {
     while(!Q.empty()){
        int u = Q.front() ;
        Q.pop() ;
        for(int i = 0 ; i < g[u].size() ; i++){
            int v = g[u][i] ;
            if(col[v] == 0){
                col[v] = 1 ;
                d[v] = d[u] + 1 ;
                par[v] = u ;
                Q.push(v) ;
            }
        }
        col[u] = 2 ;
     }
 }

 void printPath(int src, int dst)
 {
    if(src == dst){
        printf("%d ", src) ;
        return ;
    }
    if(dst == -1){
      //  printf("No path") ;
        return ;
    }
    printPath(src, par[dst]) ;
    printf("%d ", dst) ;
 }
 int main()
 {
     int n, edge, i, j, u, v, src, dst;
     scanf("%d %d", &n , &edge) ;
     for(i = 0 ; i < edge ; i++){
        scanf("%d %d", &u, &v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
     }
     scanf("%d %d", &src, &dst) ;

     for(int i = 0 ; i < n ; i++){
        col[i] = 0 ;
        d[i] = 99999 ;
        par[i] = -1 ;
     }

     col[src] = 1 ;
     d[src] = 0 ;
     Q.push(src) ;
     bfs() ;

 }

