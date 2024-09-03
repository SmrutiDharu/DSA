#include<iostream>
using namespace std;
struct student
{
	int rollno;
	string name;
	float sgpa;	
}; 
void bubblesort(student array[],int n)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4-i;j++)
		{
			if(array[j].rollno>array[j+1].rollno)
			{
				student a=array[j];
				array[j]=array[j+1];
				array[j+1]=a;
			}
		}
	}
}
void insertionsort(student array[],int n)
{
	for(int i=1;i<n;i++)
	{
		student key=array[i];
		int j=i-1;
		while(j>=0 &&array[j].name>key.name)
		{
			array[j+1]=array[j];
			j=j-1;
		}
		array[j+1]=key;
	}
}
int partition(student array[],int low ,int high)
{
	float pivot=array[high].sgpa
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(array[j].sgpa>pivot)
		{
			++i;
			student temp=array[i];
			array[i+1]=array[high];
			array[high]=temp;
			return i+1;
		}
	}
}
//void quicksort(student array[],)
int main()
{
	student s[5];
	cout<<"Enter the details"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Enter the name of the student"<<endl;
		cin>>s[i].name;
		cout<<"Enter the rollno"<<endl;
		cin>>s[i].rollno;
		cout<<"Enter the sgpa"<<endl;
		cin>>s[i].sgpa;
	}

	cout<<"Details of the student are: "<<endl;
	for(int i=0;i<5;i++)
{
	cout<<"No of students is"<<i+1<<":"<<endl;
	cout<<"Name: "<<s[i].name<<endl;
	cout<<"Rollno: "<<s[i].rollno<<endl;
	cout<<"Sgpa: "<<s[i].sgpa<<endl;
}
//bubble sort by roll no
bubblesort(s,5);
cout<<"Sorted rollno are:"<<endl;
for(int j=0;j<5;j++)
{
	cout<<s[j].rollno<<endl;
}
//insertion sort by name
insertionsort(s,5);
cout<<"Sorted names are:"<<endl;

	return 0;
}
