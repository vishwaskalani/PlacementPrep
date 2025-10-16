#include <bits/stdc++.h>
using namespace std;

struct obj {
	int a;
	int b;
	int c;
};

bool customComp(const obj &o1, const obj &o2) {
	if (o1.a != o2.a) return o1.a < o2.a;
	if (o1.b != o2.b) return o1.b > o2.b;
	return o1.c < o2.c;
}

int main() {

	// sorting using the custom comparator
	vector<obj> arr = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {1, 2, 2}};
	sort(arr.begin(), arr.end(), customComp);
	for (auto &o : arr) {
		cout << o.a << " " << o.b << " " << o.c << endl;
	}
	return 0;
}