#include <iostream>
#include <cctype> 
using namespace std;
class Vehicle{
 private: 
  int vehicleID, entryTime, parkingDuration;
  string vehicleType;
  double parkingFee;
  bool isOccupied;
 public:
  Vehicle(){
   vehicleID = 0;
      vehicleType = "";
      entryTime = 0;
      parkingDuration = 1;
      parkingFee = 0;
      isOccupied = false;
 } 
  Vehicle(int vehicleID, int entryTime, int parkingDuration, string vehicleType, double parkingFee, bool isOccupied) {
   this->vehicleID = vehicleID;
   this->entryTime = entryTime;
   this->parkingDuration = parkingDuration;
   this->vehicleType = vehicleType;
   this->parkingFee = parkingFee;
   this->isOccupied = isOccupied;
 }
 int getVehicleID() {
  return vehicleID;
 }

 void setVehicleID(int vehicleID) {
  this->vehicleID = vehicleID;
 }
 int getEntryTime() {
   return entryTime;   

 }

 void setEntryTime(int entryTime) {
  if(entryTime >= 0 && entryTime <= 23){
   this->entryTime = entryTime;
  }
 }
 int getParkingDuration() {
  return parkingDuration;
 }
 void setParkingDuration(int parkingDuration) {
  if(parkingDuration >= 1 && parkingDuration <= 23){
   this->parkingDuration = parkingDuration;
  }
 } 
 string getVehicleType() {
  return vehicleType;
 }

 void setVehicleType(string type) {
  for(int i = 0; i < type.length(); i++){
   type[i] = tolower(type[i]);
  }
  if(type == "car"){
   vehicleType = "Car"; 
  } else if(type == "motorcycle"){
   vehicleType = "Motorcycle"; 
  } else if(type == "bicycle"){
   vehicleType = "Bicycle"; 
  } else{
   cout << "Invalid" << endl; 
  } 
 } 
 double getParkingFee() {
  return parkingFee;
 }

 void setParkingFee(double parkingFee) {
  this->parkingFee = parkingFee;
 } 
 bool getIsOccupied() {
  return isOccupied;
 }

 void setIsOccupied(bool isOccupied) {
  this->isOccupied = isOccupied;
 }
 void calculateFee(){
  bool peakTime = (entryTime >= 6 && entryTime <= 9 || entryTime >= 15 && entryTime <= 18);
  if(vehicleType == "Car"){
   if(parkingDuration <= 2){ 
    if(peakTime)
     {
      parkingFee = 6.00 * 1.3 * parkingDuration;
     } else {
      parkingFee = 6.00 * 0.95 * parkingDuration;
     }
   } else{
    if(peakTime) {
     parkingFee = 2 * 6.00 * 1.3 +  6.00 * 0.9 * (parkingDuration - 2); 
    } else {
     parkingFee = 2 * 6.00 * 0.95 +  6.00 * 0.9 * (parkingDuration - 2); 
    } 
   }

  } else if (vehicleType == "Motorcycle"){
   if(parkingDuration <= 2){ 
    if(peakTime)
     {
      parkingFee = 4.00 * 1.3 * parkingDuration;
     } else {
      parkingFee = 4.00 * 0.95 * parkingDuration;
     }
   } else{
    if(peakTime) {
     parkingFee = 2 * 4.00 * 1.3 +  4.00 * 0.9 * (parkingDuration - 2); 
    } else {
     parkingFee = 2 * 4.00 * 0.95 +  4.00 * 0.9 * (parkingDuration - 2); 
    } 
   }
  } else if(vehicleType == "Bicycle"){
   if(parkingDuration <= 2){ 
    if(peakTime)
     {
      parkingFee = 2.00 * 1.3 * parkingDuration;
     } else {
      parkingFee = 2.00 * 0.95 * parkingDuration;
     }} else{if(peakTime) {
     parkingFee = 2 * 2.00 * 1.3 +  2.00 * 0.9 * (parkingDuration - 2); 
    } else {
     parkingFee = 2 * 2.00 * 0.95 +  2.00 * 0.9 * (parkingDuration - 2); 
    } 
   }
  }
 }
 void display(){
  cout << "Vehicle ID: " << vehicleID << endl;
  cout << "Vehicle Type: " << vehicleType << endl;
  cout << "Entry Time: " << entryTime << endl;
  cout << "Parking Duration: " << parkingDuration << endl;
  cout << "Parking Fee: " << parkingFee << endl;
 }
};  
 class ParkingLot {
  private:
   int parkID;
   char size;
   Vehicle vehicle1, vehicle2, vehicle3;
   bool hasVehicle1, hasVehicle2, hasVehicle3;
  public:
   ParkingLot(){
    parkID = 0;
    size = 'S';
    hasVehicle1 = false;
    hasVehicle2 = false;
    hasVehicle3 = false;
    }
   ParkingLot(int parkID, char size){
    this -> parkID = parkID;
    this -> size = size;
    hasVehicle1 = false;
    hasVehicle2 = false;
    hasVehicle3 = false;
   }
   bool addVehicle(const Vehicle& v){ 
    if(!hasVehicle1){ 
     vehicle1 = v; 
     hasVehicle1 = true;
     return true; 
    }
    if(!hasVehicle2 && getCapacity() >= 2){
     vehicle2 = v; 
     hasVehicle2 = true;
     return true; 
    }
    if(!hasVehicle3 && getCapacity() >= 3){ 
     vehicle3 = v; 
     hasVehicle3 = true;
     return true; 
    } 
    return false; 
   }
   int getCapacity() {
    if(size == 'L') {return 3;} 
    if(size == 'M') {return 2;}
    return 1; 
   }
		bool removeVehicle(int ID){
				if(hasVehicle1 && vehicle1.getVehicleID() == ID){
					if(hasVehicle2){
						vehicle1 = vehicle2;
						if(hasVehicle3){
							vehicle2 = vehicle3;
							hasVehicle3 = false;
						} else{
							hasVehicle2 = false;
						}
					} else{
						hasVehicle1 = false;
					}
				}
				return true;
				if(hasVehicle2 && vehicle2.getVehicleID() == ID){
					if(hasVehicle3){
						vehicle2 = vehicle3;
						hasVehicle3 = false;
					} else {
						hasVehicle2 = false;
					}
				}
				return false;
			}	
   
 };
