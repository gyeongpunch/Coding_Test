#include <iostream>
using namespace std;

const int MX = 100;

int N, M, R;
int arr[MX][MX];
int arrTmp[MX][MX];

void func1(){
	for(int i=0; i<M; i++){
		for(int j=0; j<N/2; j++){
			swap(arr[j][i], arr[N-j-1][i]);
		}
	}
}

void func2(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M/2; j++){
			swap(arr[i][j], arr[i][M-j-1]);
		}
	}
}

void func3(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arrTmp[j][N-i-1] = arr[i][j];
		}
	}
	swap(N, M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arr[i][j] = arrTmp[i][j];
		}
	}
}

void func4(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arrTmp[M-j-1][i] = arr[i][j];
		}
	}
	swap(N, M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arr[i][j] = arrTmp[i][j];
		}
	}
}

void func5(){
	int mx = N/2;
	int my = M/2;
	for(int i=0; i<mx; i++){
		for(int j=0; j<my; j++){
			arrTmp[i][j+my] = arr[i][j];
			arrTmp[i+mx][j] = arr[i+mx][j+my];
			arrTmp[i+mx][j+my] = arr[i][j+my];
			arrTmp[i][j] = arr[i+mx][j];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arr[i][j] = arrTmp[i][j];
		}
	}
}

void func6(){
	int mx = N/2;
	int my = M/2;
	for(int i=0; i<mx; i++){
		for(int j=0; j<my; j++){
			arrTmp[i+mx][j] = arr[i][j];
			arrTmp[i+mx][j+my] = arr[i+mx][j];
			arrTmp[i][j+my] = arr[i+mx][j+my];
			arrTmp[i][j] = arr[i][j+my];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			arr[i][j] = arrTmp[i][j];
		}
	}
}

int main() {
	cin >> N >> M >> R;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}

	int c;
	while(R--){
		cin >> c;
		switch (c){
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
		case 3:
			func3();
			break;
		case 4:
			func4();
			break;
		case 5:
			func5();
			break;
		case 6:
			func6();
			break;
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}