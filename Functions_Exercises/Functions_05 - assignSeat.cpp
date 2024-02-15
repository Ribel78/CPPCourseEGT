#include<iostream>
#include<cmath>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;

//airplane capacity 10 seats
//menu and messages to assign seats.

int seats[10] = {0};
void assignSeat(int seat[],int size){
    int seatNum = 0;
    bool isAllReserved = false;

    while (!isAllReserved){
    cout << "Reserve seat: \n";
    cin >> seatNum;
        for (int i=0; i < size; i++  ){
            isAllReserved = seats[i];
            if (seats[seatNum] == 0){
                seats[seatNum] = 1;
                cout << "Seat No: " << seatNum << " was reserved." << endl;
                break;
            }else if (!isAllReserved){
                cout << "Seat No: " << seatNum << " is taken.\nPlease choose available number:" << endl;
                for (int i = 0; i < size; i++){
                    if (seat[i] == 0){
                        cout << i << " "; 
                    }
                }
                cout<<endl;
                break;
            }else{
                isAllReserved = true;
                cout << "All seats resrerved" << endl;
                break;
            }
            
        }
    }
}

int main(){
    assignSeat(seats,10);
    return 0;
}