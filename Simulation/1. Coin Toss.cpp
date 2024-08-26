// Lab 1: Write a program to simulate coin toss game using Monte Carlo Simulation Technique

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int head=0,tail=0,itr;
	double r;
	srand(time(NULL));
	printf("Coin toss game using Monte Carlo Simulation\n");
	printf("Enter number of iterations: ");
	scanf("%d",&itr);
	for(int i=1;i<=itr;i++)
	{
		r =(double) rand()/RAND_MAX;
		if(r<=0.5)
		head++;
		else
		tail++;		
	}	
	printf("Head=  %d\n",head);
	printf("Tail = %d\n",tail);
	if(head>tail)
	printf("Head wins by %d",head-tail);
	else
	printf("Tail wins by %d",tail-head);	
}

