/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int N;
vector <vector <int>> shark_pool;
int sharksize = 2;
pair <int, int> babyshark;
int minx, miny;
typedef struct {
	int size;
	int x, y;
} fish;

vector <fish> food;



int eating_food() {
	//find shortest path to food
	//timer change and babyshark locate change
	//eating count change if eating enought to growing up then change shark size

}

void find_closest_Fish() {
	int mindist = -1;
	for (int i = 0; i < food.size(); i++) {
		//find shortest food
		if (food[i].size == 0 || food[i].size > sharksize) {
			continue;
		}
		int dist = abs(food[i].x - babyshark.first) + abs(food[i].y - babyshark.second);
		if (mindist < 0 || mindist>dist) {
			mindist = dist;
			minx = food[i].x;
			miny = food[i].y;
		}
		
	}
	//if no food that shark can eat return -1;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		vector <int> tmp(N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp[j]);
			if (tmp[j] == 9) {
				babyshark.first = i;
				babyshark.second = j;
			}
			else if (tmp[j] != 0) {
				fish tmpfish;
				tmpfish.size = tmp[j];
				tmpfish.x = i;
				tmpfish.y = j;
				food.push_back(tmpfish);
			}
		}
		shark_pool.push_back(tmp);
	}

	while (1) {
		if (find_closest_Fish() < 0) {
			//solution is timer
		}
		eating_food();

	}

	//printf("%d", solution);
	

	return 0;
}*/