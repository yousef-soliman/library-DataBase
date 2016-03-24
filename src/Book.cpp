/*
 * Book.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: yousef_soliman
 */

#include "Book.h"

Book::Book(){
	this->id = 0;
	name[0] = '\0';
	author[0] = '\0';
	this->publishYear = 0;
	this->amount = 0;
	this->numberOfStudent = 0;
}

Book::Book(char *bookName, char *bookAuthor, int publishYear, int amount,string s) {
	fstream f;
	char a[1] ;
	f.open(s.c_str(),ios::in);
	f.read(a,sizeof(a));
	int d = (int) a[0];
	bookUniqueID = d;
	f.close();
	this->id = bookUniqueID++;
	strcpy(name,bookName);
	strcpy(author,bookAuthor);
	this->publishYear = publishYear;
	this->amount = amount;
	this->numberOfStudent = 0;
	f.open(s.c_str(),ios::out);
	a[0] = (char) bookUniqueID;
	f.write(a,sizeof(a));
	f.close();
}

Book::Book(char *bookName, char *bookAuthor, int amount,string s) {
	fstream f;
	char a[1] ;
	f.open(s.c_str(),ios::in);
	f.read(a,sizeof(a));
	int d = (int) a[0];
	bookUniqueID = d;
	f.close();
	this->id = bookUniqueID++;
	strcpy(name,bookName);
	strcpy(author,bookAuthor);
	this->amount = amount;
	this->publishYear = 0;
	this->numberOfStudent = 0;
	f.open(s.c_str(),ios::out);
	a[0] = (char) bookUniqueID;
	f.write(a,sizeof(a));
	f.close();
}

int Book::getId() {
	return id;
}

void Book::setId(int newId) {
	id = newId;
}

int Book::getId()const {
	return id;
}

void Book::setAmount(int newAmount){
	this->amount = newAmount;
}

int Book::getAmount() {
	return amount;
}

int Book::getAmount()const {
	return amount;
}

void Book::setName(char* bookName) {
	strcpy(name,bookName);
}

char* Book::getName() {
	return name;
}

char* Book::getName()const {
	char *nm;
	strcpy(nm,name);
	return nm;
}

void Book::setAuthor(char* bookAuthor) {
	strcpy(author,bookAuthor);
}

char* Book::getAuthor() {
	return author;
}

char* Book::getAuthor()const {
	char *aut;
	strcpy(aut,author);
	return aut;
}

void Book::setPublishYear(int publishYear) {
	this->publishYear = publishYear;
}

int Book::getPublishYear(){
	return publishYear;
}

int Book::getPublishYear()const{
	return publishYear;
}

void Book::setNumberOfStudent(int numberOfStudent) {
	this->numberOfStudent = numberOfStudent;
}

int Book::getNumberOfStudent() {
	return numberOfStudent;
}

int Book::getNumberOfStudent()const {
	return numberOfStudent;
}

void Book::plusNumberOfStudent(){
	numberOfStudent++;
}

void Book::decreaseNumberOfStudent(){
	numberOfStudent--;
}


