#include<bits/stdc++.h>
 
using namespace std;
int nb,np,b[20],p[20];
void first_fit();
int main()
{
	int i;
	cout<<"Enter the number of blocks:";
	cin>>nb;
	cout<<"Enter the number of processes:";
	cin>>np;
	cout<<"\nEnter the size of the blocks:-\n";
	for(i=0;i<nb;i++)
    {
        cout<<"Block no."<<i+1<<":";
        cin>>b[i];
    }
	cout<<"\nEnter the size of the processes :-\n";
	for(i=0;i<np;i++)
    {
        cout<<"Process no. "<<i+1<<":";
        cin>>p[i];
    }
	first_fit();
	return 0;
}
void first_fit() 
{ 
	int allocation[np]; 
    memset(allocation, -1, sizeof(allocation)); 

	for (int i = 0; i < np; i++) 
	{ 
		for (int j = 0; j < nb; j++) 
		{ 
			if (b[j] >= p[i]) 
			{ 
				allocation[i] = j; 
				b[j] -= p[i]; 
				break; 
			} 
		} 
	} 
	cout<<"\nFirst Fit";
	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < np; i++) 
	{ 
		cout << " " << i+1 << "\t\t"
			<< p[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 

