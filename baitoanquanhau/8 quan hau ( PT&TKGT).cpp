#include <conio.h>
#include <stdio.h>
#include <unistd.h>
int n, R[51];

int check(int x, int y){
	int i;
	//kiem tra vi tri thich hop de dat quan hau k
	for(i=1;i<x;i++)
	{
		if((R[i]==y)||(i-R[i]==x-y)||(i-x==y-R[i]))
		{
			y=y+1;
			i=0;
		}
	}
	if(y>n)
		return 0;
	else
	   return y;
}

void Print(){
	int i,f;
		for(i=1;i<=n;i++){
				for(f=1;f<=n;f++)
				{
					if(f==R[i])
					 printf("Q ");
					else
					 printf("_ "); 	
				}
				printf("\n");
			}
}
int main(){
	int i, f;
	printf("enter size of the board : ");
	scanf("%d", &n);
	printf("\n");
	for(i =1; i<=n; i++)
	    R[i] =1;
	i = 1;
	while(1){
		for(;i<=n;i++){
			
			f=check(i,R[i]);
			if(f!=0)
			 R[i]=f;
			 else
			 {
			 	R[i]=1;
			 	R[i-1]=R[i-1]+1;
			 	i=i-2;
			   }
			 
			}
			//print the solution
	        	Print();
				printf("\n[");
				for(i=1;i<n;i++)
				    printf("%d,", R[i]);
				    
				printf("%d]", R[n]);
				getch();
				//xoa ket qua truoc do
				system("CLS");
				//In ra cach dat hau khac
				printf("solution for size %d\n\n", n);
				R[n]= R[n]+1;
				i=n;
		}
	}

