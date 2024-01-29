#include <iostream>
//just calling the required objects from std
using std::cout;
using std::endl;
using std::cin;

// function to output the number of digits of int attribute; def after main()
int numDigits (int n);
// variables to store counted digits of the rows
int firstRowDigitsCount = 0;
int secondRowDigitsCount = 0;

int main (){
    cout << "Set end integer number of the first row: ";
    int startingNumber;
    cin >> startingNumber;    
    // arrays for storing the numbers of the integer columns
    int columnLeft[startingNumber-1];
    int columnRight[startingNumber-1];
    // get the count of digits of the first row
    for (int i=1; i <= startingNumber; i++){
            firstRowDigitsCount += numDigits(i);
    }
    // store the numbers of right column in predefined array
    for (int i=0 ; i < startingNumber-1; i++){
        columnRight[i] = (startingNumber+1) + i;
    }
    // get the count of digits of the second row
    // second row starts with statringNumber*2 (right to left)
    // set variable to hold the end number of the second row (right to left) init with starting number
    int row_II_End_Number = startingNumber*2;
    // increment numbers of second row until the digit count exceeds the first row count
    while (secondRowDigitsCount < firstRowDigitsCount)
    {
        secondRowDigitsCount += numDigits(row_II_End_Number);
        row_II_End_Number += 1;
    }
    // the cycle ends but the true end number was incremented afterwards - restore by subtracting 1 
    row_II_End_Number -= 1;
    // store the numbers of left column in predefined array
    for (int i=0 ; i < startingNumber-1; i++){
        columnLeft[i] = (row_II_End_Number+1) + i;
    }

    // console output - draw numbers clockwise while aligned from outside
    // Draw first row
    // if counts match start from 1 else compensate with 0s
    for (int i=(firstRowDigitsCount-secondRowDigitsCount)+1; i <= startingNumber; i++){
        if (i<0){
            cout << 0;
        } else {
            cout << i;
        }
    }
    cout << endl;
    // Draw Left and Right columns
    for (int i=0;i < startingNumber-1; i++){
        //Left array read backwards
        cout << columnLeft[startingNumber-2-i];
        // find out how much spaces to type in
        int spaceCount = 0;
        spaceCount = secondRowDigitsCount - (numDigits(columnLeft[startingNumber-2-i])+numDigits(columnRight[i]));
        for (int i = 0 ; i < spaceCount; i++){
            cout << " ";
        }
        //Right array read forward    
        cout << columnRight[i] << endl;
    }
    // Draw second row
    while (row_II_End_Number>=startingNumber*2)
    {
        cout << row_II_End_Number;
        row_II_End_Number -= 1;
    }
    cout << endl;
    return 0;
}
// function to output the number of digits of integer number
int numDigits (int n){
    if (n > 0){
        int count = 0;
        while (n > 0)
        {
            n /= 10;
            count += 1;
        }
        return count;     
    }else if(n==0){
        return 1;
    } else {return 0;}
}