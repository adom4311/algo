/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <queue>

using namespace std;

int tc;
int N;


vector <vector <int>> container;
vector <vector <int>> checker;
int mvx[4] = { 0,1,0,-1 };
int mvy[4] = { 1,0,-1,0 };

queue<pair<int,int>> bfs_q;


int find_block_bfs(int day) {
	int totalcnt=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (checker[i][j] == 1 || container[i][j]<=day)
				continue;
			else {
				totalcnt++;
				bfs_q.push(make_pair(i, j));
				while (!bfs_q.empty()) {
					int nowx = bfs_q.front().first;
					int nowy = bfs_q.front().second;
					bfs_q.pop();
					if (container[nowx][nowy] > day) {
						checker[nowx][nowy] = 1;
						for (int mv = 0; mv < 4; mv++) {
							int nxtx = nowx + mvx[mv];
							int nxty = nowy + mvy[mv];
							if (nxtx >= 0 && nxty >= 0 && nxtx < N && nxty < N && checker[nxtx][nxty]==0) {
								bfs_q.push(make_pair(nxtx, nxty));
							}
						}
					}
				}
			}
		}
	}
	return totalcnt;
}

void dfs_process(int day, int x, int y) {
	checker[x][y] = 1;
	for (int mv = 0; mv < 4; mv++) {
		int nxtx = x + mvx[mv];
		int nxty = y + mvy[mv];
		if (nxtx >= 0 && nxty >= 0 && nxtx < N && nxty<N && checker[nxtx][nxty] == 0 && container[nxtx][nxty]>day) {
			dfs_process(day, nxtx, nxty);
		}

	}
}

int find_block_dfs(int day) {
	int totalcnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (container[i][j] <= day || checker[i][j] == 1) {
				continue;
			}
			else {
				totalcnt++;
				dfs_process(day, i, j);
			}
		}
	}
	
	return totalcnt;
}

int main(void) {
	scanf("%d", &tc);
	for (int T = 0; T < tc; T++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			vector <int> tmp(N);
			vector <int> tmpchecker(N);
			for (int j = 0; j < N; j++) {
				scanf("%d", &tmp[j]);
				tmpchecker[j] = 0;
			}
			container.push_back(tmp);
			checker.push_back(tmpchecker);
		}
		int maxblock_bfs = 0;
		for (int day = 1; day <= 100; day++) {
			int blockcnt = find_block_bfs(day);
			if (blockcnt > maxblock_bfs) {
				maxblock_bfs = blockcnt;
			}
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					checker[a][b] = 0;
				}
			}
		}
		int maxblock_dfs=0;
		for (int day = 1; day <= 100; day++) {
			int blockcnt = find_block_dfs(day);
			if (blockcnt > maxblock_dfs) {
				maxblock_dfs = blockcnt;
			}
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					checker[a][b] = 0;
				}
			}
		}
		printf("bfs [%d]\n", maxblock_bfs);
		printf("dfs [%d]\n", maxblock_dfs);

		
		container.clear();
		checker.clear();
	}
	return 0;
}*/