#include<stdio.h>

struct patient
{
	int arrival_time;
	int burst_time;
	int id;
	int turn_around_time;
	int waiting_time;
};

int main()
{
	int n,i,j;
	printf("Enter the number of patients:");
	scanf("%d",&n);
	struct patient p[n];

	printf("\nEnter the details: \n");

	for(i=0;i<n;i++)
	{
		printf("Enter the patient id, arrival time and burst time:");
		scanf("%d%d%d",&p[i].id,&p[i].arrival_time,&p[i].burst_time);
	}

	// Sorting on the basic of arrival time of patients

	for(i=n-1;i>0;i--)
	{
		for(j=i-1;j>0;j--)
		{
			if(p[i].arrival_time<p[j].arrival_time)
			{
				struct patient k=p[i];
				p[i]=p[j];
				p[j]=k;
			}
		}
	}
	int total_time = 1;   // Let us assume all the initial process starts from 1
	float t_tat = 0;
	float t_wt = 0;

	printf("\nAfter Scheduling, the order will be:\n");
	for(i=0;i<n;i++)
	{
		total_time = total_time + p[i].burst_time;
		p[i].turn_around_time = total_time - p[i].arrival_time;
		p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
		t_tat = p[i].turn_around_time + t_tat;
		t_wt = p[i].waiting_time + t_wt;
	}

	printf("After Scheduling the order is:\n");
	printf("Pid\tAT\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].turn_around_time,p[i].waiting_time);
	}

	printf("\nAverage Turn Around Time is: %f\n",t_tat/n);
 	printf("Average Waiting time is %f",t_wt/n);

	return 0;
}
