/*
 * Library.h
 *
 *  Created on: Mar 5, 2016
 *      Author: yousef_soliman
 */

#ifndef SRC_LIBRARY_H_
#define SRC_LIBRARY_H_

#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Book.h"
#include <fstream>

class Book;
class Student;
struct data{
	int bookId;
	int studentId;
};
class Library{
	private:
		string libName;
		string bookFiles;
		string studentFiles;
		fstream studentFile;
		fstream bookFile;
		data d;

	public:
		Library(string nameLibrary);
		~Library();
		void addBook(Book newBook);
		void addStudent(Student newStudent);
		void borrowBook(int bookId, int studentId);
		void returnBook(int bookId, int studentId);
		void displayAllBooks();
		void displayAllStudents();
		void searchBook(char *text);
		void searchBook(char *text,bool flag);
		void searchBook(int year);
		Student searchStudent(int id,bool flag);
		bool findBook(int id);
		void searchStudent(char *text);
		void searchStudent(int year);
		bool findStudent(int id);
		void updateBook(int id,char *name);
		void updateBook(int id,char *author,bool flag);
		void updateBook(int id,int year);
		void updateBook(int id,int amount,bool flag);
		void updateStudentBorrow(int id);
		void updateStudentReturn(int id);
		void updateBookReturn(int id);
		void updateStudent(int id,char *name);
		void updateStudent(int id,int y);
		void deleteBook(int id);
		void deleteStudent(int id);
		void deleteAllBooks();
		void deleteAllStudents();
		void headBorrow();
		void displayAllBorrow();
		static void headBook();
		static void headStudent();


};


#endif /* SRC_LIBRARY_H_ */
