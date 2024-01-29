#include <iostream>
using namespace std;

int main()
{
    // ask for the dimension of the square (odd works best)
    int dim;
    cout << "Enter dimension of the sqare: ";
    cin >> dim;
    // create 2D array to store integers
    int digit[dim][dim];
    //set init direction and position
    //start at center of the square
    int pos_x = dim/2;
    int pos_y = dim/2;
    //in what direction to move
    int mDir = 1;
    // how many steps to move, start with 0
    int steps = 0;
    // continue looping?
    bool loop = 1;
    int counter = 0;

    // fill the 2D array with zeros;
    for (int y=0; y< dim; y++){
        for (int x = 0; x < dim; x++) {
            digit[x][y] = 0;
        }
    }

    // set central element to 1 first and the number of steps
    digit[pos_x][pos_y] = 1;
    steps = 1;
    // increment each step strating with 1
    counter = 1;

    // crawl along a square spiral
    do
    {
        // store integer in arrays
        // move along x in specified direction and steps
        for (int i = 0; i < steps; i++){
            // make sure not referencing to nonexisting array index
            if ((pos_x + mDir)>=0 && (pos_x + mDir) < dim)
            {
                pos_x += mDir;
                counter += 1;
                digit[pos_x][pos_y] = counter;
            } else {
                // if index is out of bounds set loop to false and exict the loop
                loop =0;
                break;
            }
        }
        // next move along y in the same direction (but for y) and steps
        for (int i = 0; i < steps; i++){
            // make sure not referencing to nonexisting array index
            if (((pos_y + mDir)>=0 && (pos_y + mDir) < dim)&& loop)
            {
                pos_y += mDir;
                counter += 1;                   
                digit[pos_x][pos_y] = counter;
            } else {
                // if index is out of bounds set loop to false and exict the loop
                loop = 0;
                break;
        }
        }
        // increase crawling steps by 1   
        steps +=1;
        // flip moving direction
        mDir *= -1;
    } while (loop); // if loop is false stop the cycle
 
    // draw the result numbers;
    for (int y=0; y< dim; y++){
        for (int x = 0; x < dim; x++) {
            // quick and dirty output formatting (adding spaces to smaller digits)
            // can be optimized by calculating the maximum output number and respective number of spaces
            if (digit[x][y] > 999){
                cout << digit[x][y];
            } else if ((digit[x][y] > 99)){
                cout << digit[x][y]<<" ";
            } else if((digit[x][y] > 9)){
                cout << digit[x][y]<<"  ";
            } else{
                cout << digit[x][y]<<"   ";
            }     
        }
        cout << endl;
    }
    return 0;

}