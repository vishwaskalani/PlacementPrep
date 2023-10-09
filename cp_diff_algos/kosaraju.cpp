#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> arr1[51];
vector<int> arr2[51];
int visited[51];
int visited2[51];
stack<int> st;
int r;

//DFS Traversal of a graph
void DFS(int node){

    visited[node]=1;
    for(int child: arr1[node]){

        if(visited[child]!=1){
            DFS(child);

        }
    }
    st.push(node);
}

//DFS traversal of modified graph
void DFS2(int node){
    cout<<node<<" ";
    visited2[node]=1;
    for(int child: arr2[node]){
    if(visited2[child]!=1){
            DFS2(child);

        }
    }

}
int main(){

    int n,m,x,y;
    cout<<"Enter number of vertex and number of edge"<<endl;
    cin>>n>>m;
    while(m--){
        cout<<"enter vertex having edge in ----> this way"<<endl;
        cin>>x>>y;
        arr1[x].push_back(y);
        arr2[y].push_back(x);
    }
    DFS(0);
    cout<<" strongly connected component "<<endl;
    while(!st.empty()){
        int k=st.top();
        st.pop();
        if(visited2[k]!=1){
            r++;
            cout<<endl;
            DFS2(k);
        }
    }
    cout<<endl;
    cout<<"Total number of strongly connected component = "<<r<<" follows above "<<endl;
    return 0;
}