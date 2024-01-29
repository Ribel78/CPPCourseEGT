#include <iostream>
using namespace std;

int main (){
    // въвеждане на необходимата информация
    bool isLeap = 0; // флаг за високосна година (0 обикновена, 1 високосна)
    int date, month, day;
    cout << "Enter known\n";
	cout << "DATE/1-31/   MONTH/1-12/   DAY(Mon-Sun)/0-6/\n";
	cout << "separated by spaces:";
    cin >> date;
    cin >> month;
    cin >> day;
    cout << "Is it a leap year? [0-1]:";
    cin >> isLeap;

    int lookupDate = 13; // търсена дата
    int lookupDay = 4; // търсен ден
    cout << "DATE to look up [1-31]:";
    cin >> lookupDate;
    cout << "DAY to look up [0-6]:";
    cin >> lookupDay;   
    // край на въвеждане на необходимата информация

    //помощни масиви за изписване на информация
    string weekDays[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"}; //days of the weeek
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    // масив с дните в един месец, февруари е 28 или 29 в зависимост от въведената стойност на isLeap
    int mDays[] = {31,28+isLeap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // days in a month

    int sum = 0; // променлива за съхраняване на суми
    int dayOffset = 0; //променлива за изместване на деня от седмицата
    // Намери броя на дните преди дадения месец
    for (int i = 0; i < month-1; i++){
        sum += mDays[i];
    }
    // Броя на дните до дадената дата и месец
    sum += date;
    //Изместване между дните, което да използваме за да намерим търсения ден
    //sum%7 е деня на дадената дата в случай че първия ден от годината е Понеделник (идеален случай)
    dayOffset = (7+(day - sum%7))%7; 
    // Тъй като c++ mod на отрицателно число е отрицателно горния израз го прави положително.
    // еквивалентно на
    //dayOffset = abs(day - sum%7); // без използване на функции
    sum = 0; // нулиране на променливата за следващата инструкция
    // Намиране на датите, които имат зададения ден от седмицата lookupDay
    for (int i = 0; i < 12; i++){
        if(lookupDate <= mDays[i]){//проверяваме дали въведената дата е в даден месец (за избягване на търсене на 31 и 30 в месеци с по малко дни)
            if ((sum + lookupDate + dayOffset)%7 == lookupDay){ 
                //magic, добавяме датата към текущата сума от месеци + офсет от идеалния случай и сравняваме модулото с търсения ден
                // ако има съвпадение изписваме месеца, деня и датата
                cout <<  months[i] << " has " << weekDays[lookupDay] << " " << lookupDate << endl; 
            }
        }
        sum+=mDays[i]; //добавяме дните на сравнения месец към общата сума за ползване в следващия цикъл
    }
    return 0;
}