#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);
typedef long long ll;

const int MX = 500000;

int N;
int arr[MX];
int tmp[MX];
ll result;

void merge_sort(int left, int right){
    if(left >= right) return;

    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);

    int i=left, j=mid+1, k=left;
    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }
        else{
            tmp[k++] = arr[j++];
            result += mid - i + 1;
        }
    }
    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=right) tmp[k++] = arr[j++];
    for(int i=left; i<=right; i++) arr[i] = tmp[i];
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    merge_sort(0, N-1);

    cout << result << '\n';

    return 0;
}