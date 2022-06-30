#include<bits/stdc++.h>
using namespace std;
void bfs(int node,vector<int>&vis,vector<int>adj[]){
    queue<int>q;
    vector<int>bfsArray;
    vis[node]=1;
    q.push(node);
    bfsArray.push_back(node);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto it:adj[curr]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
                bfsArray.push_back(it);
            }
        }
    }
    cout<<"bfs traversal:"<<endl;
    for(auto it:bfsArray) cout<<it<<" ";
    cout<<endl;
}
void dfs(int node,vector<int>&vis,vector<int>adj[]){
     vis[node]=1;
     cout<<node<<" ";
     for(auto it:adj[node]){
        if(!vis[it]) dfs(it,vis,adj);
     }
}
bool cycleDetectionBFS(int node,vector<int>&vis,vector<int>adj[]){
  
    vis[node]=1;
    queue<pair<int,int>>q;
    q.push(make_pair(node,-1));
    while(!q.empty()){
        pair<int,int>temp=q.front();
        q.pop();
        int curr=temp.first;
        int par=temp.second;
        for(auto it:adj[curr]){
            if(!vis[it]){
                vis[it]=1;
            
                q.push(make_pair(it,curr));
            }
            else {
                if(it!=par) return true;
            }
        }
    }
    return false;
}
bool cycleDetectionDFS(int node,int par,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(cycleDetectionDFS(it,node,vis,adj)) return true;
        }
        else {
            if(it!=par) return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n,0);

      //bfs traversal//

//     for(int i=0;i<n;i++){                    
//         if(!vis[i]) bfs(i,vis,adj);
//     }

               //dfs traversal

    //   for(int i=0;i<n;i++){
        
    //     if(!vis[i]) { dfs(i,vis,adj);}                
    //   }


     // cycle detection in undirected graph using bfs
//     int flag=0;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             if(cycleDetectionBFS(i,vis,adj)) {flag=1;cout<<"cycle is present"<<endl;break;}
//         }
//     }
//   if(flag==0) cout<<"cycle is not present"<<endl;



//  Cycle detection in undirected graph usind dfs

//     int flag=0;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             if(cycleDetectionDFS(i,-1,vis,adj)) {flag=1;cout<<"cycle is present"<<endl;break;}
//         }
//     }
//   if(flag==0) cout<<"cycle is not present"<<endl;


       

 }