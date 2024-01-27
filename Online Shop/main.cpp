#include "Drink.h"
#include "NonAlcoholicDrink.h"
#include "AlcoholicDrink.h"
#include "Order.h"
#include "User.h"

//Метод за извеждане на инфо колко напитки са продадени от всеки вид
void soldDrinksQuantity(vector<Drink*> drinks){
    cout << "---------Sold quantity per item ------- \n";
    int diff = 0;
    for (Drink* drink : drinks){
        diff = drink->getInitQuantity()-drink->getQuantity();
        //extra condition - do not list items with 0 sales
        if (diff != 0 ){
            cout << drink->getName() << " - Qty: " << diff << endl;
        }
    }
}

/*Метод който връща (10-те/всички) клиенти с поръчки съдържащи 
напитка от даден тип (с оборот на поръчката им над дадена сума)*/
void listCustomers(int top=0, DrinkType type = COFFEE, float orderTotal=0){
    if (top==0 && orderTotal == 0){
        cout << "All users that have ordered item of type" << endl;
    } else {
        cout << "List (top) users with orders above orderTotal that have purchased item of type" << endl;
    }
}


int main(){

    NonAlcoholicDrink coffee1("Nova Brazilia", 2.50f, 100, COFFEE, 0.250f, 0.5f);
    NonAlcoholicDrink water1("Devin", 1.89f, 200, WATER, 1.50f, 0.5f);
    NonAlcoholicDrink water2("Gorna Banya", 1.65f, 300, WATER, 1.50f, 0.5f);
    AlcoholicDrink whiskey1("Jim Beam", 25.99f, 50, WHISKEY, 30.00f, 1.5f);
    AlcoholicDrink whiskey2("Johnnie Walker", 32.45f, 34, WHISKEY, 35.00, 1.5f);
    NonAlcoholicDrink juice1 ("Cappy", 3.99f, 80, JUICE, 3.00, 0.5);

    vector<Drink*> drinks {
        &coffee1, 
        &water1, 
        &water2, 
        &whiskey1, 
        &whiskey2, 
        &juice1
    };

    whiskey2.print();
    cout << whiskey2.calculatePrice(1) <<endl;
    water1.print();
    cout << water1.calculatePrice(1) <<endl;
    coffee1.print();
    cout << coffee1.calculatePrice(1) <<endl;

    // test Order class
    cout << "Order 1" << endl;
    Order ord1("20.01.2024");
    ord1.addDrink(&water1);
    ord1.addDrink(&water1);
    ord1.addDrink(&whiskey2);
    cout << ord1.getOrderDate() << endl;
    cout << ord1.getOrderTotal() << endl;

    cout << "Order 2" << endl;
    Order ord2("21.01.2024");
    ord2.addDrink(&water1);
    ord2.addDrink(&whiskey1);
    ord2.addDrink(&juice1);
    ord2.addDrink(&juice1);
    cout << ord2.getOrderDate() << endl;
    cout << ord2.getOrderTotal() << endl;

    cout << "Order 3" << endl;
    Order ord3("22.01.2024");
    ord3.addDrink(&whiskey2);
    ord3.addDrink(&whiskey1);
    ord3.addDrink(&coffee1);
    cout << ord3.getOrderDate() << endl;
    cout << ord3.getOrderTotal() << endl;

    ord2.listItems();

    ord3.listItems();

    

    User usr1("Mitko");
    User usr2("Drago");
    User usr3("Pesho");

    usr1.addOrder(&ord1);
    usr2.addOrder(&ord2);
    usr1.addOrder(&ord2);

    vector<User> users;

    cout << "List orders of user: " << usr1.getUserName() << endl << endl;
    usr1.listOrders();

    soldDrinksQuantity(drinks);

    return 0;
}
