#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree {
private:
    map<int,int> timeline;

public:
    int book(int startTime, int endTime) {
        timeline[startTime]++;
        timeline[endTime]--;

        int active = 0;
        int maxActive = 0;

        for (auto &[time, delta] : timeline) {
            active += delta;
            maxActive = max(maxActive, active);
        }

        return maxActive;
    }
};

int main(){
	return 0;
}