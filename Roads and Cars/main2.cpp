#include <iostream>
#include <sstream> //Header providing string stream classes
#include <vector>
#include <memory> //This header is part of the dynamic memory management library - unique_ptr
#include <exception> //provides several classes and functions related to exception handling in C++ programs
// #include <unistd.h>

struct RoadSegment {
    double location_marker; // distance from the beginning of the Road in meters
    int minSpeed; // minimum speed allowed in km/h
    int maxSpeed; // maximum speed allowed in km/h

    int holes; // how many holes in a sector
    //int hiddenDanger;  //...
};

class BaseRoad { // abstract base class
public:
    virtual int minSpeedAt(double meters) const = 0;
    virtual int maxSpeedAt(double meters) const = 0;
    virtual int totalLength() const = 0;
    virtual int getHoles(double meters) const = 0;
    //virtual double getDamagePercent(double meters, int speed) const = 0;

    virtual ~BaseRoad() {};
};

class SimpleRoad : public BaseRoad { //does not have any overidden base class functions?
private:
    int minSpeed;
    int maxSpeed;
    double lenMeters;
};

class CombineRoad : public BaseRoad { //combining other class roads? 
public:

private:
    std::vector<BaseRoad *> segments;
};

class Road : public BaseRoad{
public:
    Road(std::string name, double meters, int numSegments):roadName(name) { // class constructor
        double segLen = meters / numSegments; //segments have equal length in this case
        for (int i = 0; i < numSegments; ++i) { //filling segments container
            int rand_speed = 50 + rand() % 50; //random speed is between 50 and 100
            //create a RoadSegment on each iteration
            segments.push_back(RoadSegment {
                    i * segLen, //set the location_marker value
                    rand_speed - 10, //set the minimum speed
                    rand_speed, //set the maximum speed
                    rand()%10 //random amount of holes 0-10
            });
        }
        segments.push_back(RoadSegment { meters, 0, 0 }); //add last segment with location marker = length of Road and 0 speeds
    }
    int minSpeedAt(double meters) const{ //find segment and get its min speed
        return getSegmentAt(meters)->minSpeed; // what happens if NULL RoadSegment->minSpeed?
    }
    int maxSpeedAt(double meters) const { // find segment and get its max speed
        return getSegmentAt(meters)->maxSpeed; //what happens if NULL RoadSegment->maxSpeed?
    }
    int totalLength() const {
        return segments[segments.size()-1].location_marker; //last segment location marker has the total lenght value
    }
    int getHoles(double meters) const { //get number of holes in current segment
        return getSegmentAt(meters)->holes;
    }
    std::string roadName; //name of the road
private:
    const RoadSegment *getSegmentAt(double meters) const { //pointer function? find on which RoadSegment at specified length
        if (meters >= totalLength()) { //checks greater or equal than Road length
            return NULL; //return NULL RoadSegment and exit function
        }
        for (int i = 0; i < segments.size(); ++i) {
            if (segments[i].location_marker <= meters &&
                    segments[i+1].location_marker > meters) { //why i+1? - previous condition prevents causing error
                return &segments[i];
            }
        }
        return NULL; //why return NULL again? If segments.size() = 0 - minSpeedAt and maxSpeedAt will throw an error.
    }

    std::vector<RoadSegment> segments; //container to store RoadSegments
};

class Car {
public:
    Car(std::string name) : road(NULL), name(name), meters(0), damage(0) {}
    void assignRoad(Road *road) { //assign a Road to travel on via pointer to the object
        if (this->road != NULL) { //if already on a Road 
            throw "can't override road"; //doe the function continue with the code after this?
        }
        this->road = road; //assigns the input pointer to Road to (ptr)road member if car is on a NULL Road
    }
    bool hasFinished() { //has the Car reached the end of the road
        return road == NULL;
    }
    void setDamage(int holes){ //car has a 1/holes chance to avoid a damage
            if((double)(rand() % holes)/holes >= 0.5){
                this->damage += 15;
            }            
    }
    double getDamage(){
        return this->damage;
    }
    void tick(double sec) { //"move" the car forward by given time in seconds
        if (hasFinished()) {
            return; // ends tick if hasFinished() is true
        }

        int maxSpeed = road->maxSpeedAt(meters); //check the max speed at given distance (current car distance from beginning)
        int roadLen = road->totalLength(); //variable to store Road lenght 
        double dist = maxSpeed * (sec / 3600) * 1000; //distance passed for the tick seconds on the current segment with max speed
        //speed*time = distance - (km/h)*(sec/3600- sec to h conversion)*(1000 - km to m conversion) - result is in meters
        std::cout << "Car " << this->name << " covered " << dist << "m in " << sec <<  "s at: " << maxSpeed << "km/h. ";
        meters += dist; //
        if (meters >= roadLen) {
            std::cout <<" Reached end of Road " << road->roadName<< std::endl;
            road = NULL;
            meters = 0;
        } else {
            setDamage(road->getHoles(meters));
            std::cout << "Loc: " << meters <<" m ("<< (meters/roadLen)*100 << "\%) on Road " << road->roadName 
            << " current segment has " << road->getHoles(meters) << " holes. Damage: " << getDamage()
            << std::endl;
        }
    }
private:
    std::string name; //car's name
    Road *road; //on which Road the car travels
    double meters; //traveled distance in meters
    double damage;
};

class Controller { //adds cars and roads
public:
    Controller(int interval) : timerInterval(interval) {}

    void addCar() {
        // Car *p = new Car(unique_name(carId));
        // cars.emplace_back(p);
        std::unique_ptr<Car> p = std::make_unique<Car>(unique_name(carId));
        cars.push_back(std::move(p));
    }
    void addRoad() {//hardcoded arguments for road length and num segments (0 segmentss will cause an error)
        roads.emplace_back(std::make_unique<Road>(unique_name(roadID), 4000, 5)); 
    }

    void loop() {
        for (auto &car : cars) {
            if (car->hasFinished()) {
                car->assignRoad(roads[rand() % roads.size()].get()); // does not assign different road?!
            }
        }
        for (auto &car : cars) {
            car->tick(timerInterval);
        }
    }
private:
    std::string unique_name(int &id) { //based on unitialized car/road/ID variable
        std::ostringstream os;
        os << "#" << id++;
        return os.str();
    }

    int carId = 1;
    int roadID = 100;
    double timerInterval;
    std::vector<std::unique_ptr<Car>> cars;
    std::vector<std::unique_ptr<Road>> roads;
};

int main() {
    Controller ctl(15);
    ctl.addCar();
    ctl.addCar();
    ctl.addRoad();
    ctl.addRoad();
    ctl.addRoad();
    ctl.addRoad();
    ctl.addRoad();
    ctl.addRoad();

    for (int i = 0; i < 15; ++i) {
        ctl.loop();
        //sleep(1);
    }

    return 0;
}
