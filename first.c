#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct query 
{
  
int process_id;
   
int arrival_time;
   
int burst_time;
   
int completion_time;
   
int rburst_time;
 
} fac[100], stu[100], pri[100];

int n, quantam, faculty_count = 0, student_count = 0, priority_count = 0;

int informations () 
{
  system("cls");
  system("color 0f");
printf("\nfollow these instruction for Entering time values in program\n");
  
printf("\n\n--->Enter arrival time in 0 mins to 120 mins\n");
  
printf("\n\n--->Enter all arrival times in ascending order, i.e. in real time arrival manner\n");
  
printf("\n--->All Time units are in minutes.\n\n");
getch();

} 
 
int input () 
{
system("cls");
int type, i, t;
  
printf("Enter total no of queries: ");
  
scanf("%d", &n);
  
if (n == 0)
    
    {
      
printf ("\nNo queries\n");
    
}
  
  else
    
    {
      
printf ("\nEnter Time Quantam for each Process: ");
      
scanf ("%d", &quantam);
      
printf ("\nEnter 1 for faculty and 2 for student\n");
      
for (i = 0; i < n; i++)
	
	{
	  
printf ("\nquery Type (1/2): ");
	  
scanf ("%d", &type);
	  
if (type == 1)
	    
	    {
	      
printf ("Query Id: ");
	      
scanf ("%d", &fac[faculty_count].process_id);
	      
printf ("Arrival Time: ");
	      
scanf ("%d", &t);
	      
if (t < 0 || t > 120)
		
		{
		  
printf ("\nEnter Correct time\n");
		  
input ();
		
}
	      
	      else
		
		{
		  
fac[faculty_count].arrival_time = t ;
		
}
	      
printf ("Resolving Time: ");
	      
scanf ("%d", &fac[faculty_count].burst_time);
	      
fac[faculty_count].rburst_time = fac[faculty_count].burst_time;
	      
faculty_count++;
	    
}
	  
	  else
	    
	    {
	      
printf ("Query Id: ");
	      
scanf ("%d", &stu[student_count].process_id);
	      
printf ("Arrival Time: ");
	      
scanf ("%d", &t);
	      
if (t < 0 || t > 120)
		{
		  
printf ("\nEnter Correct time\n");
		  
input ();
		
}
	      
	      else
		
		{
		  
stu[student_count].arrival_time = t;
		
}
	      
printf ("Resolving Time: ");
	      
scanf ("%d", &stu[student_count].burst_time);
	      
stu[student_count].rburst_time = stu[student_count].burst_time;
	      
student_count++;
	    
}
	
}
    
}
getch();

}


int priority() 
{
int istudent_count = 0, ifaculty_count = 0, min, flag;
  
if (faculty_count!= 0 && student_count!= 0)
    
    {
      
while (istudent_count < student_count && ifaculty_count < faculty_count)
	
	{
	  
if (fac[ifaculty_count].arrival_time == stu[istudent_count].arrival_time)
	    
	    {
	      
pri[priority_count] = fac[ifaculty_count];
	      
priority_count++;
	      
ifaculty_count++;
	      
pri[priority_count] = stu[istudent_count];
	      
priority_count++;
	      
istudent_count++;
	    
}
	  
	  else if (fac[ifaculty_count].arrival_time < stu[istudent_count].arrival_time)
	    
	    {
	      
pri[priority_count] = fac[ifaculty_count];
	      
priority_count++;
	      
ifaculty_count++;
	    
}
	  
	  else if (fac[ifaculty_count].arrival_time > stu[istudent_count].arrival_time)
	    
	    {
	      
pri[priority_count] = stu[istudent_count];
	      
priority_count++;
	      
istudent_count++;
	    
}
	  
	  else;
	
}
      
if (priority_count != (faculty_count + student_count))
	
	{
	  
if (faculty_count != ifaculty_count)
	    {
	      
while (ifaculty_count != faculty_count)
		
		{
		  
pri[priority_count] = fac[ifaculty_count];
		  
priority_count++;
		  
ifaculty_count++;
		
}
	    
}
	  
	  else if (student_count != istudent_count)
	    
	    {
	      
while (istudent_count != student_count)
		
		{
		  
pri[priority_count] = stu[istudent_count];
		  
priority_count++;
		  
istudent_count++;
		
}
	    
}
	
}
    
}
  
  else if (faculty_count == 0)
    
    {
      
while (istudent_count != student_count)
	
	{
	  
pri[priority_count] = stu[istudent_count];
	  
priority_count++;
	  
istudent_count++;
	
}
    
}
  
  else if (student_count == 0)
    
    {
      
while (ifaculty_count != faculty_count)
	
	{
	  
pri[priority_count] = fac[ifaculty_count];
	  
priority_count++;
	  
ifaculty_count++;
	
}
    
}
  
  else
    
    {
      
printf ("\n No valid querys available\n");
    
}

}


 
int roundRobin () 
{
  
int time = pri[0].arrival_time, mark = 0, cc = 0, i, rc;
  
while (time != 120 && cc != priority_count)
    
    {
      
for (i = 0; i <= mark; i++)
	
	{
	  
if (pri[i].rburst_time > quantam)
	    
	    {
	      
time += quantam;
	      
pri[i].rburst_time -= quantam;
	    
      }
	  
	  else if (pri[i].rburst_time <= quantam && pri[i].rburst_time != 0)
	    
	    {
	      
time += pri[i].rburst_time;
	      
pri[i].rburst_time = 0;
	      
pri[i].completion_time = time;
	      
cc++;
	    
}
	  
	  else;
	
}
      
int start = mark + 1;
      
for (rc = start; rc < priority_count; rc++)
	
	{
	  
if (pri[rc].arrival_time <= time)
	    
	    {
	      
mark++;
	    
}
	
}
    
}

}
disp()
{
	int i=0, total=0, sum=0; 
  double avg;
  printf("\nSummary for the Execution\n");
  printf("\nQ.ID  Arival Time  Resolving Time  Completion Time  TurnAroundTime  Waiting Time");
  for(i; i<priority_count; i++)
	{ 
		printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d",pri[i].process_id, (pri[i].arrival_time), pri[i].burst_time, (pri[i].completion_time), (pri[i].completion_time-pri[i].arrival_time), ((pri[i].completion_time-pri[i].arrival_time)- pri[i].burst_time));
		total= pri[i].completion_time;
		sum+= (pri[i].completion_time-pri[i].arrival_time);
	}
	avg = sum/priority_count;
	printf("\n\nTotal time Spent for all queries: %d\n", total);
	printf("\nAverage query time: %lf\n", avg);
	printf("\nProcess Execution Complete");
	return 0;
}
int welcome()
{int i;
for(i=0;i<12;i++)
{
	printf("\n");
}
	system("color 0a");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t Welcome To The Query System \t\t\t\t\t\t\t\t\t");
	getch();
}

int main () 
{
 welcome();
 informations ();
 input ();
 priority();
 roundRobin ();
 disp();

} 
