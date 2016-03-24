/*
 * Student.h
 *
 *  Created on: Mar 5, 2016
 *      Author: yousef_soliman
 */

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Book.h"
class Book;
using namespace std;

class Student {
	private:
		int id;
		char name[40];
		int year;
		int numberOfBook;
	public:
		static int studentUniqueID;
		Student();
		Student( char *studentName,int y,string s);
		void setId(int newId);
		int getId();
		int getId()const;
		void setName(char *studentName);
		char* getName();
		char* getName()const;
		void setNumberOfBook(int NumberOfBook);
		int getNumberOfBook();
		int getNumberOfBook()const;
		void plusNumberOfBook();
		void decreaseNumberOfBook();
		void setYear(int y);
		int getYear();
};

#endif /* SRC_STUDENT_H_ */
