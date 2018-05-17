// StackTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
	int data;
	struct node *next;
};
struct node *first;

void push();
void pop();
void print();

int _tmain(int argc, _TCHAR* argv[])
{
	time_t t;
	//time(&t);
	//printf("\nSystem Time : %s", ctime(&t));
	char ch;
	int choice;
START:
	printf("\n1.Push\n2.Pop\n3.Print\n4.Clear Screen\n5.Exit\n\n");
	do
	{
		printf("Enter Choice : ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: print();
			break;
		case 4: system("cls");
			goto START;
			break;
		case 5: printf("\nExiting...");
			break;
		default: printf("\nWrong Choice!!!");
		}
	} while (choice != 4);
	return 0;
}

void push()
{
	if (first == NULL)
	{
		struct node *ptr;
		ptr = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter Data : ");
		scanf_s("%d", &ptr->data);
		ptr->next = NULL;
		first = ptr;
		printf("Data PUSHED : %d\n", ptr->data);
	}
	else
	{
		struct node *ptr, *cpt;
		ptr = first;
		cpt = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data : ");
		scanf_s("%d", &cpt->data);
		cpt->next = ptr;
		ptr = cpt;
		first = ptr;
		printf("Data PUSHED : %d\n", cpt->data);
	}
}

void pop()
{
	if (first == NULL)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		struct node *ptr, *cpt;
		ptr = first;
		cpt = ptr->next;
		first = cpt;
		printf("\nData Popped : %d\n", ptr->data);
		free(ptr);
	}
}
void print()
{
	struct node *ptr;
	ptr = first;
	if (ptr == NULL)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		printf("\nData In Stack\n");
		printf("*****************\n");
		while (ptr != NULL)
		{
			printf("  %d\n", ptr->data);
			ptr = ptr->next;
		}
		printf("*****************\n");
	}
}
