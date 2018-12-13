#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node

	//1. reading the movie.dat-----------------------------
	fp = fopen("movie.dat","r"); //1.1 FILE open
	
	list = list_genList(); //1.2 list generation (use function list_genList() )
	
	printf("Reading the data files...\n");//������ �б��� ���� �޼��� 
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( fscanf(fp,"%s %s %i %f", name, country, &runTime, &score) != EOF /* read name, country, runtime and score*/ )
	{	
		mvInfo = mv_genMvInfo(name, score, runTime, country); //generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);
	}//����,���۱���, ����ð�, ������ ���� ��ȭ������ �����ϰ� ����Ʈ�� ������ �ϳ��� ���δ�. 

	fclose(fp);//1.4 FILE close
	
	
	printf("Read done! %i items are read\n", list_len(list));//����Ʈ�� �ѱ��̸� �ľ��Ͽ� ��ȭ�� ������ ����. 
	
	//2. program start
	while(exit_flag == 0) 
	{
		
		printf("-------------------- Menu --------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score movies\n");
		printf("5. exit\n");
		printf("-------------------- Menu --------------------\n\n");

		printf("-- select an option : ");
		scanf("%i", &option); //2.1 print menu message and get input option
		
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list; //��������Ͱ� ����Ʈ�� ����Ű���� �Ѵ�. 
				
				while ( list_isEndNode(ndPtr) == 0 /* repeat until the ndPtr points to the end node */)
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr);//ndPtr = the next node of the ndPtr;
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					mv_print(mvInfo);//print the contents of the mvInfo
					printf("-------------------\n");
				}
				
				
				break;
			
	
			case 2: //print movies of specific country
				printf("select a country : ");
				scanf("%s", country); //2.3.1 get country name to search for
				
				ndPtr = list;
				int cnt = 0;//cnt�� �����ϰ� �ɼ��� �����Ҷ� ���� 0���� �����ϵ��� �Ѵ�. 

				while (list_isEndNode(ndPtr) == 0 /* repeat until the ndPtr points to the end node */)
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr);//ndPtr = the next node of the ndPtr;
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
				
					if(strcmp(country, mv_getCountry(mvInfo)) == 0)//����Ʈ�� �ִ� ������ �Լ��� ���� ������ ���ڿ��� ������ ���Ѵ� 
					{
						mv_print(mvInfo);//mv_print()�Լ��� �̿��Ͽ� ��ȭ������ ����Ѵ�. 
						printf("\n");
						cnt++;//���ǿ� �´� ��ȭ�� ������ ���� ���� cnt�� ������Ų��. 
					}//if the input country matches to the country of the movie,
					//then print the contents of the mvInfo
					
				}
				
				printf("--------------------\n");
				printf("\n");
				printf("totally %i movies are listed\n", cnt);
				printf("\n");
				
				break;
				
			case 3:
				//print movies of more than specific runtime
				printf("lowest runtime : ");
				scanf("%i", &runTime);//2.4.1 get minimal runtime value to search for
				
				ndPtr = list;
				cnt=0;
				
					while (list_isEndNode(ndPtr) == 0 /* repeat until the ndPtr points to the end node */)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr);//ndPtr = the next node of the ndPtr;
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					
					if(runTime <= mv_getRunTime(mvInfo))//����Ʈ�� �ִ� ������ �Լ��� ���� ������ ũ�⸦  ���Ѵ� 
					{
						mv_print(mvInfo);
						printf("\n");
						cnt++;
					}
					//if the input runtime is lower than the runtime of the movie,
					//then print the contents of the mvInfo
				}
				printf("--------------------\n");
				printf("\n");
				printf("totally %i movies are listed\n", cnt);
				printf("\n");
				
				break;
				
			case 4:
				//print movies of more than specific score
				printf("lowest score : ");
				scanf("%f", &score);//2.5.1 get minimal score value to search for
				
				ndPtr = list;
				cnt=0;
				
				while (list_isEndNode(ndPtr) == 0 /* repeat until the ndPtr points to the end node */)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr);//ndPtr = the next node of the ndPtr;
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					
					if(score <= mv_getScore(mvInfo))//����Ʈ�� �ִ� ������ �Լ��� ���� ������ ���ڿ��� ������ ���Ѵ� 
					{
						mv_print(mvInfo);
						printf("\n");
						cnt++;
					}
					//if the input score is lower than the score of the movie,
					//then print the contents of the mvInfo
				}
				printf("--------------------\n");
				printf("\n");
				printf("totally %i movies are listed\n", cnt);
				printf("\n");
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break; //5���� ������ �����Ѵ�. 
				
			default:
				printf("wrong command! input again\n");
				break;//case�� �ִ� ����� �ƴϸ� ����Ѵ�. 
		}
	}
	
	return 0; 
}
