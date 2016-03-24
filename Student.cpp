#include "Student.h"
class Student;
Student::Student(){
	this->id = 0;
	name[0] = '\0';
	this->year = 0;
};
Student::Student(char *studentName, int y,string s){
	fstream f;
	char a[1] ;
	f.open(s.c_str(),ios::in);
	f.read(a,sizeof(a));
	int d = (int) a[0];
	studentUniqueID = d;
	f.close();
	this->id = studentUniqueID++;
	strcpy(name,studentName);
	year = y;
	numberOfBook = 0;
	f.open(s.c_str(),ios::out);
	a[0] = (char) studentUniqueID;
	f.write(a,sizeof(a));
	f.close();
};
void Student::setId(int newId){
	id = newId;
}
int Student::getId() {
	return id;
}

int Student::getId()const {
	return id;
}

void Student::setName(char* studentName) {
	strcpy(name,studentName);
}
char* Student::getName() {
	return name;
}

char* Student::getName()const {
	char *nm;
	strcpy(nm,name);
	return nm;
}
void Student::setNumberOfBook(int numberOfBook) {
	this->numberOfBook = numberOfBook;
}
int Student::getNumberOfBook() {
	return numberOfBook;
}

int Student::getNumberOfBook()const{
	return numberOfBook;
}

void Student::plusNumberOfBook(){
	numberOfBook++;
}

void Student::decreaseNumberOfBook(){
	numberOfBook--;
}

void Student::setYear(int y) {
	year = y;
}
int Student::getYear(){
	return year;
}
