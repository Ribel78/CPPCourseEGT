#include <iostream>
using namespace std;
// color black and white pixels
string b = "-";
string w = "@";

int main()
{
    // ask for the dimension of the square
    int dim;
    cout << "Enter dimension of the sqare: ";
    cin >> dim;
    // create 2D array to store pixel colors
    string pix[dim][dim];
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

    // fill the 2D array with the black pixels;
    for (int y=0; y< dim; y++){
        for (int x = 0; x < dim; x++) {
            pix[x][y] = b;
        }
    }

    // set central pixel to white first and the first number of steps
    pix[pos_x][pos_y] = w;
    steps = 2;

    // crawl along a quare spiral
    do
    {
        // store pixel color
        // move along x in specified direction and steps
        for (int i = 0; i < steps; i++){
            // make sure not referencing to nonexisting array index
            if ((pos_x + mDir)>=0 && (pos_x + mDir) < dim)
            {
                pos_x += mDir;
                pix[pos_x][pos_y] = w;
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
                pix[pos_x][pos_y] = w;
            } else {
                // if index is out of bounds set loop to false and exict the loop
                loop = 0;
                break;
        }
        }
        // increase crawling steps by two (to skip a row(column))     
        steps +=2;
        // flip moving direction
        mDir *= -1;
    } while (loop); // if loop is false stop the cycle
 
    // draw the result pixels;
    for (int y=0; y< dim; y++){
        for (int x = 0; x < dim; x++) {
            cout << pix[x][y];
        }
        cout << endl;
    }
    // cout << "pos_x= " << pos_x << "; pos_y= " << pos_y << endl; // testing last position (indices)
    return 0;

}