#include <stdio.h>
#include <string.h>

#define LEN 50
#define POP 100

typedef struct inf {
	char name[LEN];
	char number[LEN];
}Inf;

void ShowMenu(void);
void Insert(Inf * man, int * pnum);
void Delete(Inf * man, int * pnum);
void Search(Inf * man, int pnum);
void PrintAllData(Inf * man, int pnum);
void LoadData(Inf* man, int* pnum);
void WriteData(Inf* man, int* pnum);

main(void)
{
	int n;
	int pnum = 0;
	Inf man[POP];
	LoadData(man, &pnum);
	
	while (1)
	{
		ShowMenu();
		scanf_s("%d", &n);
		switch (n)
		{
			case 1:
			{
				Insert(man, &pnum);
				break;
			}
			case 2:
			{
				Delete(man, &pnum);
				break;
			}
			case 3:
			{
				Search(man, pnum);
				break;
			}
			case 4:
			{
				PrintAllData(man, pnum);
				break;
			}
			case 5:
			{
				WriteData(man, &pnum);
				return 0;
			}
			default:
			{
				printf("잘못된 접근\n");
				break;
			}
		}
		printf("\n");
	}
	return 0;
}

void ShowMenu(void)
{
	printf("***** MENU *****\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Print All\n");
	printf("5. Exit\n");
	printf("Choose the item:");
}

void Insert(Inf * man, int * pnum)
{
	printf("[ INSERT ]\n");
	printf("Input Name: ");
	scanf_s("%s", man[*pnum].name, LEN);
	printf("Input Tel Number:");
	scanf_s("%s", man[*pnum].number, LEN);
	printf("                Data Inserted\n");
	(*pnum)++;
}

void Delete(Inf* man, int * pnum)
{
	char nam[LEN];
	int i, j;
	Inf* ptr = man;
	printf("[ DELETE ]\n");
	printf("Input Name:");
	scanf_s("%s", nam, LEN);
	for (i = 0; i < *pnum; i++)
	{
		if (strcmp(man[i].name, nam) == 0)
		{
			for (j = i+1;j<*pnum;j++)
			{
				strcpy_s(man[j - 1].name, LEN, man[j].name);
				strcpy_s(man[j - 1].number, LEN, man[j].number);
			}
			break;
		}
	}
	printf("           Data Deleted\n");
	(*pnum)--;
}

void Search(Inf* man, int pnum)
{
	char nam[LEN];
	int i;
	printf(" SEARCH \n");
	printf("Input Name: ");
	scanf_s("%s", nam, LEN);
	for (i = 0; i < pnum; i++)
	{
		if (strcmp(man[i].name, nam) == 0)
		{
			printf("Name: %s   /   Tel: %s \n", man[i].name, man[i].number);
		}
	}
}

void PrintAllData(Inf* man, int pnum)
{
	char nam[LEN];
	int i;
	printf("[ Print All Data ]\n");
	for (i = 0; i < pnum; i++)
	{
		printf("Name: %s   /   Tel: %s \n", man[i].name, man[i].number);
	}
}

void LoadData(Inf * man, int * pnum)
{
	FILE* fp;
	fopen_s(&fp, "text.txt", "rt");
	if (fp == NULL)
	{
		printf("파일 오픈 에러\n");
		return;
	}
	while (1)
	{
		fscanf_s(fp, "%s %s", man[*pnum].name, LEN, man[*pnum].number, LEN);
		if (feof(fp) != 0)
			break;
		(*pnum)++;
	}
	fclose(fp);
}

void WriteData(Inf* man, int* pnum)
{
	FILE* fp;
	int i;
	fopen_s(&fp, "text.txt", "wt");
	if (fp == NULL)
	{
		printf("파일 오픈 에러\n");
		return;
	}
	for (i = 0; i < *pnum; i++)
	{
		fprintf(fp, "%s %s ", man[i].name, man[i].number);
	}
	fclose(fp);
}