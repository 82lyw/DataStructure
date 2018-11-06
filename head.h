#pragma once
typedef int Status;
#include <cassert>
#include <new> 
using namespace std; 
#include <time.h>
const int OK=1; 
const int ERROR=0; 
const int INFEASIBLE=-1; 
//const int OVERFLOW=-2; 
//typedef int Status; //表示操作结果的状态
Status equal(int a,int b) { 
	if(a==b) return OK;
	else return ERROR; 
} 
Status great(int a,int b) { 
	if(a>b) return OK; 
	else return ERROR;
}
Status small(int a,int b) { 
	if(a<b) return OK;
	else return ERROR;
}