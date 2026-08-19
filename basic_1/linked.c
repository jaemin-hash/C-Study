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

	printf("---30이 들어있는 칸 찾기---\n");

	while (current != NULL) {

		if (current->data == 30) {

			printf("찾았다! 데이터30이 들어있는 칸을 발견했습니다.\n");

			break;

		}

		current = current->next;



	}

	if (current == NULL) {

		printf("기차를 다 뒤졌지만 30은 없었습니다.");

	}



	current = head;

	struct Node* nextNode;

	{

		while (current != NULL) {

			nextNode = current->next;

			printf("데이터 %d가 들어있는 칸을 반납합니다.\n", current->data);

			free(current);

			current = nextNode;

		}

		head = NULL;

	}

	return 0;



}