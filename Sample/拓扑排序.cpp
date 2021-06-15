//输出拓扑排序 
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;  //边的数量
int m;  //顶点的数量 
vector<vector<int>> graph;  //邻接表存图
vector<int> ans; 
vector<int> in;

void topo_sort(){
	for(int i = 1; i <= m; i++){
		for(auto j : graph[i]){
			in[j]++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= m; i++){
		if(in[i] == 0){
			q.push(i);
			ans.push_back(i);
		}
	}
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(auto i : graph[temp]){
			in[i]--;
			if(in[i] == 0){
				q.push(i);
				ans.push_back(i);
			}
		}
	}
	
}

int main()
{
	cin >> m >> n;
	in.resize(m + 1, 0);
	graph.resize(m + 1);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	} 
	topo_sort();
	if(ans.size() == m){
		for(auto i : ans){
			cout << i <<" ";
		}
	}
	else{
		cout << "有环" <<endl; 
	} 
	return 0;
}