#include <iostream>
using namespace std;

// color of pixels
string b = " - ";
string w = " # ";

int main()
{
    // type of triangle to draw (up, down and their flipped vesrions). Range 1-4
    int triangle_type;
    // dimension of the square plane. Greater or equal to 3
    int dim = 0;
    while (dim < 3)
    {
        cout << "Enter triangle base length( >=3 ): ";
        cin >> dim;
    }
    cout << "Enter triangle type (1-4): ";
    cin >> triangle_type;
    for (int y=-dim/2; y< (dim/2)+1; y++){
        for (int x = -dim/2; x < (dim/2)+1; x++) {
            int sum; // sum of coords
            switch (triangle_type)
            {
            case 1:
                sum = x+y; //up-right
                break;
            case 2:
                sum = x-y; //down-right
                break;
            case 3:
                sum = y-x; // up-left
                break;
            case 4:
                sum = -x-y; // down-left; same as -y-x
                break;
            default:
                sum = 0;
                break;
            }
            if (sum < 0){
                cout << b;
            } else {
                cout<< w;
            }           
        }
        cout << endl;
    }
    return 0;
}