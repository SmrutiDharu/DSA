//CIRCULAR QUEUE
#include<iostream>
#define MAXSIZE 3
using namespace std;

int rear=-1,front=-1,cq[MAXSIZE];
//inserting a element
int insert()
{
	int ele;
	if(front==((rear+1)%MAXSIZE))
	{
		cout<<"Circular Queue is full"; //queue full condition
	}
	else
	{
		rear=(rear+1)%MAXSIZE;
		if(front==-1);
		{
			front=0;
		}
		cout<<" \n Enter the element";
		cin>>ele;
		cq[rear]=ele;
		cout<<ele<<"is inserted";
	}
}
//deleting element
int del()
{
	int ele;
	if(front==-1 || front>rear)
	{
		cout<<"Circular queue is empty";//queue empty condition
	}
	
	else
	{
		ele=cq[front];
		front=(front+1)%MAXSIZE;
		cout<<"Element"<<ele<<"is deleted"<<endl;
		if(front==0 && rear==(MAXSIZE-1)||(front>rear))
	{
		front=-1;
		rear=-1;
		
	}
	}
}
//displaying element
int display()
{
	int i;
	if(front==-1 || rear==-1)
	{
		cout<<"cicular queue is empty \n";
	}
	else
	{
	cout<<"Queue contents are:";
		for(int i=front;i<=rear;i++)
	{
		cout<<cq[i]<<endl;
	}
	}
}
int main()
{
	int n;
	while(n!=4)
	{
		cout<<"\n Enter what you want to do \n"<<"1.insert"<<"\t"<<"2.delete"<<"\t"<<"3.display"<<"\t"<<"4.exit"<<"\n"<<"\t";
		cin>>n;
		switch (n) //applying switch case
		{
			case 1:
				insert();
				break;
				
			case 2:
				del();
				break;
				
			case 3:
				display();
				break;
		
		}
	}
	if(n==4)
	{
		cout<<" exit "<<"\n";
	}
	return 0;
}

