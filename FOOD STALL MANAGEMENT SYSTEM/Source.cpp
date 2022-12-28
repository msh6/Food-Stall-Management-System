/* FOOD STALL MANAGEMENT SYSTEM APPLICATION */

// All the header files used...

#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<cstdio>
#include<stdio.h>

// username, unique id, food truck name
char u_name[20];
char uid[20];
char foodtype[20];

class Admin {
private:
	int totalitem, price[10];
	char name[20];
	char fmenu[10][10], type[20];
	char passwd[20], rpasswd[20];
protected:
	char mobile[15], mail[50], stallid[20];
public:
	char restid[];
	/* this fuction authenticates the login of both admin and food stall portal users*/

	int login() {
		if ((strcmp(::u_name, restid)) == 0) {
			std::cout << "\nEnter the Login Password : ";
			int len = 0;
			len = strlen(passwd);
			char inputpasswd[20];
			for (int i = 0; i < len; i++) {
				inputpasswd[i] = std::cin.get();
				std::cout << '#';
			}
			//inputpasswd[i] = NULL;
			if ((strcmp(u_name, restid) == 0) && (strcmp(passwd, inputpasswd) == 0)) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	// This function helps is password recovery with help of unique keyword provided by admin

	int recover() {
		std::cout << "\nThe Input Username is " << u_name;
		char key[20];
		if (strcmp(u_name, restid) == 0) {
			std::cout << "\nEnter the Unique Keyword (Provided by admin ) : ";
			std::cin >> key;
			if ((strcmp(key, rpasswd) == 0)) {
				std::cout << "\nYou are a Valid user.";
				std::cout << "\nYour Password is :" << passwd;
				std::cout << "\nPlease Exit to Login again.";
				return 1;
			}else
				return 0;
		}
		else
			return 0;
	}
	void getdata() {
		std::cout << "\nEnter the Food stall Name : ";
		std::cin.getline(name, sizeof(name));
		std::cout << "\nEnter the Food Stall ID : ";
		std::cin >> restid;
		std::cout << "\nEnter the Mobile Number : ";
		std::cin.getline(mobile, sizeof(mobile));
		std::cout << "\nEnter the E-mail ID : ";
		std::cin.getline(mail, sizeof(mail));
		std::cout << "\nEnter the Stall Unique ID : ";
		std::cin.getline(stallid, sizeof(stallid));
		std::cout << "\nFood Stall Food Options Possible are \n1.South-Indian\n2.Continental\n3.Chinese\n4.Thailand\n5.Multiple";
		int foodtype;
		std::cout << "\nEnter the Food stall Food Options Type(Unique Number)";
		std::cin >> foodtype;
		if (foodtype == 1)
			strcpy(type, "South-Indian");
		else if (foodtype == 2)
			strcpy(type, "Continental");
		else if (foodtype == 3)
			strcpy(type, "Chinese");
		else if (foodtype == 4)
			strcpy(type, "Thailand");
		else
			strcpy(type, "Multiple");
		std::cout << "\nEnter the Total Food menu Items : ";
		std::cin >> totalitem;
		for (int i = 0; i < totalitem; i++) {
			std::cout << "\nEnter the Food Items " << i + 1 << "Name : ";
			std::cin >> fmenu[i];
			std::cout << "Enter the price of Food " << i + 1 << "INR : ";
			std::cin >> price[i];
		}
		std::cout << "\nCreate your Login Password : ";
		std::cin >> passwd;
		std::cout << "\nEnter the Unique keyword to Recover Password : ";
		std::cin >> rpasswd;
		std::cout << "\n\nPlease note your Username is ID, i.e. " << restid << "\n";
	}
	void display() {
		std::cout << "\nFood Stall Name						: " << name;
		std::cout << "\nFood Stall ID						: " << restid;
		std::cout << "\nFood Stall Mobile No.				: " << mobile;
		std::cout << "\nFood Stall E-Mail ID				: " << mail;
		std::cout << "\nFood Stall Food Menu Total Items	: " << totalitem;
		for (int i = 0; i < totalitem; i++) {
			std::cout << "\n\tFood Item : " << i + 1 << " : " << fmenu[i] << " :: Price ;" << price[i];
			if (totalitem == 0)
				std::cout << " ( None Food Items Specified... )";
		}
	}
	int profile(){
		if (strcmp(u_name, restid) == 0) {
			std::cout << "\nFood Stall Food Items Type		: " << type;
			std::cout << "\nFood Stall Total Mobile			: " << totalitem;
			std::cout << "\nFood Stall Food Items Type		: " << type;
			return 1;
		}
		else
			return 0;
	}
	int knowmenu() {
		if ((strcmp(u_name, restid) == 0)) {
			std::cout << "\nFood Stall Food Items Type	 :- " << type;
			std::cout << "\nFood Stall Total fmenus	     :- " << totalitem;
			for (int i = 0; i < totalitem; i++) {
				std::cout << "\nFood Item : " << i + 1 << " : " << fmenu[i] << " :: Price : " << price[i];
			}
			return 1;
		}
		else
			return 0;
	}
	void addmenu() {
		if ((strcmp(u_name, restid) == 0)) {
			std::cout << "\nEnter the New Food Item : ";
			std::cin >> fmenu[totalitem];
			std::cout << "\nEnter the Price of new Food Item : ";
			std::cin >> price[totalitem];

			totalitem++;
			std::cout << "\n\nNew fmenu Added Successfully...";
		}
	}
	// this function helps a food stall portal user to delete a menu 
	void delmenu(){
		knowmenu();
		int de = 0;
		if ((strcmp(u_name, restid) == 0)) {
			if (totalitem == 0 || totalitem < 0) {
				totalitem = 0;
				std::cout << "\nNone fmenus Exist...";
				std::cin.get();
				exit(0);
			}
			std::cout << "\nEnter the fmenu No. to be Deleted : ";
			std::cin >> de;
			if (de == totalitem) {
				totalitem--;
				strcpy(fmenu[totalitem], " ");
				price[totalitem] = NULL;
			}
			else if (totalitem == 1) {
				totalitem = 0;
				strcpy(fmenu[totalitem], " ");
				price[0] = NULL;
			}
			else {
				de--;
				strcpy(fmenu[totalitem], " ");
				for (int p = de; p < totalitem; p++) {
					strcpy(fmenu[p], fmenu[p + 1]);
					price[p] = price[p + 1];
				}
				totalitem--;
			}
			std::cout << "\n Records Updated Successfully...";
		}
	}
	// this function helps a food stall portal user to modify the personal profile
	void modreprofile() {
		if ((strcmp(u_name, restid) == 0)) {
			std::cout << "\nThe Profile Details are : ";
			std::cout << "\n 1. Food Stall E-mail	: " << mail;
			std::cout << "\n 2. Food Stall Mobile	: " << mobile;
			std::cout << "\n 3. Food Stall Type 	: " << type;
			int g = -1;
			std::cout << "\n\nEnter the Detail No. to be Modified : ";
			std::cin >> g;
			if (g == 1) {
				char newmail[50];
				std::cout << "\nEnter the new Mail Address : ";
				std::cin.getline(newmail, sizeof(newmail));
				strcpy(mail, newmail);
				std::cout << "\nRecords Updated Successfully...";
			}
			else if (g == 2) {
				char newmobile[15];
				std::cout << "\nEnter the New Mobile No.: ";
				std::cin.getline(newmobile, sizeof(newmobile));
				strcpy(mobile, newmobile);
				std::cout << "\nRecords Updated Successfully...";
			}
			else if (g == 3) {
				char newtype[20];
				std::cout << "\nFood Stall Food Options Possible are \n1.South - Indian\n2.Continental\n3.Chinese\n4.Thailand\n5.Multiple";
				int foodtype;
				std::cout << "\nEnter the Food stall Food Options Type(Unique Number)";
				std::cin >> foodtype;
				if (foodtype == 1)
					strcpy(newtype, "South-Indian");
				else if (foodtype == 2)
					strcpy(newtype, "Continental");
				else if (foodtype == 3)
					strcpy(newtype, "Chinese");
				else if (foodtype == 4)
					strcpy(newtype, "Thailand");
				else
					strcpy(newtype, "Multiple");
				strcpy(type, newtype);
				std::cout << "\nRecords Updated Successfully...";
			}
			else
				std::cout << "\nInvalid Input Provided...";
		}
	}
	int knowmenutocustomer() {
		if ((strcmp(uid, stallid) == 0)) {
			std::cout << "\nFood Stall Name						:: " << name;
			std::cout << "\nFood Stall Unique ID				:: " << stallid;
			std::cout << "\nFood Stall Food Menu Type			:: " << type;
			std::cout << "\nFood Stall Total Food Menu Items	:: " << totalitem;
			for (int i = 0; i < totalitem; i++) {
				std::cout << "\n\tFood Item : " << i + 1 << " : " << fmenu[i] << " :: Price : " << price[i];
			}
			return 1;
		}
		else
			return 0;
	}
	void displaytocustomer() {
		std::cout << "\nFood Stall Name						:: " << name;
		std::cout << "\nFood Stall Unique ID				:: " << stallid;
		std::cout << "\nFood Stall Total Food Menu Items	:: " << totalitem;
		for (int i = 0; i < totalitem; i++) {
			std::cout << "\n\tFood Items : " << i + 1 << " : " << fmenu[i] << " :: Price : " << price[i];
		}
		if (totalitem == 0)
			std::cout << " ( None Food Items Specified... )";
	}
	int searchbyfoodtype() {
		if ((strcmp(foodtype, type) == 0)) {
			std::cout << "\nFood Stall Name						:: " << name;
			std::cout << "\nFood Stall Unique ID				:: " << stallid;
			std::cout << "\nFood Stall Total Food Menu Items	:: " << totalitem;
			for (int i = 0; i < totalitem; i++) {
				std::cout << "\n\tFood Items : " << i + 1 << " : " << fmenu[i] << " :: Price : " << price[i];
			}
			return 1;
		}
		else
			return 0;
	}
	void invalid_input() {
		std::cout << "\nInvalid Input Provided !!! ";
		std::cin.get();
		system("cls");
		std::cout << "\n\n\n\t\t\tThank You";
	}
}a, f;

class MainMenu {
public:
	void admin_call() {
		char adminuser[20], adminpass[20];
		std::cout << "\n\t\t\tWelcome To Admin Login Portal ";
		std::cout << "\n\nEnter the username : ";
		std::cin >> adminuser;
		std::cout << "\nEnter the Password : ";
		for (int i = 0; i < 8; i++) {
			adminpass[i] = std::cin.get();
			std::cout << "*";
		}
		std::cin.get();
		adminpass[20] = NULL;
		if ((strcmp(adminuser, "admin") == 0) && (strcmp(adminpass, "password") == 0)) {
			system("cls");
		}
		else {
			std::cout << "\n\n\n\t\t\tInvalid Access to Portal ";
			std::cout << "\n\n\t\t\t\tThank You !!!";
			std::cin.get();
			exit(0);
		}
		int temp;
		char opera = 'y';
		do {
			std::cout << "\n\t\t\t\tWelcome To Admin Panel";
			std::cout << "\n\nPress 1 to Add Single Food Stall with record ";
			std::cout << "\nPress 2 to Add Multiple Food Stalls with record ";
			std::cout << "\nPress 3 to View All Food Stalls with records";
			std::cout << "\nPress 4 to Delete a Food Stall with record ";
			std::cout << "\n\tEnter Your Choice : ";
			std::cin >> temp;
			system("cls");
			if (temp == 1) { // for inserting  a single Food Stall record
				std::cout << "\nEnter the Details :- ";
				std::fstream fs;
				fs.open("info.txt", std::ios::in | std::ios::out | std::ios::ate);
				a.getdata();
				fs.write((char*)&a, sizeof(Admin));
				fs.close();
				std::cout << "\nRecord Entered Successfully...";
			}//for inserting the single Food Stall records
			if (temp == 2) { // for inserting multiple food stall records
				int m = 0;
				std::fstream fs;
				fs.open("info.txt", std::ios::in | std::ios::out | std::ios::ate);
				do {
					std::cout << "\nEnter the Details :- ";
					a.getdata();
					fs.write((char*)&a, sizeof(Admin));
					std::cout << "Press 0 if you want to Enter More Records : ";
					std::cin >> m;
				} while (m == 0);
				fs.close();
				std::cout << "\nRecord Entered Successfully... ";
			}
			if (temp == 3) { //  to view all food stall records
				std::fstream fs;
				fs.open("info.txt", std::ios::in);
				fs.seekg(0);
				while (!fs.eof()) {
					fs.read((char*)&a, sizeof(Admin));
					a.display();
				}
				fs.close();
			}// to view all food  stall records
			if (temp == 4) { // for deleting a food stall record
				char tmpfaid[15];
				int de = 0; int result = -1;
				std::cout << "\nEnter the Food Stall ID. :- ";
				std::cin >> tmpfaid;
				std::fstream fs;
				fs.open("info.txt", std::ios::in);
				std::fstream fs1;
				fs1.open("fanewinfo.txt", std::ios::out | std::ios::ate);
				while (!fs.eof()) {
					fs.read((char*)&a, sizeof(Admin));
					result = strcmp(tmpfaid, a.restid);
					if (result == 0) {
						de = 1;
					}
					else
						fs1.write((char*)&a, sizeof(Admin));
				}
				if (de == 1) {
					std::cout << "\nRecord Deleted Successfully....";
				}
				else {
					std::cout << "\nRecord not found....";
				}
				fs.close();
				fs1.close();
				remove("info.txt");
				rename("fanewinfo.txt", "rainfo.txt");
			}// for deleting a food stall record

			std::cin.get();
			std::cout << "\n\nPress y ; For More Operations otherwise n : ";
			std::cin >> opera;
			if (opera != 'y') {
				std::cin.get();
				system("cls");
				std::cout << "\n\n\n\n\n\t\t\t\t\tThank You !!!";
				std::cin.get();
			}// closing of thank you
		} while (opera == 'Y' || opera == 'y');
	}
	void r_call() {
		system("cls");
		char un[20];
		int val, s = 0;
		std::cout << "\n\t\t\tWelcome to Food Stall Login Page";
		std::cout << "\n\nEnter the UserName : ";
		std::cin >> u_name;
		std::fstream fs;
		fs.open("info.txt", std::ios::in | std::ios::binary);
		fs.seekg(0);
		while (!fs.eof()) {
			val = -1;
			fs.read((char*)&f, sizeof(Admin));
			val = f.login();
			if (val == 1) {
				s = 1;
				break;
			}
		}
		fs.close();
		if (s == 1) {
			system("cls");
		}// if first login is valid
		if (s != 1) { // if first login is invalid
			system("cls");
			int ho = 0;
			std::cout << "\n\n\t\tYour Login Credentials are In-Correct";
			std::cout << "\nThe UserName is Your ID\restid.";
			std::cout << "\nThe Password is Case-Sensitive.";
			std::cout << "\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
			std::cout << "\nEnter the choice : ";
			std::cin >> ho;
			if (ho == 1) {	// Recover Password
				std::cout << "\nEnter the Username :- ";
				std::cin >> u_name;
				std::fstream fs;
				fs.open("info.txt", std::ios::in | std::ios::binary);
				fs.seekg(0);
				int re, su = -1;
				while (!fs.eof()) {
					re = -1;
					fs.read((char*)&f, sizeof(Admin));
					re = f.recover();
					if (re == 1) {
						su = 1;
						break;
					}
				}
				fs.close();
				if (su == 1) {
					std::cin.get();
					system("cls");
					std::cout << "\n\n\n\n\t\tThank You !!! ";
					std::cin.get();
					exit(0);
				}
				else {
					std::cout << "\nYou are an Invalid User.";
					std::cin.get();
					exit(0);
				}
			}// recover password
			if (ho == 2) {	// attempt login again
				std::cout << "\n\nEnter the Username: ";
				std::cin >> u_name;
				std::fstream fs;
				fs.open("info.txt", std::ios::in | std::ios::binary);
				fs.seekg(0);
				int suc = -1, value;		// value for storing login() returned value for successful login
				while (!fs.eof()) {
					value = -1;
					fs.read((char*)&f, sizeof(Admin));
					value = f.login();
					if (value == 1) {
						suc = 1;
						break;
					}
				}
				fs.close();
				if (suc == 1) {
					system("cls");
				}
				else {
					std::cin.get();
					std::cout << "\nYou are an Invalid User...";
					std::cout << "\nThank You !!!";
					std::cin.get();
					exit(0);
					exit(0);
				}
			}
			if (ho != 1 && ho != 2) {
				std::cout << "\n\nInvalid Input Provided. ";
				std::cout << "\n\n\t\t\tThank You !!!";
				std::cin.get();
				exit(0);
			}
		}
		// Beginning of Food Stall Main Menu
		char con = 'y';
		do {
			system("cls");
			std::cout << "\n\n\t\t\tWelcome to Food Stall Panel ";
			std::cout << "\n\n\t\t\t\t\t\t		Your UserId is : " << u_name;
			std::cout << "\n\nPress 1 to View Your Profile.";
			std::cout << "\nPress 2 to Know Your Menu (with Price)";
			std::cout << "\nPress 3 to Add a Food Item.";
			std::cout << "\nPress 4 to Delete a Food Item.";
			std::cout << "\nPress 5 to Modify Your Profile.";
			int choice;
			std::cout << "\n\nEnter Your Choice : ";
			std::cin >> choice;
			if (choice == 1) {	//View a Food Stall record
				std::fstream fs;
				fs.open("info.txt", std::ios::in);
				fs.seekg(0);
				int x;
				while (!fs.eof()) {
					x = 0;
					fs.read((char*)&f, sizeof(Admin));
					x = f.profile();
					if (x == 1) {
						break;
					}
					fs.close();
				}
			}	// View a food stall record
			if (choice == 2) {
				std::fstream fs;
				fs.open("info.txt", std::ios::in);
				fs.seekg(0);
				int y;
				while (!fs.eof()) {
					y = 0;
					fs.read((char*)&f, sizeof(Admin));
					int y = f.knowmenu();
					if (y == 1) {
						break;
					}
				}
				fs.close();
			}
			if (choice == 3) {	///Add an Item in food stall menu
				std::fstream fs;
				std::fstream fs1;
				fs.open("info.txt", std::ios::in | std::ios::binary);
				fs1.open("tempinfo.txt", std::ios::out | std::ios::ate);
				fs.seekg(0);
				while (!fs.eof()) {
					fs.read((char*)&f, sizeof(Admin));
					f.addmenu();
					fs1.write((char*)&f, sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("info.txt");
				rename("tempinfo.txt", "info.txt");
			}	// Add item in food stall menu
			if (choice == 4) {	// Delete an item in food stall menu
				std::fstream fs;
				fs.open("info.txt", std::ios::in | std::ios::binary);
				std::fstream fs1;
				fs1.open("delinfo.txt", std::ios::out | std::ios::ate);
				fs.seekg(0);
				while (!fs.eof()) {
					fs.read((char*)&f, sizeof(Admin));
					f.delmenu();
					fs1.write((char*)&f, sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("info.txt");
				rename("delinfo.txt", "info.txt");
			}
			if (choice == 5) {	//Modify the food stall profile
				std::fstream fs;
				std::fstream fs1;
				std::cout << "Enter the unique Id of the Food Stall : ";
				std::cin >> u_name;
				fs.open("info.txt", std::ios::in | std::ios::binary);
				fs.seekg(0);
				fs1.open("modinfo.txt", std::ios::out | std::ios::ate);
				while (!fs.eof()) {
					fs.read((char*)&f, sizeof(Admin));
					f.modreprofile();
					fs1.write((char*)&f, sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("info.txt");
				rename("modinfo.txt", "info.txt");
			}	//Modify the Food Stall Profile
			if (choice < 1 || choice>5) {
				std::cout << "\nInvalid Input Provided !!! ";
				std::cout << "\n\n\t\t\t\tEnter to Continue";
				std::cin.get();
				std::cout << "\n\nPress y to continue ; otherwise n : ";
				std::cin >> con;
			}
			if (con != 'y' && con != 'Y') {
				system("cls");
				std::cout << "\n\n\n\n\n\t\t\t\tThank You !!! ";
				std::cin.get();
				exit(0);
			}
		} while (con != 'y' || con != 'Y');
	}
	void customer_call() {
		char moreop;
		system("cls");
		do {
			system("cls");
			std::cout << "\n\n\t\t\tWelcome to Customer Panel ";
			std::cout << "\n\n\t\t\t\t\t\t		Guest Login";
			std::cout << "\n\nPress 1 to View All Food Stall/Food Stall Details.";
			std::cout << "\nPress 2 to Search a Stall by Stall unique ID.";
			std::cout << "\nPress 3 to Search a Food Stall (Depending on Taste)";
			int  inchoice;
			std::cout << "\n\nEnter Your Choice : ";
			std::cin >> inchoice;
			if (inchoice == 1) {	//to view all food stall records
				std::fstream fs;
				fs.open("info.txt", std::ios::in);
				fs.seekg(0);
				while (!fs.eof()) {
					fs.read((char*)&a, sizeof(Admin));
					a.displaytocustomer();
				}
				fs.close();
			}// to view all food stall records
			if (inchoice == 2) {// to search a food stall by unique stall id
				int result = -1;
				std::cout << "\nEnter the Food Stall Unique ID. :- ";
				std::cin >> uid;
				std::fstream fs;
				fs.open("info.txt", std::ios::in);
				while (!fs.eof()) {
					fs.read((char*)&a, sizeof(Admin));
					result = a.knowmenutocustomer();
					if (result == 1) {
						break;
					}
				}
				if (result != 1) {
					std::cout << "\nRecord not found....";
				}
			}// to search a Food Stall by stallid
			if (inchoice == 3) {	// to search a food stall by food type
				int result;
				std::cout << "\nFood Stall Food Options Possibilities are \n1. South-Indian\n2. Continental\n3. Chinese\n4. Thailand\n5. Multiple";
				std::cout << "\nEnter the Food Stall Food Options Type(Unique Number)";
				std::cin >> result;
				if (result == 1)
					strcpy(foodtype, "South Indian");
				else if (result == 2)
					strcpy(foodtype, "Continental");
				else if (result == 3)
					strcpy(foodtype, "Chinese");
				else if (result == 4)
					strcpy(foodtype, "Thailand");
				else
					strcpy(foodtype, "Multiple");
				std::fstream fs;
				fs.open("info.txt", std::ios::in);
				while (!fs.eof()) {
					fs.read((char*)&a, sizeof(Admin));
					result = a.searchbyfoodtype();
					if (result == 1) {
						break;
					}
				}
				if (result != 1) {
					std::cout << "\nNo Such Food Stall found...";
				}
			}//to a search a food stall by food type
			if (inchoice < 1 || inchoice>3) {
				std::cout << "\nInvalid Input Provided...";
				std::cout << "\n\n\t\t\tEnter to Continue ";
				std::cin.get();
				std::cout << "\n\nPress y, otherwise n to perform More Operations : ";
				std::cin >> moreop;
				if (moreop != 'Y' && moreop != 'y') {
					system("cls");
					std::cout << "\n\n\n\t\t\tThank You !!!";
					std::cin.get();
					exit(0);
				}
			}
		} while (moreop == 'Y' || moreop == 'y');
		std::cin.get();
	}
	void invalid_user_input() {
		a.invalid_input();
	}
}m;

//main fuction

void main() {
	int ch, tmp;
	system("cls");
	std::cout << "\n\n\n\t\t\tWelcome to Food Court Management System ";
	std::cout << "\n\n\n\t\t\t\tEnter to Continue ";
	std::cin.get();
	system("cls");
	std::cout << "\n\n\n\t\t\tPress 1 for Admin Portal ";
	std::cout << "\n\t\t\tPress 2 for Food Stall Portal ";
	std::cout << "\n\t\t\tPress 3 for Customer Portal ";
	std::cout << "\n\n\t\t\tEnter Your Choice : ";
	std::cin >> ch;
	system("cls");
	if (ch == 1) {
		m.admin_call();
	}// closing of admin login

	if (ch == 2) {// beginning of food stall view portal
		m.r_call();
	}// End of Food stall view portal
	
	if (ch == 3) { // begin of Customer view
		m.customer_call();
	}// closing of Customer panel ch = 3

	if (ch < 1 || ch>3) {
		m.invalid_user_input();
	}
}