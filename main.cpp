/*
 * main.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: yousef_soliman
 */
#include<iostream>
#include <fstream>
#include "Student.h"
#include "Book.h"
#include "Library.h"
using namespace std;
int Book::bookUniqueID = 0;
int Student::studentUniqueID = 0;
int main() {
	int ch;
	string s = "computer science";
	Library lib(s);
	do {
		cout<<"\n\n    BOOk Menut \t \t \t \t \t     STUDENT Menu\n\n"
		    <<"\t \t \t   0 - Exit \t \n"
		    <<"1 - Add new Book\t \t \t \t 7 - Add new Student\n"
		    <<"2 - Display all Books\t \t \t \t 8 - Display All Student\n"
		    <<"3 - Search for a Book\t \t \t \t 9 - Search for a Student\n"
		    <<"4 - Update Book\t \t \t \t        10 - Update Student\n"
		    <<"5 - Delete Book\t \t \t \t        11 - Delete Student\n"
		    <<"6 - Delete All Books\t \t \t \t12 - Delete All Student\n"
			<<"\t \t \t 13 - Borrow Book \t \n"
			<<"\t \t \t 14 - Return Book \t \n"
			<<"\t \t \t 15 - Display all borrowed Books \t \n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			  case 1: {
				  char name[40];
				  char author[40];
				  int year;
				  int amount;
				  cout<<"\n\nPlease Enter Book Data ";
				  cout<<"\nBook Name : ";
				  cin>>name;
				  cout<<"\nBook Author : ";
				  cin>>author;
				  cout<<"\nBook Publish year : ";
				  cin>>year;
				  cout<<"\nBook Amount : ";
				  cin>>amount;
				  cout << endl;
				  string ss = s + "BookID.txt";
				  Book newBook(name,author,year,amount,ss);
				  lib.addBook(newBook);
				  break;
			} case 2: {
				  lib.displayAllBooks();
				  break;
			} case 3: {
				  int number;
				  cout<<"\n\n   Search BOOK Menu\n\n"
					  <<"1 - search by name\n"
					  <<"2 - search by author name\n"
					  <<"3 - search by Publish Year\n\n";
				  cout << "Enter your choice : ";
				  cin >> number;
				  switch(number) {
				  	  case 1:{
				  		  char c[30];
				  		  cout << "Enter name of Book "  << endl;
				  		  cin >> c;
				  		  lib.searchBook(c);
				  		  break;
				  	} case 2:{
				  		  char c[30];
				  		  cout << "Enter author name of Book "  << endl;
				  		  cin >> c;
				  		  lib.searchBook(c,0);
				  		  break;
				  	} case 3:{
				  		  int year;
				  		  cout << "Enter Publish Year of Book "  << endl;
				  		  cin >> year;
				  		  lib.searchBook(year);
				  		  break;
				  	}
				  }

				  break;
			} case 4: {
				  int number;
				  int id;
				  cout << "Enter id for Book you want to UPDATE" << endl;
				  cin >> id;
				  cout<<"\n\n   UPDATE BOoutOK Menu\n\n"
					  <<"1 - Update name\n"
					  <<"2 - Update author name\n"
					  <<"3 - Update Publish Year\n"
					  <<"4 - Update Amount\n\n";
				  cout << "Enter your choice : ";
				  cin >> number;
				  switch(number) {
					  case 1:{
						char c[30];
						cout << "Enter new name of Book " << id << endl;
						cin >> c;
						lib.updateBook(id,c);
						break;
					} case 2:{
						char c[30];
						cout << "Enter new author name of Book " << id << endl;
						cin >> c;
						lib.updateBook(id,c,0);
						break;
					} case 3:{
						int year;
						cout << "Enter new Publish Year of Book " << id << endl;
						cin >> year;
						lib.updateBook(id,year);
						break;
					} case 4:{
						int amount;
						cout << "Enter new Amount of Book " << id << endl;
						cin >> amount;
						lib.updateBook(id,amount,0);
						break;
					}

				}
				break;
			} case 5: {
				int id;
				cout << "Enter id for Book you want to DELETE" << endl;
				cin >> id;
				lib.deleteBook(id);
				break;
			} case 6: {
				lib.deleteAllBooks();
				break;
			} case 7: {
				  char name[40];
				  int year;
				  cout<<"\n\nPlease Enter Book Data ";
				  cout<<"\nStudent Name : ";
				  cin>>name;
				  cout<<"\nStudent year : ";
				  cin>>year;
				  string ss = s + "StudentID.txt";
				  Student newStudent(name,year,ss);
				  lib.addStudent(newStudent);
				  break;
			}case 8: {
				  lib.displayAllStudents();
				  break;
			}case 9: {
				  int number;
				  cout<<"\n\n   Search Student Menu\n\n"
					  <<"1 - search by name\n"
					  <<"2 - search by year\n";
				  cout << "Enter your choice : ";
				  cin >> number;
				  switch(number) {
				  	  case 1:{
				  		  char c[30];
				  		  cout << "Enter  name of Student "  << endl;
				  		  cin >> c;
				  		  lib.searchStudent(c);
				  		  break;
				  	} case 2:{
				  		  int year;
				  		  cout << "Enter Year of Student "  << endl;
				  		  cin >> year;
				  		  lib.searchStudent(year);
				  		  break;
				  	}
				  }
				  break;
			} case 10: {
				  int number;
				  int id;
				  cout << "Enter id for Student you want to UPDATE" << endl;
				  cin >> id;
				  cout<<"\n\n   UPDATE Student Menu\n\n"
					  <<"1 - Update name\n"
					  <<"2 - Update year\n";
				  cout << "Enter your choice : ";
				  cin >> number;
				  switch(number) {
					  case 1:{
						char c[30];
						cout << "Enter new name of Student " << id << endl;
						cin >> c;
						lib.updateStudent(id,c);
						break;
					} case 2:{
						int y;
						cout << "Enter new year of Student " << id << endl;
						cin >> y;
						lib.updateStudent(id,y);
						break;
					}
				}
				break;
			} case 11: {
				int id;
				cout << "Enter id for Book you want to DELETE" << endl;
				cin >> id;
				lib.deleteStudent(id);
				break;
			} case 12: {
				  lib.deleteAllStudents();
				  break;
			} case 13: {
				int bId,sId;
				cout << "Enter id for Book you want to Borrow" << endl;
				cin >> bId;
				cout << "Enter id for student you want to Borrow" << endl;
				cin >> sId;
				lib.borrowBook(bId,sId);
				break;
			} case 14: {
				int bId,sId;
				cout << "Enter id for Book you want to Borrow" << endl;
				cin >> bId;
				cout << "Enter id for student you want to Borrow" << endl;
				cin >> sId;
				lib.returnBook(bId,sId);
				break;
			} case 15: {
				lib.displayAllBorrow();
				break;
			} case 0:
					return 0;
			default: cout<<"wrong choice plz try again !! ";
					break;

		}
	}while(ch != 0);
	return 0;
}




