#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

class Vehicle {
private:
    int vehicleID, entryTime, parkingDuration;
    string vehicleType;
    double parkingFee;
    bool isOccupied;
 
public:
    Vehicle() {
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
 
    int getVehicleID() { return vehicleID; }
    void setVehicleID(int vehicleID) { this->vehicleID = vehicleID; }
 
    int getEntryTime() { return entryTime; }
    void setEntryTime(int entryTime) {
        if (entryTime >= 0 && entryTime <= 23) {
            this->entryTime = entryTime;
        }
    }
 
    int getParkingDuration() { return parkingDuration; }
    void setParkingDuration(int parkingDuration) {
        if (parkingDuration >= 1 && parkingDuration <= 23) {
            this->parkingDuration = parkingDuration;
        }
    }
 
    string getVehicleType() { return vehicleType; }
    bool setVehicleType(string type) {
        for (int i = 0; i < (int)type.length(); i++) {
            type[i] = tolower(type[i]);
        }
        if (type == "car") {
            vehicleType = "Car";
        } else if (type == "motorcycle") {
            vehicleType = "Motorcycle";
        } else if (type == "bicycle") {
            vehicleType = "Bicycle";
        } else {
            return false;
        }
        return true;
    }
 
    double getParkingFee() { return parkingFee; }
    void setParkingFee(double parkingFee) { this->parkingFee = parkingFee; }
 
    bool getIsOccupied() { return isOccupied; }
    void setIsOccupied(bool isOccupied) { this->isOccupied = isOccupied; }
 
    void calculateFee() {
        double rate = 0;
        if (vehicleType == "Car") rate = 6.00;
        else if (vehicleType == "Motorcycle") rate = 4.00;
        else if (vehicleType == "Bicycle") rate = 2.00;
 
        bool peakTime = (entryTime >= 6 && entryTime <= 9) || (entryTime >= 15 && entryTime <= 18);
        double firstRate;
        if (peakTime) firstRate = rate * 1.3;
        else firstRate = rate * 0.95;
 
        if (parkingDuration <= 2) {
            parkingFee = firstRate * parkingDuration;
        } else {
            parkingFee = firstRate * 2 + rate * 0.9 * (parkingDuration - 2);
        }
    }
 
    void display() {
        cout << "  Ma xe: " << vehicleID
             << " | Loai: " << vehicleType
             << " | Gio vao: " << entryTime
             << " | Thoi luong: " << parkingDuration
             << " | Phi: $" << fixed << setprecision(2) << parkingFee << endl;
    }
};

class ParkingLot {
private:
    int parkID;
    char size;
    Vehicle vehicle1, vehicle2, vehicle3;
    bool hasVehicle1, hasVehicle2, hasVehicle3;
 
public:
    ParkingLot() {
        parkID = 0;
        size = 'S';
        hasVehicle1 = false;
        hasVehicle2 = false;
        hasVehicle3 = false;
    }
    ParkingLot(int parkID, char size) {
        this->parkID = parkID;
        this->size = size;
        hasVehicle1 = false;
        hasVehicle2 = false;
        hasVehicle3 = false;
    }
 
    int getParkID() { return parkID; }
    char getSize() { return size; }
 
    int getCapacity() {
        if (size == 'L') return 3;
        if (size == 'M') return 2;
        return 1;
    }
 
    int getVehicleCount() {
        int dem = 0;
        if (hasVehicle1) dem++;
        if (hasVehicle2) dem++;
        if (hasVehicle3) dem++;
        return dem;
    }

    bool addVehicle(const Vehicle& v) {
        if (!hasVehicle1) {
            vehicle1 = v;
            hasVehicle1 = true;
            return true;
        }
        if (!hasVehicle2 && getCapacity() >= 2) {
            vehicle2 = v;
            hasVehicle2 = true;
            return true;
        }
        if (!hasVehicle3 && getCapacity() >= 3) {
            vehicle3 = v;
            hasVehicle3 = true;
            return true;
        }
        return false;
    }
 
