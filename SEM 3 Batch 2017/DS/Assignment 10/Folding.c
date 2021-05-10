#include<stdio.h>
int Divarr[100]={0};

//LINEAR PROBING WITH DIVISION
int midSquare(int num)
{
    int n,a[2],b[2],i,rem;
    for(i=0;i<2;i++)
    {
        rem=num%10;
        a[i]=rem;
        num=num/10;
    }
    for(i=0;i<2;i++)
    {
        rem=num%10;
        b[i]=rem;
        num=num/10;
    }
    for(i=0;i<2;i++)
    {
        a[i]=a[i]+b[i];
        if(a[i]>9)
            a[i]=a[i]-10;
    }
    int key = a[1]*10 + a[0];
    return key;
}

int linearProbMid(int num)
{
    int key=midSquare(num);
    int num1=Divarr[key];
    int key1=midSquare(num1);
    int i,j;
    while(1)
    {
        if(key1==key)
        {
            if(Divarr[key]==0)
            {
                Divarr[key]=num;
                printf("With FOLDING method the key has been stored at key %d\n",key);
                return 0;
            }
            else{
                while(Divarr[key]!=0)
                    key++;
                Divarr[key]=num;
                printf("With FOLDING method the key has been stored at key %d\n",key);
                return 0;
            }
        }
        else{
            if(Divarr[key]==0)
            {
                Divarr[key]=num;
                printf("With FOLDING method the key has been stored at key %d\n",key);
                return 0;
            }
            else{
                for(i=key;Divarr[i]!=0;)
                    i=(i+1)%100;

                for(j=i-1;j>=key;j--)
                    Divarr[j+1]=Divarr[j];
                Divarr[key]=num;
                printf("With FOLDING method the key has been stored at key %d\n",key);
                return 0;
            }
        }
    }
}
void searchMid(int n)
{
    int key=midSquare(n);
    int i;
    for(i=key;i!=key-1;)
    {
        if(Divarr[i]==n){
            printf("The key is found.\n");
            return 0;
        }
        else if(Divarr[i]==0 || i==key-1){
            printf("The key is not present\n");
            return 0;
        }
        i=(i+1)%100;
    }
}

void display()
{
    int i;
    for(i=0;i<99;i++)
    {
        if(Divarr[i]!=0)
            printf("At key %d:\t %d\n",i,Divarr[i]);
    }
    printf("\n");
    printf("All other keys are empty\n");
}

void main()
{
    int choice,num;
    printf("==============HASHING WITH FOLDING METHOD AND LINEAR PROBING=============\n");
    while(1)
    {
        printf("Choose any one of below:\n1.Insert key\n2.Find Key\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number\n");
                    scanf("%d",&num);
                    linearProbMid(num);
                    break;

            case 2: printf("Enter the number to be search\t:");
                    scanf("%d",&num);
                    searchMid(num);
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default: printf("Wrong choice entered\n");
                    break;
        }
    }
}
