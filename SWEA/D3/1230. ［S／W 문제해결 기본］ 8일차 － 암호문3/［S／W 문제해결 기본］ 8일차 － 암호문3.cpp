#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(nullptr);

constexpr int MAX_NODE = 10000;
constexpr int MAX_CMD = 500;

struct Node{
    int data;
    Node* next;
};

Node nodePool[MAX_NODE];
int nodeCnt = 0;
Node head; 

Node* create_node(int data){
    if(nodeCnt >= MAX_NODE) return nullptr;
    Node* newNode = &nodePool[nodeCnt++];
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int N, M;
int result;

void init(){
    head.next = nullptr;
    nodeCnt = 0;
}

Node* get_node_at(int x){
    Node* cur = &head;
    for(int i=0; i<x && cur->next != nullptr; i++){
        cur = cur->next;
    }
    return cur;
}

void insert(int x, int y){
    Node* getNode = get_node_at(x);
    for(int j=0; j<y; j++){
        int data;
        cin >> data;
        Node* newNode = create_node(data);
        if(newNode == nullptr) return;
        newNode->next = getNode->next;
        getNode->next = newNode;
        getNode = newNode;
    }
}

// void deleteNode(int x, int y){
//     Node* prevNode = get_node_at(x);
//     Node* curNode = prevNode->next;

//     while(y-- && curNode != nullptr){
//         curNode = curNode->next;
//     }
//     prevNode->next = curNode;
// }

void deleteNode(int x, int y){
    Node* prevNode = get_node_at(x);
    Node* curNode = prevNode->next;

    while(y-- && curNode != nullptr){
        prevNode->next = curNode->next;
        curNode = prevNode->next;
    }
}

void append(int y){
    Node* lastNode = &head;
    while(lastNode->next != nullptr){
        lastNode = lastNode->next;
    }
    for(int j=0; j<y; j++){
        int data;
        cin >> data;
        Node* newNode = create_node(data);
        if(newNode == nullptr) return;
        lastNode->next = newNode;
        lastNode = newNode;
    }
}

void input(){
    Node* cur = &head;

    cin >> N;
    for(int i=0; i<N; i++){
        int data;
        cin >> data;
        Node* newNode = create_node(data);
        cur->next = newNode;
        cur = newNode;
    }

    cin >> M;
    for(int i=0; i<M; i++){
        string command;
        cin >> command;
        if(command == "I"){
            int x, y;
            cin >> x >> y;

            insert(x, y);
        }
        else if(command == "D"){
            int x, y;
            cin >> x >> y;

            deleteNode(x, y);
        }
        else if(command == "A"){
            int y;
            cin >> y;
            
            append(y);
        }
    }
}

void print_result(int t){
    Node* cur = head.next;
    cout << '#' << t << ' ';
    for(int i=0; i<10 && cur != nullptr; i++){
        cout << cur->data << ' ';
        cur = cur->next;
    }
    cout << '\n';
}

int main(void){
    fastio;
    
    // freopen("input.txt", "r", stdin);

    int T=10;
    for(int t=1; t<=T; t++){    
        init();
        input();
        print_result(t);
    }

    return 0;
}