#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Time{
    int s, m, h;

    int toSeconds() const {
        return h*3600 + m*60 + s;
    }

    static Time fromSeconds(int totalSeconds){
        Time t;
        t.h = totalSeconds / 3600;
        t.m = (totalSeconds % 3600) / 60;
        t.s = totalSeconds % 60;
        return t;
    }
};

Time Parse(const string& str){
    Time t;
    stringstream ss(str);
    string tmp;

    getline(ss, tmp, ':');
    t.h = stoi(tmp);
    getline(ss, tmp, ':');
    t.m = stoi(tmp);
    getline(ss, tmp);
    t.s = stoi(tmp);

    return t;
}

int main(void){
    string start, now;
    cin >> now >> start;

    Time now_time = Parse(now);
    Time start_time = Parse(start);

    int now_total_seconds = now_time.toSeconds();
    int start_total_seconds = start_time.toSeconds();

    int remain_seconds = start_total_seconds - now_total_seconds;
    if(remain_seconds < 0){
        remain_seconds += 24 * 3600;
    }

    Time remain = Time::fromSeconds(remain_seconds);

    cout << setw(2) << setfill('0') << remain.h << ':' 
        << setw(2) << setfill('0') << remain.m << ':' 
        << setw(2) << setfill('0') << remain.s << endl;


    return 0;
}