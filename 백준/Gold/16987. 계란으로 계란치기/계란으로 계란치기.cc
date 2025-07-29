#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info{
	int d, w;
};

const int MX = 8;
int N;
Info arr[MX];
vector<int> path;
int result;

void dfs(int idx, int cnt){
	// cout << idx << ' ' << cnt << '\n';

	if(idx == N){
		result = max(result, cnt);
		return;
	}

	if(arr[idx].d <= 0){
		dfs(idx+1, cnt);
		return;
	}

	bool flag = false;
	for(int i=0; i<N; i++){
		if(i == idx) continue;
		if(arr[i].d <= 0) continue;

		arr[i].d -= arr[idx].w;
		arr[idx].d -= arr[i].w;

		if(arr[i].d <= 0) cnt++;
		if(arr[idx].d <= 0) cnt++;
		flag = true;
		dfs(idx+1, cnt);

		if(arr[i].d <= 0) cnt--;
		if(arr[idx].d <= 0) cnt--;

		arr[i].d += arr[idx].w;
		arr[idx].d += arr[i].w;
	}
	if(!flag){
		dfs(idx+1, cnt);
	}
}

int main() {
	// 코드 작성
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i].d >> arr[i].w;
	}

	dfs(0, 0);

	cout << result << '\n';
	
	return 0;
}

/*
탄수화물보단 단백질!
계란에는 내구도가 있다.
각 계란은 상대 무게만큼 내구도가 감소한다.
(7, 5) - (3, 4)
(3, 5) - (3, -1) -> 2는 깨짐

차례대로 쳐서 최대한 많은 계란을 깨자


*/