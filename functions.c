#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"
void create(person **arr,int *n){
	printf("n=");
	scanf("%d",n);
	if(*n<=0)
		return;
	*arr=(person*)calloc(*n,sizeof(person));
	for(int i=0;i<*n;i++){
		printf("name=");
		scanf("%s",(*arr)[i].name);
		printf("age=");
                scanf("%d",&(*arr)[i].age);
		printf("salary=");
                scanf("%d",&(*arr)[i].salary);
		}
	}
void read(person **arr,int *n){
	FILE *fp=fopen("file.txt","r");
	if(!fp)
		return;
	if(fscanf(fp,"%d",n)!=1){
		fclose(fp);
		return;
		}
	if(*n<=0){
		fclose(fp);
		return;
		}
	*arr=(person*)calloc(*n,sizeof(person));
	for(int i=0;i<*n;i++){
		if(fscanf(fp,"%s %d %d",(*arr)[i].name,&(*arr)[i].age,&(*arr)[i].salary)!=3)
		break;
		}
	fclose(fp);
}
void write(person*arr,int n){
	if(n<=0)
		return;
	FILE *fp=fopen("file.txt","w");
	if(!fp)
		return;
	fprintf(fp,"%d\n",n);
	for(int i=0;i<n;i++)
		fprintf(fp,"%s %d %d\n", arr[i].name,arr[i].age,arr[i].salary);
	fclose(fp);
	};
void search(person *arr, int n){
	int key;
	printf("Search by: 1-Name,2-Age,3-Salary\n");
	scanf("%d",&key);
	switch(key){
			case 1:{
				char Name[40];
				int ans1=0;
				printf("Enter name:");
				scanf("%s",Name);
				for(int i=0;i<n;i++){
					if(!strcmp(arr[i].name,Name)){
						printf("Found: %s %d %d\n", arr[i].name,arr[i].age,arr[i].salary);
						ans1=1;
						}
				}
				if(!ans1)
					printf("Not found\n");
				break;
				}
			case 2:{
				int Age;
				int ans2=0;
				printf("Enter age:");
				scanf("%d",&Age);
				for(int i=0;i<n;i++){
					if(Age==arr[i].age){
						printf("Found: %s %d %d\n", arr[i].name,arr[i].age,arr[i].salary);
						ans2=1;
						}
				}
				if(!ans2)
					printf("Not found\n");
				break;
				}
			case 3:{
				int Salary;
				int ans3=0;
                                printf("Enter salary:");
                                scanf("%d",&Salary);
                                for(int i=0;i<n;i++){
                                        if(Salary==arr[i].salary){
                                                printf("Found: %s %d %d\n", arr[i].name,arr[i].age,arr[i].salary);
                                                ans3=1;
                                                }
				}
                                if(!ans3)
                                        printf("Not found\n");
                                break;
                                }
			default:
				break;
			};
	}


