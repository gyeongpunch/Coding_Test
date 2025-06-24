#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

constexpr int MX_NODE = 500005;

struct Node{
    long long data;
    Node* next;
    Node* prev;
    int init;
};

Node nodePool[MX_NODE];
int nodeCnt = 0;
Node head;

Node* create_node(int data, int init){
    if(nodeCnt >= MX_NODE) return nullptr;
    Node* newNode = &nodePool[nodeCnt++];
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->init = init;
    return newNode;
}

int N;

void print_test(){
    Node* test = &head;
    while(test->next!=nullptr){
        cout << test->next->data << ' ';
        test = test->next;
    }
    cout << '\n';
}

Node* simulation(){
    while(true){
        Node* now = &head;
        if(now->next->next == nullptr) {
            return now->next;
        }
        now = now->next;
        // print_test();
        while(true){
            long long tmp = now->data;
            if(now->prev->data != 0 && now->prev->data <= now->data){
                tmp += now->prev->data;
                now->prev = now->prev->prev;
                now->prev->next = now;
            }
            if(now->next != nullptr && now->next->data <= now->data){
                tmp += now->next->data;
                now->next = now->next->next;
                if(now->next != nullptr) now->next->prev = now;
            }
            now->data = tmp;

            if(now->next == nullptr) break;

            now = now->next;
        }
    }
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    cin >> N;
    long long data;
    Node* now = &head;
    for(int i=0; i<N; i++){
        cin >> data;
        Node* newNode = create_node(data, i+1);
        now->next = newNode;
        newNode->prev = now;
        now = newNode;
    }

    Node* result = simulation();

    cout << result->data << '\n' << result->init << '\n';

    return 0;
}