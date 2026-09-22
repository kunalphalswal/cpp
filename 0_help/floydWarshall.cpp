#include <vector>
#include <climits>
using namespace std;
const int INF = 1e7;
vector<vector<int>> floydWarshall(vector<vector<int>>edges, int n, bool oneIndexed){
    if(oneIndexed)for(auto & e:edges)e[0]--, e[1]--;
    vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
    for(int i = 0;i<n;i++){
        if(oneIndexed)dist[i+1][i+1]=0;
        else dist[i][i]=0;
    }
    for(auto & e:edges){
        if(oneIndexed) dist[e[0]+1][e[1]+1]=e[2];
        else dist[e[0]][e[1]]=e[2];}
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(oneIndexed){
                    if(dist[i+1][k+1]<INF && dist[k+1][j+1]<INF){
                        dist[i+1][j+1]=min(dist[i+1][j+1], dist[i+1][k+1]+dist[k+1][j+1]);
                    }
                }else{
                    if(dist[i][k]<INF && dist[k][j]<INF){
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
    }
    return dist;
}