#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char* lTrim(char list[]);
char* rTrim(char list[]);
char* trim(char list[]);
char* nameStr(char list[]);
void printfMenu();
void addStud(char list[][31],float score[], int* n);
void outPut(char list[][31],float score[], int n);
void searchScore(char list[][31],float score[], int n);
void searchName(char list[][31],float score[],int n);
void sortAlpha(char list[][31],float score[],int n);
void sortbyScore(char list[][31],float score[],int n);
int main(int argc, char *argv[]) {
	char list[MAX][31];
	double point[MAX][10];
	int n=0,choice ;
	float score[MAX];
	fflush(stdin);

	printfMenu();
	do {
		printf("\nYour choice : ");
		scanf("%d",&choice);
		fflush(stdin);

		switch(choice) {
			case 1:
				addStud(list,score,&n);
				break;
			case 2:
				outPut(list,score,n);
				break;
			case 3:
				searchScore(list,score,n);
				break;
			case 4:
				searchName(list,score,n);
				break;
			case 5:
				sortAlpha(list,score,n);
				break;
			case 6:
				sortbyScore(list,score,n);
				break;
		}
	} while(choice!=0);
	printf("\nGoobye !!");
	return 0;
}
void printfMenu() {
	printf(" Menu :\n");
	printf("1. Add a student into the list\n");
	printf("2. Print out the all list\n");
	printf("3. Search student by name\n");
	printf("4. Search student by score\n");
	printf("5. Sort the student list by alphabetic order by name\n");
	printf("6. Sort the student list in ascending order by score\n");
	printf("0. Exit \n");
}
void addStud(char list[][31],float score[], int* n) {
	printf("\nEnter name: ");
	scanf("%[^\n]",&list[*n]);
	nameStr(list[*n]);
	printf("\nEnter score: ");
	scanf("%f",&score[*n]);
	//gets(list[*n];
	(*n)++;
}
void outPut(char list[][31],float score[],int n) {
	for(int i=0; i<n; i++) {
		printf("%-20s%.2f\n", list[i],score[i]);
	}
}
void searchScore(char list[][31],float score[], int n) {
	float x;
	int flag =0;
	printf("Enter the score want to search : ");
	scanf("%f",&x);
	for (int i=0; i<n; i++) {
		if (score[i]==x) {
			printf("\n%-15s %.2f",list[i],score[i]);
			flag = 1;
		}
	}
	if (flag==0)
		printf("Not found ");
}
void searchName(char list[][31],float score[],int n) {
	char x[31];
	int flag =0;
	printf("Enter the name want to search : ");
	gets(x);
	nameStr(x);
	for (int i=0; i<n; i++) {
		if (strstr(list[i],x)!=NULL) {
			printf("\n%-15s %.2f",list[i],score[i]);
			flag = 1;
		}
	}
	if (flag==0)
		printf("Not found ");
}
void sortAlpha(char list[][31],float score[],int n) {
	char t[31];
	float tmp;
	char list2[MAX][31];
	float score2[MAX];
	//copy from list to ist 2
	//           score to score2
	for (int i=0; i<n; i++) {
		strcpy(list2[i],list[i]);
		score2[i] = score[i];
	}

	for (int i=0; i<n-1; i++) 
		for (int j=i+1; j<n; j++) 
			if (strcmp(list2[i],list2[j])==1) {
				strcpy(t,list2[i]);
				strcpy(list2[i],list2[j]);
				strcpy(list2[j], t);

				tmp = score2[i];
				score2[i] = score2[j];
				score2[j] = tmp;
			}
	outPut(list2,score2,n);
	
}
void sortbyScore(char list[][31],float score[],int n) {
	char t[31];
	float tmp;
	char list2[MAX][31];
	float score2[MAX];
	//copy from list to ist 2
	//           score to score2
	for (int i=0; i<n; i++) {
		strcpy(list2[i],list[i]);
		score2[i] = score[i];
	}

	for (int i=0; i<n-1; i++) 
		for (int j=i+1; j<n; j++) 
			if (score2[i] > score2[j]) {
				strcpy(t,list2[i]);
				strcpy(list2[i],list2[j]);
				strcpy(list2[j], t);

				tmp = score2[i];
				score2[i] = score2[j];
				score2[j] = tmp;
			}
	outPut(list2,score2,n);		
}
char* lTrim(char list[]) {
	int i=0;
	while (list[i]==' ') i++;
	if (i>0) strcpy (&list[0],&list[i]);
	return list;
}
char* rTrim(char list[]) {
	int i= strlen(list)-1;
	while (list[i] == ' ') i--;
	list[i+1]='\0';//NULL
	return list;
}
char* trim(char list[]) {
	rTrim(lTrim(list));
	char* ptr = strstr(list,"  ");
	while (ptr!=NULL) {
		strcpy(ptr,ptr+1);
		ptr =strstr(list,"  ");
	}
	return list;
}
char* nameStr(char list[]) {
	trim(list);
	strlwr(list);
	int L = strlen(list);
	for (int i=0; i<L; i++)
		if (i==0 || (i>0 && list[i-1]==' ')) list[i] = toupper(list[i]);
	return list;

}