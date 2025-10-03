#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <map>
using namespace std;

struct Staff {
    string fullName;
    string jobTitle;
    string contactNumber;
    string emailAddress;
};

struct Vehicle {
    string brand;
    string modelName;
    int manufactureYear;
    double costPrice;
    double salePrice;
};

struct Transaction {
    int staffId;
    int vehicleId;
    string saleDate;
    double finalPrice;
};

vector<Staff> staffList;
vector<Vehicle> vehicleList;
vector<Transaction> transactionList;

void saveToFile() {
    ofstream f("data.txt");
    f << staffList.size() << endl;
    for (auto& s : staffList)
        f << s.fullName << "|" << s.jobTitle << "|" << s.contactNumber << "|" << s.emailAddress << endl;

    f << vehicleList.size() << endl;
    for (auto& v : vehicleList)
        f << v.brand << "|" << v.modelName << "|" << v.manufactureYear << "|" << v.costPrice << "|" << v.salePrice << endl;

    f << transactionList.size() << endl;
    for (auto& t : transactionList)
        f << t.staffId << "|" << t.vehicleId << "|" << t.saleDate << "|" << t.finalPrice << endl;
    f.close();
    cout << "Data saved.\n"; system("pause");
}

void loadFromFile() {
    ifstream f("data.txt");
    if (!f.is_open()) return;
    staffList.clear(); vehicleList.clear(); transactionList.clear();

    int n; string line;
    f >> n; f.ignore();
    for (int i = 0; i < n; i++) {
        Staff s;
        getline(f, s.fullName, '|');
        getline(f, s.jobTitle, '|');
        getline(f, s.contactNumber, '|');
        getline(f, s.emailAddress);
        staffList.push_back(s);
    }

    f >> n; f.ignore();
    for (int i = 0; i < n; i++) {
        Vehicle v;
        getline(f, v.brand, '|');
        getline(f, v.modelName, '|');
        f >> v.manufactureYear; f.ignore();
        f >> v.costPrice; f.ignore();
        f >> v.salePrice; f.ignore();
        vehicleList.push_back(v);
    }

    f >> n; f.ignore();
    for (int i = 0; i < n; i++) {
        Transaction t;
        f >> t.staffId; f.ignore();
        f >> t.vehicleId; f.ignore();
        getline(f, t.saleDate, '|');
        f >> t.finalPrice; f.ignore();
        transactionList.push_back(t);
    }
    f.close();
    cout << "Data loaded.\n"; system("pause");
}

void addStaff() {
    Staff s;
    cout << "Full Name: "; getline(cin, s.fullName);
    cout << "Job Title: "; getline(cin, s.jobTitle);
    cout << "Contact Number: "; getline(cin, s.contactNumber);
    cout << "Email Address: "; getline(cin, s.emailAddress);
    staffList.push_back(s);
}

void deleteStaff() {
    int id; cout << "Staff ID: "; cin >> id; cin.ignore();
    if (id >= 0 && id < staffList.size()) staffList.erase(staffList.begin() + id);
}

void addVehicle() {
    Vehicle v;
    cout << "Brand: "; getline(cin, v.brand);
    cout << "Year: "; cin >> v.manufactureYear; cin.ignore();
    cout << "Model: "; getline(cin, v.modelName);
    cout << "Cost Price: "; cin >> v.costPrice;
    cout << "Sale Price: "; cin >> v.salePrice; cin.ignore();
    vehicleList.push_back(v);
}

void deleteVehicle() {
    int id; cout << "Vehicle ID: "; cin >> id; cin.ignore();
    if (id >= 0 && id < vehicleList.size()) vehicleList.erase(vehicleList.begin() + id);
}

void addTransaction() {
    Transaction t;
    cout << "Staff ID: "; cin >> t.staffId;
    cout << "Vehicle ID: "; cin >> t.vehicleId; cin.ignore();
    cout << "Sale Date (YYYY-MM-DD): "; getline(cin, t.saleDate);
    cout << "Final Price: "; cin >> t.finalPrice; cin.ignore();
    transactionList.push_back(t);
}

void deleteTransaction() {
    int id; cout << "Transaction ID: "; cin >> id; cin.ignore();
    if (id >= 0 && id < transactionList.size()) transactionList.erase(transactionList.begin() + id);
}

void listStaff() {
    for (int i = 0; i < staffList.size(); i++)
        cout << i << ". " << staffList[i].fullName << " | " << staffList[i].jobTitle
        << " | " << staffList[i].contactNumber << " | " << staffList[i].emailAddress << endl;
}

void listVehicles() {
    for (int i = 0; i < vehicleList.size(); i++)
        cout << i << ". " << vehicleList[i].brand << " " << vehicleList[i].modelName
        << " (" << vehicleList[i].manufactureYear << ") Cost:" << vehicleList[i].costPrice
        << " Sale:" << vehicleList[i].salePrice << endl;
}

void listTransactions() {
    for (int i = 0; i < transactionList.size(); i++)
        cout << i << ". StaffID:" << transactionList[i].staffId
        << " VehicleID:" << transactionList[i].vehicleId
        << " Date:" << transactionList[i].saleDate
        << " Price:" << transactionList[i].finalPrice << endl;
}

void transactionsByDate() {
    string d;
    cout << "Enter date (YYYY-MM-DD): "; getline(cin, d);
    for (auto& t : transactionList)
        if (t.saleDate == d)
            cout << "StaffID:" << t.staffId << " VehicleID:" << t.vehicleId
            << " Price:" << t.finalPrice << endl;
}

void transactionsByPeriod() {
    string start, end;
    cout << "Start date (YYYY-MM-DD): "; getline(cin, start);
    cout << "End date (YYYY-MM-DD): "; getline(cin, end);
    for (auto& t : transactionList)
        if (t.saleDate >= start && t.saleDate <= end)
            cout << "StaffID:" << t.staffId << " VehicleID:" << t.vehicleId
            << " Date:" << t.saleDate << " Price:" << t.finalPrice << endl;
}

void transactionsByStaff() {
    int id; cout << "Staff ID: "; cin >> id; cin.ignore();
    for (auto& t : transactionList)
        if (t.staffId == id)
            cout << "VehicleID:" << t.vehicleId << " Date:" << t.saleDate
            << " Price:" << t.finalPrice << endl;
}

int main() {
    vector<string> menuItems = {
        "Add Staff","Delete Staff","Add Vehicle","Delete Vehicle",
        "Add Transaction","Delete Transaction","List Staff","List Vehicles",
        "List Transactions","Transactions by Date","Transactions by Period",
        "Transactions by Staff","Quit"
    };
    int selected = 0;

    while (true) {
        system("cls");
        cout << "Car Sales Management\n\n";
        for (int i = 0; i < menuItems.size(); i++) {
            if (i == selected) cout << ">> "; else cout << "   ";
            cout << menuItems[i] << endl;
        }
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 && selected > 0) selected--;
            else if (key == 80 && selected < menuItems.size() - 1) selected++;
        }
        else if (key == 13) {
            switch (selected) {
            case 0: addStaff(); break;
            case 1: deleteStaff(); break;
            case 2: addVehicle(); break;
            case 3: deleteVehicle(); break;
            case 4: addTransaction(); break;
            case 5: deleteTransaction(); break;
            case 6: listStaff(); system("pause"); break;
            case 7: listVehicles(); system("pause"); break;
            case 8: listTransactions(); system("pause"); break;
            case 9: transactionsByDate(); system("pause"); break;
            case 10: transactionsByPeriod(); system("pause"); break;
            case 11: transactionsByStaff(); system("pause"); break;
            case 12: return 0;
            }
        }
    }
}
