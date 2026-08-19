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
		newNode->data = i*10;
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
	printf("---완성된 기차 순회 결과---\n");
	while (current != NULL) {
		printf("현재 칸의 데이터:%d\n", current->data);
		current = current->next;

	}
	return 0;

}