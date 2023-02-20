#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct process_state{
    int pid;
    int bt;
    int at;
    int ct,wt,tat,start;
}ps[10];

void swap(int* m, int* n){
    *m= *m^*n;
    *n= *m^*n;
    *m= *m^*n;
}

int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a<b?a:b;
}

int main(){
    int n=5;
    bool isCompleted[10]={false};
    bool firstProcess=true;
    int current_time=0;
    int completed=0;
    int totalTAT=0,totalWT=0;
    for(int i=0;i<n;i++){
    	printf("\nEnter Process %d AT:",i);
    	scanf("%d",&ps[i].at);
    	ps[i].pid=i;
    }
    for(int i=0;i<n;i++){
    	printf("\nEnter Process %d BT:",i);
    	scanf("%d",&ps[i].bt);
    }
    
    while(completed!=n){
    	int min_idx=-1;
    	int lowest=INT_MAX;
    	for(int i=0;i<n;i++){
    	    if(ps[i].at <= current_time && isCompleted[i]==false){
    	    	if(ps[i].bt<lowest){
    	    	    lowest=ps[i].bt;
    	    	    min_idx=i;
    	    	}
    	    	if(ps[i].bt==lowest){
    	    	    if(ps[i].at<ps[min_idx].at){
    	    	    	lowest=ps[i].bt;
    	    	    	min_idx=i;
    	    	    }
    	    	}
    	    }
    	}
    	if(min_idx==-1){
    	    current_time++;
    	}else{
    	    ps[min_idx].start=current_time;
    	    ps[min_idx].ct=ps[min_idx].start + ps[min_idx].bt;
    	    ps[min_idx].tat=ps[min_idx].ct - ps[min_idx].at;
    	    ps[min_idx].wt=ps[min_idx].tat - ps[min_idx].bt;
    	    
    	    totalTAT+=ps[min_idx].tat;
    	    totalWT+=ps[min_idx].wt;
    	    
    	    completed++;
    	    isCompleted[min_idx]=true;
    	    current_time = ps[min_idx].ct;
    	    firstProcess=false;
    	}
    }
    printf("ID\tBT\tAT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++){
	printf("%d\t%d\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].bt,ps[i].at,ps[i].ct,ps[i].tat,ps[i].wt);
    }
    printf("\n");
    
    int s=(float)totalWT / (float)n;
    int t=(float)totalTAT / (float)n;
    printf("Average waiting time = %d",s);
    printf("\n");
    printf("Average turn around time = %d ",t);
    
    
    return 0; 
}