    bool removeVehicle(int vID) {
        if (hasVehicle1 && vehicle1.getVehicleID() == vID) {
            hasVehicle1 = false;
            return true;
        }
        if (hasVehicle2 && vehicle2.getVehicleID() == vID) {
            hasVehicle2 = false;
            return true;
        }
        if (hasVehicle3 && vehicle3.getVehicleID() == vID) {
            hasVehicle3 = false;
            return true;
        }
        return false;
    }
 
    bool hasVehicleID(int vID) {
        if (hasVehicle1 && vehicle1.getVehicleID() == vID) return true;
        if (hasVehicle2 && vehicle2.getVehicleID() == vID) return true;
        if (hasVehicle3 && vehicle3.getVehicleID() == vID) return true;
        return false;
    }
 
    void displayLotInfo() {
        cout << "Bai " << parkID << " | Kich thuoc: " << size
             << " | So xe: " << getVehicleCount() << "/" << getCapacity() << endl;
        if (hasVehicle1) vehicle1.display();
        if (hasVehicle2) vehicle2.display();
        if (hasVehicle3) vehicle3.display();
        if (getVehicleCount() == 0) cout << "  Bai trong" << endl;
    }
 
    int displayByType(string type) {
        int dem = 0;
        if (hasVehicle1 && vehicle1.getVehicleType() == type) { vehicle1.display(); dem++; }
        if (hasVehicle2 && vehicle2.getVehicleType() == type) { vehicle2.display(); dem++; }
        if (hasVehicle3 && vehicle3.getVehicleType() == type) { vehicle3.display(); dem++; }
        return dem;
    }
 
    int countType(string type) {
        int dem = 0;
        if (hasVehicle1 && vehicle1.getVehicleType() == type) dem++;
        if (hasVehicle2 && vehicle2.getVehicleType() == type) dem++;
        if (hasVehicle3 && vehicle3.getVehicleType() == type) dem++;
        return dem;
    }
 
    double sumFeeType(string type) {
        double tong = 0;
        if (hasVehicle1 && vehicle1.getVehicleType() == type) tong += vehicle1.getParkingFee();
        if (hasVehicle2 && vehicle2.getVehicleType() == type) tong += vehicle2.getParkingFee();
        if (hasVehicle3 && vehicle3.getVehicleType() == type) tong += vehicle3.getParkingFee();
        return tong;
    }
};
 
class SystemInterface {
private:
    ParkingLot parkingLot1, parkingLot2, parkingLot3;
    bool hasLot1, hasLot2, hasLot3;
 
    bool existsLotID(int id) {
        if (hasLot1 && parkingLot1.getParkID() == id) return true;
        if (hasLot2 && parkingLot2.getParkID() == id) return true;
        if (hasLot3 && parkingLot3.getParkID() == id) return true;
        return false;
    }
 
    bool existsVehicleID(int id) {
        if (hasLot1 && parkingLot1.hasVehicleID(id)) return true;
        if (hasLot2 && parkingLot2.hasVehicleID(id)) return true;
        if (hasLot3 && parkingLot3.hasVehicleID(id)) return true;
        return false;
    }
 
    void printAverage(string label, int dem, double tong) {
        cout << "  " << label << ": ";
        if (dem == 0) cout << "khong co xe" << endl;
        else cout << dem << " xe | TB: $" << fixed << setprecision(2) << tong / dem << endl;
    }
 
    void reportType(string loai) {
        int dem = 0;
        double tong = 0;
        if (hasLot1) { dem += parkingLot1.countType(loai); tong += parkingLot1.sumFeeType(loai); }
        if (hasLot2) { dem += parkingLot2.countType(loai); tong += parkingLot2.sumFeeType(loai); }
        if (hasLot3) { dem += parkingLot3.countType(loai); tong += parkingLot3.sumFeeType(loai); }
        printAverage(loai, dem, tong);
    }
 
    void reportLot(ParkingLot& lot) {
        cout << "Bai " << lot.getParkID() << ":" << endl;
        printAverage("Car", lot.countType("Car"), lot.sumFeeType("Car"));
        printAverage("Motorcycle", lot.countType("Motorcycle"), lot.sumFeeType("Motorcycle"));
        printAverage("Bicycle", lot.countType("Bicycle"), lot.sumFeeType("Bicycle"));
    }
 
