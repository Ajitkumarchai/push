#include<iostream>
using namespace std;
void merge(int *arr,int start,int end)
{
    int mid=start+(end-start)/2;
    int len1=mid-start+1;;
    int len2=end-mid;
    int *arr1=new int[len1];
    int *arr2=new int[len2];
    int mainArrayIndex=0;
    for(int i=0;i<len1;i++)
    {
        arr1[i]=arr[mainArrayIndex++];
    }
    for(int j=0;j<len2;j++)
    {
        arr2[j]=arr[mainArrayIndex++];
    }
    int i=0;
    int j=0;
    mainArrayIndex=0;
    while(i<len1 && j<len2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[mainArrayIndex++]=arr1[i++];
        }
        else
        {
            arr[mainArrayIndex++]=arr2[j++];
        }
    }
    while(i<len1)
    {
        arr[mainArrayIndex++]=arr1[i++];
    }
    while(j<len2)
    {
        arr[mainArrayIndex++]=arr2[j++];
    }
    
    
    delete[]arr1;
    delete[]arr2;
    
}
void mergeSort(int *arr,int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int mid=start+(end-start)/2;
    
    mergeSort(arr,start,mid-1);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
}
int main()
{
    int arr[10]={23,45,23,12,56,78,54,4,23,88};
    mergeSort(arr,0,9);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
}