Car Sales Management System

A console-based application written in C++ for managing a car dealership’s daily operations.
It helps keep track of employees, vehicles, and sales transactions, and calculates profits over time.

 Main Features

Add, delete, and view staff members

Add, delete, and view vehicles

Record and remove sales transactions

View transactions by:

specific date

date range

staff member

Find the most sold car within a period

Identify the most profitable employee

Calculate total profit for a given time period

Save and load all data automatically from a local text file

 How It Works

When you start the program, it automatically loads data from a file named data.txt.
You navigate the menu using the arrow keys (↑ ↓) and select options with Enter.

Every entity (staff, car, or sale) has its own ID, which is simply its position in the list.
For example:

Staff ID = index in the staff list

Vehicle ID = index in the vehicle list

All data is saved back to the file when you choose “Save Data” or “Quit” from the menu.

 Data Storage

All information is stored in a simple text file (data.txt) in a readable format.
Each section (staff, vehicles, transactions) starts with a number showing how many records there are.
Fields are separated by | for easy parsing.

Example Workflow

Add a staff member (e.g., name, job title, phone, email).

Add a vehicle (e.g., brand, model, year, cost, sale price).

Record a transaction — connect a staff ID and vehicle ID, enter sale date and price.

View lists or filter transactions by date, period, or employee.

Save your data and exit — everything will be restored next time you open the program.

 Reports and Analytics

Transactions by Date → shows all sales for one specific day

Transactions by Period → shows all sales in a chosen time range

Transactions by Staff → shows all cars sold by a specific employee

Best Car by Period → finds which car model sold the most

Best Staff by Period → finds who brought the most profit

Total Profit by Period → sums up all profits within the selected time frame

 Technical Notes

Works on Windows (uses <conio.h> for keyboard input)

Built with standard C++17

Data is plain text — no database needed

All user interaction is through the console

 Files
File	Description
main.cpp	Main program source code
data.txt	Automatically created file where all records are saved
README.md	Project description
 Summary

This project demonstrates:

File handling in C++

Dynamic data management using vectors

Menu navigation with keyboard input

Basic analytics (counting, summing, comparing)

It’s a great example of how to build a complete CRUD (Create, Read, Update, Delete) console application with simple data analysis in C++.