    void createLot() {
        int id;
        char size;
        cout << "Ma bai: ";
        cin >> id;
        cout << "Kich thuoc (S/M/L): ";
        cin >> size;
        size = toupper(size);
 
        if (size != 'S' && size != 'M' && size != 'L') {
            cout << "Kich thuoc khong hop le!" << endl;
            return;
        }
        if (existsLotID(id)) {
            cout << "Ma bai da ton tai!" << endl;
            return;
        }
        if (!hasLot1) { parkingLot1 = ParkingLot(id, size); hasLot1 = true; }
        else if (!hasLot2) { parkingLot2 = ParkingLot(id, size); hasLot2 = true; }
        else if (!hasLot3) { parkingLot3 = ParkingLot(id, size); hasLot3 = true; }
        else {
            cout << "Da du 3 bai, khong tao them duoc!" << endl;
            return;
        }
        cout << "Da tao bai " << id << endl;
    }
 
    void addVehicle() {
        if (!hasLot1 && !hasLot2 && !hasLot3) {
            cout << "Chua co bai nao, hay tao bai truoc!" << endl;
            return;
        }
        int id, gio, tg;
        string loai;
        cout << "Ma xe: ";
        cin >> id;
        cout << "Loai (Car/Motorcycle/Bicycle): ";
        cin >> loai;
        cout << "Gio vao (0-23): ";
        cin >> gio;
        cout << "Thoi luong (1-23): ";
        cin >> tg;
 
        if (existsVehicleID(id)) {
            cout << "Ma xe da ton tai!" << endl;
            return;
        }
        Vehicle v;
        if (!v.setVehicleType(loai)) {
            cout << "Loai xe khong hop le!" << endl;
            return;
        }
        if (gio < 0 || gio > 23 || tg < 1 || tg > 23) {
            cout << "Gio vao hoac thoi luong khong hop le!" << endl;
            return;
        }
        if (gio + tg > 24) {
            cout << "Xe phai ra trong cung 1 ngay (gio vao + thoi luong <= 24)!" << endl;
            return;
        }
        v.setVehicleID(id);
        v.setEntryTime(gio);
        v.setParkingDuration(tg);
        v.calculateFee();
        v.setIsOccupied(true);
 
        bool ok = false;
        if (hasLot1 && !ok) ok = parkingLot1.addVehicle(v);
        if (hasLot2 && !ok) ok = parkingLot2.addVehicle(v);
        if (hasLot3 && !ok) ok = parkingLot3.addVehicle(v);
 
        if (ok) cout << "Da them xe " << id << " | Phi: $" << fixed << setprecision(2) << v.getParkingFee() << endl;
        else cout << "Cac bai deu day!" << endl;
    }
 
    void deleteLot() {
        int id;
        cout << "Ma bai can xoa: ";
        cin >> id;
        if (hasLot1 && parkingLot1.getParkID() == id) hasLot1 = false;
        else if (hasLot2 && parkingLot2.getParkID() == id) hasLot2 = false;
        else if (hasLot3 && parkingLot3.getParkID() == id) hasLot3 = false;
        else {
            cout << "Khong tim thay bai!" << endl;
            return;
        }
        cout << "Da xoa bai " << id << endl;
    }
 
    void removeVehicle() {
        int id;
        cout << "Ma xe can lay ra: ";
        cin >> id;
        bool ok = false;
        if (hasLot1 && !ok) ok = parkingLot1.removeVehicle(id);
        if (hasLot2 && !ok) ok = parkingLot2.removeVehicle(id);
        if (hasLot3 && !ok) ok = parkingLot3.removeVehicle(id);
        if (ok) cout << "Da lay xe ra" << endl;
        else cout << "Khong tim thay xe!" << endl;
    }
 
