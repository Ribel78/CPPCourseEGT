/*
Drinks                                      Food        

Alcoholic    NoAlcoholic    Tea  Coffee     Biscuits  Chocolates   Nuts  

base class
Drinks
Name. ; Price. ; Quantity
Type (wine, gin, whiskey, water, juice, ice tea, …)
Print()

derived class
NoAlcoholic
Liters ; CityTax
CalculatePrice()  -> Quantity * Price + CityTax

derived class
Alcoholic
alcohol by volume ABV (% alcohol) ; Tax (акциз)
CalculatePrice() > Quantity * (Price  * Tax)

class
Потребител - username, списък/вектор от поръчки

class
Поръчка: - напитки, дата, крайна сума

Метод за извеждане на инфо колко напитки са продадени 
от всеки вид

Метод който връща най-добрият клиент/клиенти 
(с най-скъпа поръчка)

Метод който връща всички клиенти с поръчки съдържащи 
напитка от даден тип

Метод който връща 10-те клиенти с поръчки съдържащи 
напитка от даден тип с оборот на поръчката им над дадена сума
*/