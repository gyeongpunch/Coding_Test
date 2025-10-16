#include <iostream>
#include <vector>
using namespace std;

const int MX = 51;

int N;
vector<int> tree[MX];
int parent[MX];
int root, rmv;
int result;

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> parent[i];
		if(parent[i] != -1){
			tree[parent[i]].push_back(i);
		}
		else{
			root = i;
		}
	}
	cin >> rmv;
}

void solution(int now){
	if(now == rmv) return;

	bool flag = true;
	for(const int &child : tree[now]){
		if(child != rmv){
			solution(child);
			flag = false;
		}
	}
	if(flag) result++;
}

int main() {
	input();

	solution(root);

	cout << result << '\n';

	return 0;
}