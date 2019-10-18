/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int shark_cnt;
vector <vector<int>> shark;
int eaten_shark_size = 0;

typedef struct {
	int num;
	int size;
	int dst;
	int speed;
} st_shark;

void do_clock(int time) {

}

int main(void) {
	st_shark null_shark;
	null_shark.size = 0;
	scanf("%d %d %d", &N, &M, &shark_cnt);
	vector < vector<st_shark>> fishing_pool(N, vector<st_shark>(M, null_shark));
	vector < vector<st_shark>> tmp_pool(N, vector<st_shark>(M, null_shark));

	for (int i = 0; i < shark_cnt; i++) {
		vector <int> tmp(6);
		scanf("%d %d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4]);
		tmp[5] = 1;
		fishing_pool[tmp[0]][tmp[1]].num = i;
		fishing_pool[tmp[0]][tmp[1]].speed = tmp[2];
		fishing_pool[tmp[0]][tmp[1]].dst = tmp[3];
		fishing_pool[tmp[0]][tmp[1]].size = tmp[4];
		shark.push_back(tmp);

	}

	for (int fisher = 0; fisher < M; fisher++) {

		//catch shark zone
		for (int detect = 0; detect < N; detect++) {
			if (fishing_pool[detect][fisher].size != 0) {
				eaten_shark_size += fishing_pool[detect][fisher].size;
				fishing_pool[detect][fisher].size = 0;
				shark[fishing_pool[detect][fisher].num][5] = 0;
				break;
			}
		}

		//move shark zone
		for (int mv = 0; mv < shark_cnt; mv++) {
			if (shark[mv][5] == 0)
				continue;
			if (shark[mv][3])
		}

	}


	return 0;
}*/