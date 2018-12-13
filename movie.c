#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr; //mvPtr가 구조체 
	
	mvPtr = (movInfo_t*)malloc( sizeof(movInfo_t) );//allocate memory and set the member variables
	strcpy(mvPtr->madeIn, country);
	strcpy(mvPtr->name, name);//문자열복사함수를 이용하여 포인터가 가리킬 정보를 바꾼다. 
	mvPtr->runTime = runTime;
	mvPtr->score = score;//폰인터가 가리킬 값을 바꾼다. 
	
	return (void*)mvPtr;
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //구조체인 mvPtr가 obj가 되도록 한다. 
	
	return mvPtr->score;//반환값을 mvPtr을 이용하여 바꿔준다. 
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //구조체인 mvPtr가 obj가 되도록 한다. 
	
	return mvPtr->runTime;//반환값을 mvPtr을 이용하여 바꿔준다.
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //구조체인 mvPtr가 obj가 되도록 한다. 
	
	return mvPtr->name;//반환값을 mvPtr을 이용하여 바꿔준다.
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj; //구조체인 mvPtr가 obj가 되도록 한다. 
	
	return mvPtr->madeIn;//반환값을 mvPtr을 이용하여 바꿔준다.
}


