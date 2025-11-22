#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 100001;

int N;
int arr[MX];
int ps[MX];
int result;

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
		ps[i] = ps[i-1] + arr[i];
	}
}

// bee - honey - bee
void case_1(){
	int b1 = 1, b2 = N;
	for(int h=2; h<N; h++){
		result = max(result, ps[h]-ps[b1] + ps[b2-1]-ps[h-1]);
	}
}

// bee - bee - honey
void case_2(){
	int b1 = 1, h = N;
	for(int b2=2; b2<N; b2++){
		result = max(result, ps[h]-ps[b1] + ps[h]-ps[b2]-arr[b2]);
	}
}

// honey - bee - bee
void case_3(){
	int h = 1, b2 = N;
	for(int b1=1; b1<N; b1++){
		result = max(result, ps[b1-1]-ps[h-1] + ps[b2-1]-ps[h-1]-arr[b1]);
	}
}

void solution(){
	case_1();

	case_2();

	case_3();
}

void get_result(){
	cout << result << '\n';
}

int main() {
	input();

	solution();

	get_result();

	return 0;
}