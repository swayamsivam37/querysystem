#include<stdio.h>
#include<conio.h>
int n,quantam,fc=0, sc=0, mc=0;
int main()
{
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t*** Welcome To The Query System ***\t\t\t\t\t\t\t\t\t");
	informations();
	input();
	return 0;
}
informations()
{
	printf("\nfollow these instruction for Entering time values in program");
	printf("\n\n--->Enter time in 2400 hours format. Like for 10:30 am enter 10030");
	printf("\n\n--->Enter all arrival times in ascending order, i.e. in real time arrival manner");
	printf("\n--->All Time units are in minutes.\n\n");
}

void input(){
	int type,i, t;
	printf("Enter total no of queries: "); 
	scanf("%d", &n);
	if(n==0) 
	{
	 printf("\nNo queries\n"); 
	}
	else
	{
		printf("\nEnter Time Quantam for each Process: ");
		scanf("%d", &quantam);
		printf("\nEnter 1 for faculty and 2 for student\n");
		for(i=0; i<n; i++)
		{
			printf("\nJob Type (1/2): "); 
			scanf("%d", &type);
			if(type==1){
				printf("Query Id: "); scanf("%d", &f[fc].pid);
				printf("Arrival Time: "); scanf("%d", &t);
				if(t<1000 || t>1200){
					printf("\nEnter Correct time");
					input();
				}
				else{f[fc].at= t-1000;}
				printf("Resolving Time: "); scanf("%d", &f[fc].bt);	 f[fc].rbt= f[fc].bt; 
				fc++;
			} else{
				printf("Query Id: "); scanf("%d", &s[sc].pid);
				printf("Arrival Time: "); scanf("%d", &t); 
				if(t<1000 || t>1200){
					printf("\nEnter Correct time\n");
					input();
				}
				else {s[sc].at= t-1000; }
				printf("Resolving Time: "); scanf("%d", &s[sc].bt);	 s[sc].rbt= s[sc].bt;
				sc++;
			}
		}
	}
}