    void showAllLots() {
        if (!hasLot1 && !hasLot2 && !hasLot3) {
            cout << "Chua co bai nao!" << endl;
            return;
        }
        if (hasLot1) cout << "Bai " << parkingLot1.getParkID() << " | Kich thuoc: " << parkingLot1.getSize()
                          << " | So xe: " << parkingLot1.getVehicleCount() << "/" << parkingLot1.getCapacity() << endl;
        if (hasLot2) cout << "Bai " << parkingLot2.getParkID() << " | Kich thuoc: " << parkingLot2.getSize()
                          << " | So xe: " << parkingLot2.getVehicleCount() << "/" << parkingLot2.getCapacity() << endl;
        if (hasLot3) cout << "Bai " << parkingLot3.getParkID() << " | Kich thuoc: " << parkingLot3.getSize()
                          << " | So xe: " << parkingLot3.getVehicleCount() << "/" << parkingLot3.getCapacity() << endl;
    }
 
    void showLotVehicles() {
        int id;
        cout << "Ma bai: ";
        cin >> id;
        if (hasLot1 && parkingLot1.getParkID() == id) parkingLot1.displayLotInfo();
        else if (hasLot2 && parkingLot2.getParkID() == id) parkingLot2.displayLotInfo();
        else if (hasLot3 && parkingLot3.getParkID() == id) parkingLot3.displayLotInfo();
        else cout << "Khong tim thay bai!" << endl;
    }
 
    void listByType() {
        string loai;
        cout << "Loai xe: ";
        cin >> loai;
        Vehicle tmp;
        if (!tmp.setVehicleType(loai)) {
            cout << "Loai xe khong hop le!" << endl;
            return;
        }
        loai = tmp.getVehicleType();
        int tong = 0;
        if (hasLot1 && parkingLot1.countType(loai) > 0) {
            cout << "Bai " << parkingLot1.getParkID() << ":" << endl;
            tong += parkingLot1.displayByType(loai);
        }
        if (hasLot2 && parkingLot2.countType(loai) > 0) {
            cout << "Bai " << parkingLot2.getParkID() << ":" << endl;
            tong += parkingLot2.displayByType(loai);
        }
        if (hasLot3 && parkingLot3.countType(loai) > 0) {
            cout << "Bai " << parkingLot3.getParkID() << ":" << endl;
            tong += parkingLot3.displayByType(loai);
        }
        if (tong == 0) cout << "Khong co xe loai " << loai << endl;
    }
 
    void averageReport() {
        cout << "--- Toan he thong ---" << endl;
        reportType("Car");
        reportType("Motorcycle");
        reportType("Bicycle");
        cout << "--- Theo tung bai ---" << endl;
        if (hasLot1) reportLot(parkingLot1);
        if (hasLot2) reportLot(parkingLot2);
        if (hasLot3) reportLot(parkingLot3);
    }
 
public:
    SystemInterface() {
        hasLot1 = false;
        hasLot2 = false;
        hasLot3 = false;
    }
 
    void runMenu() {
        int chon;
        do {
            cout << "\n===== QUAN LY BAI DO XE =====" << endl;
            cout << "1. Tao bai do" << endl;
            cout << "2. Them xe" << endl;
            cout << "3. Xoa bai do" << endl;
            cout << "4. Lay xe ra" << endl;
            cout << "5. Hien thi tat ca bai do" << endl;
            cout << "6. Hien thi xe theo bai" << endl;
            cout << "7. Liet ke xe theo loai" << endl;
            cout << "8. Bao cao phi trung binh" << endl;
            cout << "9. Thoat" << endl;
            cout << "Chon: ";
            if (!(cin >> chon)) {   
                cin.clear();
                cin.ignore(1000, '\n');
                chon = 0;
            }
 
            switch (chon) {
                case 1: createLot(); break;
                case 2: addVehicle(); break;
                case 3: deleteLot(); break;
                case 4: removeVehicle(); break;
                case 5: showAllLots(); break;
                case 6: showLotVehicles(); break;
                case 7: listByType(); break;
                case 8: averageReport(); break;
                case 9: break;
                default: cout << "Chon sai, nhap lai!" << endl;
            }
        } while (chon != 9);
    }
};
 
int main() {
    SystemInterface sys;
    sys.runMenu();
    return 0;
}
 


