#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
int main() {
	struct Node* head = NULL;
	struct Node* tail = NULL;
	for (int i = 1; i <= 5; i++) {

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

		newNode->data = i * 10;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	struct Node* current = head;
	struct Node* previous = NULL;
	printf("---30이 들어있는 칸 삭제---\n");

	while (current != NULL && current->data != 30) {
		previous = current;
		current = current->next;
	}
	if (current != NULL) {
		if (previous == NULL) {
			head = current->next;
		}
		else {
			previous->next = current->next;
		}
		printf("데이터 30을 찾아서 연결을 끊고 폭파시킵니다.\n");
		free(current);
	}
	else {
		printf("삭제하려는 30이 없습니다.");
	}

	printf("\n---삭제 후 남은 기차 상태---\n");
	current = head;
	while (current != NULL) {
		printf("현재 칸의 데이터: %d\n", current->data);
		current = current->next;
	}

	current = head;
	struct Node* nextNode;

		while (current != NULL) {
			nextNode = current->next;
			printf("데이터 %d가 들어있는 칸을 반납합니다.\n", current->data);
			free(current);
			current = nextNode;
		}
		head = NULL;
	
	return 0;
}