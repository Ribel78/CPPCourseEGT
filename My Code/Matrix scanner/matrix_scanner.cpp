#include <iostream>
using namespace std;

int main (){
    //Вход: m,n,k
    // Дадена е m x n  матрица от числа (пр 7x10)
    //Дадена е подматрица k x k, k <= min(m,n) (пр. 3x3)
    //Да се намери максималната сума от елементи k x k в m x n (пр. кои 3x3 числа сумарно дават максимален резултат).

    int n=3,m=3,k=3;
    cout << "Enter rows number n: ";
    cin >> n; 
    cout << "Enter columns number m: ";
    cin >> m;
    k = m; // за да влезне в while цикъла
	// въвеждане на числата по ред разделени със space
    while (k >= n || k >= m){
        cout << "Enter square side k: ";
        cin >> k;
    }
    int arr[n][m];
    cout << "Enter array elements: ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Size of array is: "<< sizeof(arr)/sizeof(int) << endl;
	
	//променливи за търсенето на максимална сума в квадрат с размери k
    int cellSum = 0;
    int maxSum = 0;
    int rowRange = n-k;
    int colRange = m-k;
    int coords[2] = {0,0};

    //Изход: maxSum
	//Използваме 4 вгнездени цикъла
	//Първите два местят началото на квадрата
	//Вторите два проверяват сумата в квадрата и сравняват с максималната текуща сума
    for (int x = 0; x < rowRange+1; x++)
    {
        for (int y = 0; y < colRange+1; y++)
        {
            for (int i = x; i < k+x; i++)
            {
                for (int j = y; j < k+y; j++)
                {
                    cellSum+=arr[i][j];
                }  
                        
            }
            if (cellSum > maxSum)
            {
                maxSum = cellSum;
                coords[0] = x;
                coords[1] = y;
            }
            cellSum = 0; 
        }
        
    }

    cout << "Max "<< k << "x" << k <<" sum is: " << maxSum << " " <<" Starting at row: "<< coords[0]+1 << ", column: " << coords[1]+1 << endl;

    return 0;
}