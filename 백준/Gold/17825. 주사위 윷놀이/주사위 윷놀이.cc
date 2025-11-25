#include <iostream>
#include <unordered_map>
using namespace std;

struct Info{
	int num, scr;
};

const int MX = 10;
const int MXN = 50;

int arr[MX];
Info maps[MXN];
int horse[4];
int finish[4];
int result;
unordered_map<int, int> Map = {
	{5, 22}, {10, 31}, {15, 28}
};

void init(){
	for(int i=0; i<=32; i++){
		maps[i].num = i+1;
		maps[i].scr = i * 2;
	}
	maps[21] = {21, 0};

	maps[22] = {23, 13};
	maps[23] = {24, 16};
	maps[24] = {25, 19};

	maps[25] = {26, 25};
	maps[26] = {27, 30};
	maps[27] = {20, 35};

	maps[28] = {29, 28};
	maps[29] = {30, 27};
	maps[30] = {25, 26};

	maps[31] = {32, 22};
	maps[32] = {25, 24};


	// for(int i=0; i<=32; i++){
	// 	cout << maps[i].num << ' ' << maps[i].scr << "\n";
	// }
}

void input(){
	for(int i=0; i<10; i++){
		cin >> arr[i];
	}
}

bool is_avail(int idx, int loc){
	for(int i=0; i<4; i++){
		if(i == idx) continue;
		if(horse[i] == loc) return false;
	}
	return true;
}

void dfs(int idx, int score){
	if(idx == 10){
		result = max(result, score);
		return;
	}

	for(int i=0; i<4; i++){
		if(finish[i] == 1) continue;

		int now_loc = horse[i];

		int nxt_loc = horse[i];
		int rest = arr[idx];
		if(Map.count(nxt_loc)){
			rest--;
			nxt_loc = Map[nxt_loc];
		}
		for(int j=0; j<rest; j++){
			nxt_loc = maps[nxt_loc].num;
		}

		if(!is_avail(i, nxt_loc)) continue;

		if(nxt_loc == 21){
			horse[i] = 0;
			finish[i] = 1;	
		}
		else{
			horse[i] = nxt_loc;
		}
		
		dfs(idx+1, score + maps[nxt_loc].scr);

		horse[i] = now_loc;
		finish[i] = 0;

	}

}

void solution(){
	dfs(0, 0);
}

int main() {
	init();
	
	input();

	solution();

	cout << result << '\n';

	return 0;
}