#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long get_age(vector<string> v){
    return stoll(v[0]) + stoll(v[1])*30 + stoll(v[2])*12*30;
}

struct Student{
    string name;
    int day, month, year, total;
};

int main(void){
    int N;
    cin >> N;
    vector<Student> students(N);

    for(int i=0; i<N; i++){
        cin >> students[i].name >> students[i].day >> students[i].month >> students[i].year;
        students[i].total = students[i].day + students[i].month*30 + students[i].year*12*30;
    }
    Student young = students[0];
    Student old = students[0];

    for(int i=1; i<N; i++){
        if(students[i].total > young.total){
            young = students[i];
        }
        else if(students[i].total < old.total){
            old = students[i];
        }
    }

    cout << young.name << endl << old.name << endl;
    return 0;
}