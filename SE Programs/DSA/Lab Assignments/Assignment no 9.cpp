#include <iostream>

using namespace std;

class heap
{
    public:
    
    void heapify(int array[], int n, int i) 
    {
        int temp;
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        if (l < n && array[l] > array[largest])
        {
            largest = l;
        }
        
        if (r < n && array[r] > array[largest])
        {
            largest = r;
        }
        
        if (largest != i)
        {
            temp = array[i];
            array[i] = array[largest];
            array[largest] = temp;
            heapify(array, n, largest);
        }
    }
    
    void heapSort(int array[], int n)
    {
        int temp;
        
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(array, n, i);
        }
        
        for (int i = n - 1; i >= 0; i--)
        {
            temp = array[0];
            array[0] = array[i];
            array[i] = temp;
            heapify(array, i, 0);
        }
    }
};

int main()
{
    int array[100], n, i;
    int ch;
    
    do{
        cout<<"\n\nEnter number of elements in array: ";
        cin>>n;
        
        for(i=0; i<n; i++)
        {
            cout<<"Enter element "<<i+1<<": ";
            cin>>array[i];
        }
        
        cout<<"Given array is: "<<endl;
        
        for(i=0; i<n; i++)
        {
            cout<<array[i]<<" ";
        }
        
        cout<<endl;
        
        heap hs;
        hs.heapSort(array, n);
        
        cout<<"\nSorted array is: "<<endl;
        for(i=0; i<n; i++)
        {
            cout<<array[i]<<" ";
        }
        
        cout<<"\n\nDo you want to continue? (0/1) : ";
        cin>>ch;
        
    }while(ch!=0);
    
    
    cout<<"\n\nDone!!"<<endl;

    return 0;
}
