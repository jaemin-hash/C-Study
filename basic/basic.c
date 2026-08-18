#include<stdio.h>
struct memoryblock {
	int id;
	int size;
	int is_free;
};

struct memoryblock pool[3];

int my_malloc(int requested_size) {
	int best_id = -1;
	int min_diff = 999999;
	for (int i = 0;i < 3;i++) {
		if (pool[i].is_free == 1 && pool[i].size >= requested_size) {
			int diff = pool[i].size - requested_size;
			if (diff < min_diff) {
				min_diff = diff;
				best_id = pool[i].id;
			}
		}
	}
	if (best_id != -1) {
		for (int i=0; i < 3; i++) {
			if (pool[i].id == best_id) {
				pool[i].is_free = 0;
				printf("[알림] best-fit으로 %d번 블록을 할당되었습니다.\n",pool[i].id);
				return pool[i].id;
			}
		}
	}
	printf("[알림] 맞는 방이 없습니다\n");
	return -1;
};
void my_free(int target_id) {
	for (int i = 0;i < 3;i++) {
		if (pool[i].id == target_id) {
			pool[i].is_free = 1;
			printf("[알림] %d번 블록이 반환되었습니다.\n",pool[i].id);
			break;
		}
	}
};
int main() {
	int choice;
	int current_size = 512;
	for (int i = 0;i < 3;i++) {
		pool[i].id = i + 1;
		pool[i].is_free = 1;
		pool[i].size = current_size;
		current_size = current_size * 2;
	}

	while (1) {
		printf("\n----키오스크----\n");
		printf("1번. 메모리 할당\n");
		printf("2번. 메모리 반환\n");
		printf("3번. 전체 상태보기\n");
		printf("4번. 프로그램 종료\n");
		printf("선택:");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1: {
			printf("메모리 할당하세요(size):");
			int x;
			scanf_s("%d", &x);
			my_malloc(x);
			break;
		}
		case 2: {
			printf("메모리 반환하세요(id):");
			int y;
			scanf_s("%d", &y);
			my_free(y);
			break;
		}
		case 3:for (int n = 0;n < 3;n++) {
			printf("[블록 %d] 크기: %d, 빈공간 여부: %d\n", pool[n].id, pool[n].size, pool[n].is_free);
		}
			  break;
		case 4: return 0;


		}


	}
}