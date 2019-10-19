/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <queue>

using namespace std;
int section;
int minsum = -1;
vector<int> population;
vector <vector <int>> con;
//vector <int> a; //district A
//vector <int> b; //district B
vector <int> checker;


int isconnect(int src, int dst, int ary[], int arysize) {
	int srcidx=0;
	if (con[src][dst] == 1)
		return 1;
	else {
		for (int i = 0; i < arysize; i++) {
			if (ary[i] == src) {
				srcidx = i;
				checker[i] = 1;
			}
		}
		for (int ps = 0; ps < con[src].size(); ps++) {
			if (checker[con[src][ps]] == 1)
				continue;
			else {
				if (isconnect(con[src][ps], dst, ary, arysize) == 1) {
					return 1;
				}
			}
		}
	}
	checker[srcidx] = 0;
	return 0;
	
}

void distribute_district(int a[], int b[], int asize, int bsize, int count) {
	if (count == section) {
		//ispossible
		if (a[0] == -1 || b[0] == -1) {
			return;
		}
		checker.resize(asize, 0);
		for (int i = 0; i < asize; i++) {
			for (int j = i + 1; j < asize; j++) {
				if (isconnect(i, j, a, asize) == 0) {
					return;
				}
			}
		}
		checker.clear();
		checker.resize(bsize, 0);
		for (int i = 0; i < bsize; i++) {
			for (int j = i + 1; j < bsize; j++) {
				if (isconnect(i, j, b, bsize) == 0) {
					return;
				}
			}
		}
		int asum = 0;
		int bsum = 0;
		for (int i = 0; i < asize; i++) {
			asum += population[a[i]];
		}
		for (int i = 0; i < bsize; i++) {
			bsum += population[b[i]];
		}
		int gap = abs(bsum - asum);
		if (minsum<0 || minsum>gap) {
			minsum = gap;
		}
		

	}
	else {
		a[asize] = count;
		distribute_district(a, b, asize + 1, bsize, count + 1);
		a[asize] = -1;
		b[bsize] = count;
		distribute_district(a, b, asize, bsize + 1, count + 1);
	}
}

int main(void) {
	int a[10] = { -1 };
	int b[10] = { -1 };
	scanf("%d", &section);
	for (int i = 0; i < section; i++) {
		int tmp;
		scanf("%d", &tmp);
		population.push_back(tmp);
	}
	for (int i = 0; i < section; i++) {
		vector <int> tmpvec;
		for (int j = 0; j < section; j++) {
			tmpvec.push_back(0);
		}
		con.push_back(tmpvec);
	}
	for (int i = 0; i < section; i++) {
		int near_cnt;
		scanf("%d", &near_cnt);
		for (int j = 0; j < near_cnt; j++) {
			int node;
			scanf("%d", &node);
			con[i][node-1] = 1;
		}
	}

	distribute_district(a, b, 0, 0, 0);
	printf("%d", minsum);

	

	return 0;
}*/