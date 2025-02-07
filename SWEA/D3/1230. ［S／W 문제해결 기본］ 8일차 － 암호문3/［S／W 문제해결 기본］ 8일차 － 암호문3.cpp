#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX_NODE = 5000;
constexpr int MAX_CMD = 500;

struct Node {
    int data;
    Node* next;
};

Node node_pool[MAX_NODE];
int node_count;
Node head;

Node* new_node(int data) {
    node_pool[node_count].data = data;
    node_pool[node_count].next = nullptr;
    return &node_pool[node_count++];
}

void init() {
    head.next = nullptr;
    node_count = 0;
}

Node* getNodeAt(int x) {
    Node* cur = &head;
    for (int i = 0; i < x && cur->next != nullptr; i++) {
        cur = cur->next;
    }
    return cur;
}

void insert(int x, int y) {
    Node* pos = getNodeAt(x);
    while (y--) {
        int val;
        cin >> val;
        Node* newNode = new_node(val);

        newNode->next = pos->next;
        pos->next = newNode;
        pos = newNode;
    }
}

void remove(int x, int y) {
    Node* prev = getNodeAt(x);
    Node* cur = prev->next;

    while (y-- && cur != nullptr) {
        cur = cur->next;
    }
    
    prev->next = cur;
}

void append(int y) {
    Node* cur = &head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    while (y--) {
        int val;
        cin >> val;
        Node* newNode = new_node(val);
        cur->next = newNode;
        cur = newNode;
    }
}

void printList(int t) {
    cout << "#" << t << " ";
    Node* cur = head.next;
    for (int i = 0; i < 10 && cur != nullptr; i++) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    for (int test_case = 1; test_case <= 10; test_case++) {
        init();

        int N, M;
        cin >> N;

        Node* cur = &head;
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            Node* newNode = new_node(val);
            cur->next = newNode;
            cur = newNode;
        }

        cin >> M;

        while (M--) {
            char cmd;
            cin >> cmd;

            if (cmd == 'I') {
                int x, y;
                cin >> x >> y;
                insert(x, y);
            }
            else if (cmd == 'D') {
                int x, y;
                cin >> x >> y;
                remove(x, y);
            }
            else if (cmd == 'A') {
                int y;
                cin >> y;
                append(y);
            }
        }

        printList(test_case);
    }

    return 0;
}
