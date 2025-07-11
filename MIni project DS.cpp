#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int ar[100],n=50;
void Insert()
{
    int i,x;
    i=n;
    n++;
    cout<<"Enter the number : ";
    int item;
    cin>>item;
    ar[n]=item;

    cout<<endl;
}
void display()
{
    for(int i=1; i<=n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
void Sort()
{
    int temp;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=1; j<=n-1; j++)
        {
            if(ar[j]>ar[j+1])
            {
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }

        }
    }
    cout<<endl;
}
void Search()
{
    cout<<"input the element to search ";
    int x;
    cin>>x;
    int lb = 1;
    int ub = n;
    int loc = 0;
    while(lb<=ub)
    {
        int mid = (lb+ub)/2;
        if(ar[mid]==x)
        {
            loc=5;
            break;
        }
        else if(ar[mid]>x)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
    }
    if(loc==5)
    {
        cout<<"element found in array";
        cout<<endl;
    }
    else
    {
        cout<<"not found";
        cout<<endl;
    }

}
void delet()
{
    cout<<"input the element to search ";
    int x;
    cin>>x;
    int lb = 1;
    int ub = n;
    int loc = 0;
    while(lb<=ub)
    {
        int mid = (lb+ub)/2;
        if(ar[mid]==x)
        {
            loc=mid;
            break;
        }
        else if(ar[mid]>x)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
    }
    if(loc>0)
    {
        cout<<endl;
        cout<<"element found in array";
        cout<<endl;
        int item=ar[loc];
        for (int j=loc; j<=n-1; j++)
        {
            ar[j]=ar[j+1];
        }
        n=n-1;
        cout<<item<<" DELETED SUCCESFULLY"<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"not found";
        cout<<endl;
    }
}

int main()
{


    int i;
    cout<<"How many numbers ? "<<endl;
    cin>>n;
    ofstream file("DS_file.txt");
    for(i=1; i<=n; i++)
    {
        ar[i]=rand() % 100;
        file<<ar[i]<<" ";

    }
    file.close();
    Sort();
    for(i=1; i<=n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    while(1)
    {
menu:

        cout<<"1 - Insert a number "<<endl;
        cout<<"2 - Delete a number "<<endl;
        cout<<"3 - Search a number "<<endl;
        cout<<"4 - Display the number "<<endl;
        cout<<"5 - exit "<<endl;
        int k1;
        cin>>k1;
        if(k1==1)
        {
            Insert();
            Sort();
            ofstream file("DS_file.txt");
            for(i=1; i<=n; i++)
            {

                file<<ar[i]<<" ";

            }
            file.close();

            goto menu;
        }
        else if(k1==2)
        {
            delet();
            ofstream file("DS_file.txt");
            for(i=1; i<=n; i++)
            {

                file<<ar[i]<<" ";

            }
            file.close();

            goto menu;
        }
        else if(k1==3)
        {
            Search();
            goto menu;
        }
        else if(k1==4)
        {
            display();
            goto menu;
        }
        else
        {
            break;
        }


    }
}
