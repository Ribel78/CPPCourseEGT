#include <iostream>
#include <string>
/*Създаване на клас Student със следните параметри:
Име, Фамилия, ЕГН, Град, Дата на раждане
Включете сетери и гетери функции и функция за изписване на съобщение с параметрите от класа.*/
using namespace std;

class Student{
	public:
		/*Инициализиране на променливите от потребителя. Умишлено ползвам параметри с имена различни
		от имената на private променливите в класа за да се види че имената са независими*/
		Student(string first, string last, int id, string town, string date){
			this->nameFirst = first;
			this->nameLast = last;
			this->egn = id;
			this->city = town;
			this->dateBirth = date;
		};
		//Принтиране на съобщение съдържащо променливите на класа
		void printData(){
			cout << nameFirst <<" "<< nameLast <<" is born in " << city <<" on " << dateBirth <<". The EGN is: "<< egn <<endl;
		}
		//setter функции - не връщат стойност
		void setName(string nFirst, string nLast){ //функция с два параметъра
										this->nameFirst   = nFirst;
										this->nameLast 	  = nLast;
		}
		// функции с един параметър
		void setEGN(long long e){       this->egn         = e;}
		void setCity(string city){      this->city        = city;}

		// функция извикваща cin и поставяне на потребителскиия вход в променлива на класа
		void setDateOfBirth(){ cin >> this->dateBirth;}

		//getters функции - връщат стойност
		string getName(int idx){ //извежда променлива на класа базиран на индекс от масив
			string studentNames[2] = {this->nameFirst, this->nameLast}; //поставяме 2 от променливите на класа в масив
			if (idx >=0 && idx<2){
				return studentNames[idx];
			} else {
				cout << "The function accepts 0 or 1 as arguments.\n"; 
				return "Error";
				}
		}
		//извеждане на променливи по обикновения начин
		long long getEGN(){			return this->egn;}
		string getCity (){			return this->city;}
		string getDateOfBirth(){	return this->dateBirth;}

	private:
		string nameFirst;
		string nameLast;
		long long egn;
		string city;
		string dateBirth;	
};

int main(){
	//обект от класа се създава като задължително се въвеждат параметрите в правилния ред
	Student student_01("Georgi","Georgiev",1234567899,"Georgievo","56.23.1912");

	// разиграване на фунциите
	student_01.printData();

	cout << "Please correct the entries" << endl;
	string names[2]; //масив в който да съхраним новите имена
	cout << "First name: "; cin >> names[0];
	cout << "Last name: "; cin >> names[1];
	student_01.setName(names[0],names[1]);
	long long egn; // променлива за дълго число на ЕГН-то
	cout << "EGN: "; cin >> egn;
	student_01.setEGN(egn);
	string city; // променлива за града
	cout << "City: "; cin >> city;
	student_01.setCity(city);
	cout << "Date of birth: ";
	// за тази няма нужда от cin защото е вградена във самата setter функция
	student_01.setDateOfBirth();

	student_01.printData(); // извеждаме направените промени

	//Нека променим първото или последно име според желанието на потребителя
	int userInput = 0;
	string name = "";
	cout << "Change first (0) or last (1) name?:";
	cin >> userInput;
	if (userInput==0){
		cout << "Enter first name";
		cin >> name;
		student_01.setName(name, student_01.getName(1));
		/* тъй като тази функция иска 2 аргумента трябва да поставим съществуващата стойност 
		за параметъра. който няма да променяме*/
	} else if (userInput == 1){
		cout << "Enter last name: ";
		cin >> name;
		student_01.setName(student_01.getName(0), name);
	} else{cout << "The function takes 0 or 1 as arguments.";}

	// извеждаме направените промени
	cout << student_01.getName(0) << " " << student_01.getName(1) << " from " << student_01.getCity() <<" says \"Thanks!\"" << endl;

	return 0;
}
