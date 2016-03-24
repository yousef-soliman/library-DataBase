/*
 * Book.h
 *
 *  Created on: Mar 5, 2016
 *      Author: yousef_soliman
 */

#ifndef SRC_BOOK_H_
#define SRC_BOOK_H_



#include <stdio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include "Student.h"
class Student;
using namespace std;

class Book{
	private:
		int id;// id of book
		static int bookUniqueID;
		char name[40];//name of book
		char author[40]; // author's name
		int publishYear;
		int amount; // number of current books in lib;
		int numberOfStudent;
	public:
		Book();
		Book(char *bookName, char *bookAuthor, int publishYear, int amount,string s);
		Book(char *bookName, char *bookAuthor, int amount,string s);
		int getId();
		void setId(int newId);
		int getId()const;
		void setName(char* bookName);
		char* getName();
		char* getName()const;
		void setAuthor(char* bookAuthor);
		char* getAuthor();
		char* getAuthor()const;
		void setPublishYear(int publishYear);
		int getPublishYear();
		int getPublishYear()const;
		void setAmount(int newAmount);
		int getAmount();
		int getAmount()const;
		void setNumberOfStudent(int numberOfStudent);
		void plusNumberOfStudent();
		void decreaseNumberOfStudent();
		int getNumberOfStudent();
		int getNumberOfStudent()const;
};


#endif /* SRC_BOOK_H_ */

