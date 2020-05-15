#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#define MAX 10000
using namespace std;
typedef long long ll;
typedef struct {
	ll xpos;
	ll ypos;
}Point;
ll ccw(Point p0,Point p1,Point p2) {
	Point p[3] = { p0,p1,p2 };
	Point v[2];
	v[0].xpos = (p[1].xpos - p[0].xpos);
	v[0].ypos = (p[1].ypos - p[0].ypos);
	v[1].xpos = (p[2].xpos - p[0].xpos);
	v[1].ypos = (p[2].ypos - p[0].ypos);

	return v[0].xpos * v[1].ypos - v[0].ypos * v[1].xpos;
}

int main(void)
{	
	ll sum = 0;
	int n;
	cin >> n;
	Point p[MAX];
	for (int i = 0; i < n; i++) {
		cin >> p[i].xpos;
		cin >> p[i].ypos;
	}
	
	for (int i = 1; i <= n - 2; i++) {
		sum += ccw(p[0], p[i], p[i + 1]);
	}
	printf("%.1lf\n", abs(sum/2.0));
	return 0;
}