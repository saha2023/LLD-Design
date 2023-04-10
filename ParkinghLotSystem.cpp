#include <bits/stdc++.h>
void file_i_o() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Vehicle {
protected:
    int parkedTime;
public:
    virtual std::string getType(){
        return "I am the parent class Vehical";
    }
    virtual int calculateCost(int hours){
        return 0;
    }
    void setParkedTime(int currTime){
        parkedTime = currTime;
    }
    int getParkedTime(){
        return parkedTime;
    }
};

class Car : public Vehicle {
public:
    // Car() { 
    //     // payment = new CarPayment(); 
    // }
    int calculateCost(int hours) override{
        return hours*2;
    }
    std::string getType() override {
        return "Car";
    }  
};

class Bike : public Vehicle {
public:
    // Bike() { 
    //     payment = new BikePayment(); 
    // }
    int calculateCost(int hours) override{
        return hours*1;
    }
    std::string getType() override{ 
        return "Bike"; 
    }
};

class HandicappedVehicle : public Vehicle {
public:
    // HandicappedVehicle() { 
    //     payment = new HandicappedPayment(); 
    // }
    int calculateCost(int hours) override{
        return 0;
    }
    std::string getType() override{ 
        return "Handicapped"; 
    }
};

class ParkingLot {
private:
    std::vector<std::vector<std::vector<Vehicle*>>> spots;
    int floors;
    int rows;
    int spotsPerRows;
public:
    ParkingLot(int floors, int rows, int spotsPerRows){
        this->floors = floors;
        this->rows = rows;
        this->spotsPerRows = spotsPerRows;
        spots.resize(floors);
        for(int i=0;i<floors;i++){
            spots[i].resize(rows);
            for(int j=0;j<rows;j++){
                spots[i][j].resize(spotsPerRows);
            }
        }
    }

    bool park(Vehicle* v, int floor, int row, int spot){
        if(spots[floor][row][spot] == NULL){
            spots[floor][row][spot] = v;
            std::cout<<v->getType()<< "parked successfully at floor"<< floor << ", row " << row << ", spot " << spot << "." << std::endl;
            return true;
        }
        else{
            std::cout << "Spot already occupied." << std::endl;
            return false;
        }
    }

    int calculateHoursParked(Vehicle* v, int currTime){
        return currTime - v->getParkedTime();
    }
    bool leave(Vehicle* v, int currTime){
        for (int i = 0; i < floors; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < spotsPerRows; k++) {
                    if (spots[i][j][k] == v){
                        int hours = calculateHoursParked(spots[i][j][k], currTime);
                        int cost = spots[i][j][k]->calculateCost(hours);
                        spots[i][j][k] = nullptr;
                        std::cout << v->getType() << " left successfully. Total cost: " << cost << std::endl;
                        return true;
                    }
                }
            }
        }
        std::cout << v->getType() << " not found." << std::endl;
        return false;
    }

    int availableSpots(int floor) {
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < spotsPerRows; j++) {
                if (spots[floor][i][j] == nullptr) {
                    count++;
                }
            }
        }
        return count;
    }

    int handicappedSpots(int floor) {
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < spotsPerRows; j++) {
                if (dynamic_cast<HandicappedVehicle*>(spots[floor][i][j]) != nullptr) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    file_i_o();
    ParkingLot lot(3, 10, 20);
    Car car1, car2;
    Bike bike1, bike2;
    HandicappedVehicle hv1;

    car1.setParkedTime(1); //car1 parked at 1hr
    lot.park(&car1, 0, 0, 0);

    car2.setParkedTime(1); //car2 parked at 1hr
    lot.park(&car2, 0, 0, 1);

    bike1.setParkedTime(2); //bike1 parked at 2 hr
    lot.park(&bike1, 0, 0, 2);
    
    hv1.setParkedTime(10); // handicaped vehical1 parked at 10hr;
    lot.park(&hv1, 2, 9, 19);

    std::cout << "Available spots on floor 0: " << lot.availableSpots(0) << std::endl;
    std::cout << "Handicapped spots on floor 2: " << lot.handicappedSpots(2) << std::endl;

    lot.leave(&car1, 7); //car1 left at 7hr
    lot.leave(&bike2, 7); //bike2 left at 7hr

    std::cout << "Available spots on floor 0: " << lot.availableSpots(0) << std::endl;

    return 0;
}

