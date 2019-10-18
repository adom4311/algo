/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
vector <int> que;
void dequeue() {
	vector <pair<int, int>> find;
	if (que.size() == 0) {
		printf("%d ", -1);
		return;
	}
	else {
		for (int i = 0; i < que.size(); i++) {
			if (i == 0) {
				find.push_back(make_pair(que[i], 1));
			}
			else {
				for (int j = 0; j < find.size(); j++) {
					if (que[i] == find[j].first) {
						find[j].second = find[j].second+1;
						break;
					}
					if(j==find.size()-1){
						
						find.push_back(make_pair(que[i], 1));
						
					}
				}
			}
		}
	}
	int max = 0;
	int maxidx = 0;
	vector <int> maxes;
	for (int i = 0; i < find.size(); i++) {
		
		if (find[i].second > max) {
			max = find[i].first;
			maxidx = i;
		}
	}
	maxes.push_back(max);
	for (int i = 0; i < find.size(); i++) {
		if (find[i].first == max) {
			maxes.push_back(find[i].first);
		}
	}
	for (int i = 0; i < que.size(); i++) {
		for (int j = 0; j < maxes.size(); j++) {
			if (que[i] == maxes[j]) {
				printf("%d", que[i]);
				que.erase(que.begin() + i);
				return;
			}
		}
	}

}


int main() {
	int N;
	char command[20] = { 0x00, };
	int number;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		memset(&command, 0x00, sizeof(command));
		scanf("%s", command);
		if (command[0] == 'e') {
			scanf("%d", &number);
			que.push_back(number);
		}
		else {
			dequeue();
		}
	}
	return 0;
}*/