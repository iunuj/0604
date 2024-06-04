#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink, * rlink;
} DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {

	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));  //<1>
	newnode->data = data;  // <1>
	newnode->llink = before;  // <2>
	newnode->rlink = before->rlink; // <3>
	//	before->rlink->llink = newnode; // <5>
	//	before->rlink = newnode; // <4>
	before->rlink = newnode; // <4>
	newnode->rlink->llink = newnode; // <5>
}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		printf(" %d -> ", p->data);
	}
	printf("\n");
}

element ddelete(DListNode* head, DListNode* removed) {
	element r;
	if (removed == head) return;
	r = removed->data;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	return r;
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	int choice, data;

	while (1) {
		printf("\n�޴�\n");
		printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3. ����Ʈ ó�� ��� ����\n");
		printf("4. ����Ʈ ������ ��� ����\n");
		printf("5. ����Ʈ ����Ʈ\n");
		printf("6. ����\n");
		printf("���� : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("�߰��� ���� �Է�: ");
			scanf("%d", &data);
			dinsert(head, data);
			break;
		case 2:
			printf("�߰��� ���� �Է�: ");
			scanf("%d", &data);
			dinsert(head->llink, data);
			break;
		case 3:
			if (head->rlink != head) {
				ddelete_node(head, head->rlink);
			}
			else {
				printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
			}
			break;
		case 4:
			if (head->llink != head) {
				ddelete_node(head, head->llink);
			}
			else {
				printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
			}
			break;
		case 5:
			print_dlist(head);
			break;
		case 6:
			printf("���α׷� ����\n");
				return 0;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���\n");
		}

	}
	return 0;
}