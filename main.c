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
	
	printf("Reading the data files...\n");//데이터 읽기전 띄우는 메세지 
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( fscanf(fp,"%s %s %i %f", name, country, &runTime, &score) != EOF /* read name, country, runtime and score*/ )
	{	
		mvInfo = mv_genMvInfo(name, score, runTime, country); //generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);
	}//제목,제작국가, 영상시간, 평점에 관한 영화정보를 생성하고 리스트의 꼬리에 하나씩 붙인다. 

	fclose(fp);//1.4 FILE close
	
	
	printf("Read done! %i items are read\n", list_len(list));//리스트의 총길이를 파악하여 영화의 개수를 센다. 
	
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
				
				ndPtr = list; //노드포인터가 리스트를 가리키도록 한다. 
				
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
				int cnt = 0;//cnt를 선언하고 옵션을 선택할때 마다 0부터 시작하도록 한다. 

				while (list_isEndNode(ndPtr) == 0 /* repeat until the ndPtr points to the end node */)
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					ndPtr = list_getNextNd(ndPtr);//ndPtr = the next node of the ndPtr;
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
				
					if(strcmp(country, mv_getCountry(mvInfo)) == 0)//리스트에 있는 정보와 함수로 받은 정보의 문자열이 같은지 비교한다 
					{
						mv_print(mvInfo);//mv_print()함수를 이용하여 영화정보를 출력한다. 
						printf("\n");
						cnt++;//조건에 맞는 영화의 개수를 세기 위해 cnt를 증감시킨다. 
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
					
					if(runTime <= mv_getRunTime(mvInfo))//리스트에 있는 정보와 함수로 받은 정보의 크기를  비교한다 
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
					
					if(score <= mv_getScore(mvInfo))//리스트에 있는 정보와 함수로 받은 정보의 문자열이 같은지 비교한다 
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
				break; //5번을 누르면 종료한다. 
				
			default:
				printf("wrong command! input again\n");
				break;//case에 있는 명령이 아니면 출력한다. 
		}
	}
	
	return 0; 
}
