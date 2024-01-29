#include <iostream>
#include <cmath>
using namespace std;

class Circle2D{
public:
	Circle2D(double pos_x, double pos_y, double r){
		this->position_x = pos_x;
		this->position_y = pos_y;
		this->radius = r;
		this->area = getArea();
		this->perimeter = getPerimeter();		
	}
	// print attributes
	void info(){
		double data[5] = {this->position_x, this->position_y, this->radius, this->area, this->perimeter};
		string s_data[5] = {"Position X: ", "Position: ", "Radius: ", "Area: ", "Perimeter: "};
		for (int i=0; i<5; i++){
			cout << s_data[i] << data[i] << endl;
		}
	}
	//setters
	void setPosition(double pos_x, double pos_y){
		this->position_x = pos_x;
		this->position_y = pos_y;		
	}
	void setRadius(double r){
		this->radius = r;
	}
	void setArea(double area){
		if(this->radius > 0){
			this->area = area;
			this->radius = sqrt(area/pi);
			this->perimeter = getPerimeter();
		} else {cout << "Use setRadius to set radius greater than 0." << endl;}
	}
	void setPerimeter(double p){
		if (this->radius > 0){
			this->perimeter = p;
			this->radius = p/(2*pi);
			this->area = getArea();
		} else {cout << "Use setRadius to set radius greater than 0." << endl;}
	}

	// getters
	double getPosition(int idx){
		if (idx >= 0 && idx < 2){
			double position[2] = {this->position_x, this->position_y};
								return position[idx];
		}	else {cout << "Enter 0 or 1 as function attribute" << endl; return 0;} // what to return if false?
	}
	double getRadius(){ 		return this->radius; 	}
	double getArea(){
		this->area = pi*pow(this->radius,2);
		 						return this->area; 		
	}
	double getPerimeter(){
		this->perimeter = 2*pi*this->radius;
		 						return this->perimeter; }

private:
	const double pi = M_PI;
	double position_x;
	double position_y;
	double radius;
	double area;
	double perimeter;
};

int main(){

	Circle2D circle_01(0.0,0.0,3);
	circle_01.info();
	cout << endl << "Setting Area to 45.34" << endl<< endl;
	circle_01.setArea(45.34);
	circle_01.info();

	cout << endl << "Setting Perimeter to 10.23" << endl<< endl;
	circle_01.setPerimeter(10.23);
	circle_01.info();

	cout << endl << "Setting new position and radius to 24.68" << endl<< endl;
	circle_01.setPosition(0.5,2.37);
	circle_01.setRadius(24.68);
	circle_01.info();
	return 0;
}