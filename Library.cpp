/*
 * Library.cpp
 *
 *  Created on: Mar 5, 2016
 *      Author: yousef_soliman
 */
#include "Library.h"
/*constructor
 * parameter :
 * name for libaray;
 */
Library::Library(string nameLibrary) {
	libName = nameLibrary;
	bookFiles = libName+"Book.txt";
	studentFiles = libName+"Student.txt";
}
Library::~Library() {
	studentFile.close();
	bookFile.close();
}

void Library::addBook(Book newBook) {
	bookFile.open(bookFiles.c_str(),ios::app);
	bookFile.write((char*)& newBook,sizeof(newBook));
	bookFile.close();
	bookFile.clear();
}

void Library::addStudent(Student newStudent) {
	studentFile.open(studentFiles.c_str(),ios::app);
	studentFile.write((char*)&newStudent,sizeof(newStudent));
	studentFile.close();
	studentFile.clear();

}
void Library::displayAllBooks(){
	Book selectedBook;
	headBook();
	bookFile.open(bookFiles.c_str(),ios::in);
	while(bookFile.read((char*)&selectedBook,sizeof(selectedBook)))
	{
		if(selectedBook.getId() == -1) continue;
		cout<<selectedBook.getId()<<setw(20)<<(selectedBook.getName())<<setw(18)<<selectedBook.getAuthor()<<setw(20)
			    <<selectedBook.getPublishYear() << setw(10) << selectedBook.getAmount() << setw(15) << selectedBook.getNumberOfStudent()<< endl;
	}
	bookFile.close();
}
void Library::displayAllStudents(){
	Student selected;
	headStudent();
	studentFile.open(studentFiles.c_str(),ios::in);
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == -1) continue;
		cout<<selected.getId()<<setw(20)<<(selected.getName())<<setw(18)
			    <<selected.getYear() << setw(15) << selected.getNumberOfBook() << endl;
	}
	studentFile.close();
}
void Library::headBook(){
	cout<<"\n\n\t\t\t\tBook LIST\n\n";
	    cout<<"============================================================================================\n";
	    cout<<"ID"<<setw(15)<<"Name"<<setw(22)<<"Author"
		    <<setw(22)<<"Publish year"  <<setw(10)<<"amount" << setw(16)<<"   number of Students\n";
	    cout<<"============================================================================================\n";
}

void Library::headStudent(){
	cout<<"\n\n\t\t\t\tStudent LIST\n\n";
	    cout<<"============================================================================================\n";
	    cout<<"ID"<<setw(15)<<"Name"<<setw(22)<<"Year"  <<setw(15) << "		number of Books"<< endl;
	    cout<<"============================================================================================\n";
}
void Library::searchBook(char *text){
	Book selectedBook;
	bookFile.open(bookFiles.c_str(),ios::in);
	headBook();
	while(bookFile.read((char*)&selectedBook,sizeof(selectedBook)))
	{
		if(selectedBook.getId() == -1) continue;
		if(strcmp(selectedBook.getName(),text) == 0){
			cout<<selectedBook.getId()<<setw(20)<<(selectedBook.getName())<<setw(18)<<selectedBook.getAuthor()<<setw(20)
				<<selectedBook.getPublishYear() << setw(10) << selectedBook.getAmount() << setw(15) << selectedBook.getNumberOfStudent()<< endl;
		}
	}
	bookFile.close();
}

void Library::searchBook(char *text,bool flag){
	Book selectedBook;
	bookFile.open(bookFiles.c_str(),ios::in);
	headBook();
	while(bookFile.read((char*)&selectedBook,sizeof(selectedBook)))
	{
		if(selectedBook.getId() == -1) continue;
		if(strcmp(selectedBook.getAuthor(),text) == 0){
			cout<<selectedBook.getId()<<setw(20)<<(selectedBook.getName())<<setw(18)<<selectedBook.getAuthor()<<setw(20)
				<<selectedBook.getPublishYear() << setw(10) << selectedBook.getAmount() << setw(15) << selectedBook.getNumberOfStudent()<< endl;
		}
	}
	bookFile.close();
}

void Library::searchBook(int year){
	Book selectedBook;
	bookFile.open(bookFiles.c_str(),ios::in);
	headBook();
	while(bookFile.read((char*)&selectedBook,sizeof(selectedBook)))
	{
		if(selectedBook.getId() == -1) continue;
		if(selectedBook.getPublishYear() == year ){
			cout<<selectedBook.getId()<<setw(20)<<(selectedBook.getName())<<setw(18)<<selectedBook.getAuthor()<<setw(20)
				<<selectedBook.getPublishYear() << setw(10) << selectedBook.getAmount() << setw(15) << selectedBook.getNumberOfStudent()<< endl;
		}
	}
	bookFile.close();
}
bool Library::findBook(int id){
	Book selectedBook;
	bookFile.open(bookFiles.c_str(),ios::in);
	while(bookFile.read((char*)&selectedBook,sizeof(selectedBook)))
	{
		if(selectedBook.getId() == -1) continue;
		if(selectedBook.getId() == id ){
			bookFile.close();
			return true;
		}
	}
	bookFile.close();
	return false;
}

void Library::searchStudent(char *text){
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in);
	headStudent();
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == -1) continue;
		if(strcmp(selected.getName(),text) == 0 ){
			cout<<selected.getId()<<setw(20)<<(selected.getName())<<setw(18)
			    <<selected.getYear() << setw(15) << selected.getNumberOfBook() << endl;
		}
	}
	studentFile.close();
}
void Library::searchStudent(int year){
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in);
	headStudent();
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == -1) continue;
		if(selected.getYear() == year ){
			cout<<selected.getId()<<setw(20)<<(selected.getName())<<setw(18)
			    <<selected.getYear() << setw(15) << selected.getNumberOfBook() << endl;
		}
	}
	studentFile.close();
}

Student Library::searchStudent(int id,bool flag){
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in);
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == -1) continue;
		if(selected.getYear() == id ){
			return selected;
		}
	}
	studentFile.close();
	return selected;
}

bool Library::findStudent(int id) {
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in);
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == -1) continue;
		if(selected.getId() == id ){
			studentFile.close();
			return true;
		}
	}
	studentFile.close();
	return false;
}

void Library::updateBook(int id,char *name){
	Book selected;
	bookFile.open(bookFiles.c_str(),ios::in|ios::out);
	while(bookFile.read((char*)&selected,sizeof(Book)))
	{
		if(selected.getId() == id)
		{
			selected.setName(name);
			int pos= sizeof(selected); //move the cursure
			bookFile.seekp(-1 * pos,ios::cur);
			bookFile.write((char*)&selected,sizeof(selected));
		}
	}
	bookFile.close();

}

void Library::updateBook(int id,char *author,bool flag){
	Book selected;
	bookFile.open(bookFiles.c_str(),ios::in|ios::out);
	while(bookFile.read((char*)&selected,sizeof(Book)))
	{
		if(selected.getId() == id)
		{

			selected.setName(author);
			int pos= sizeof(selected); //move the cursure
			bookFile.seekp(-1 * pos,ios::cur);
			bookFile.write((char*)&selected,sizeof(selected));
		}
	}
	bookFile.close();
}

void Library::updateBook(int id,int year){
	Book selected;
	bookFile.open(bookFiles.c_str(),ios::in|ios::out);
	while(bookFile.read((char*)&selected,sizeof(Book)))
	{
		if(selected.getId() == id)
		{

			selected.setPublishYear(year);
			int pos= sizeof(selected); //move the cursure
			bookFile.seekp(-1 * pos,ios::cur);
			bookFile.write((char*)&selected,sizeof(selected));
		}
	}
	bookFile.close();
}

void Library::updateBook(int id,int amount,bool flag){
	Book selected;
	bookFile.open(bookFiles.c_str(),ios::in|ios::out);
	while(bookFile.read((char*)&selected,sizeof(Book)))
	{
		if(selected.getId() == id)
		{

			selected.setAmount(amount);
			int pos= sizeof(selected); //move the cursure
			bookFile.seekp(-1 * pos,ios::cur);
			bookFile.write((char*)&selected,sizeof(selected));
		}
	}
	bookFile.close();
}

void Library::updateStudent(int id,char *name){
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in|ios::out);
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == id)
		{
			selected.setName(name);
			int pos= sizeof(selected); //move the cursure
			studentFile.seekp(-1 * pos,ios::cur);
			studentFile.write((char*)&selected,sizeof(selected));
		}
	}
	studentFile.close();
}

void Library::updateStudent(int id,int y){
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in|ios::out);
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == id)
		{
			selected.setYear(y);
			int pos= sizeof(selected); //move the cursure
			studentFile.seekp(-1 * pos,ios::cur);
			studentFile.write((char*)&selected,sizeof(selected));
		}
	}
	studentFile.close();
}

void Library::updateStudentBorrow(int id){
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in|ios::out);
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == id)
		{
			selected.plusNumberOfBook();
			int pos= sizeof(selected); //move the cursure
			studentFile.seekp(-1 * pos,ios::cur);
			studentFile.write((char*)&selected,sizeof(selected));
		}
	}
	studentFile.close();
}
void Library::updateStudentReturn(int id){
	Student selected;
	studentFile.open(studentFiles.c_str(),ios::in|ios::out);
	while(studentFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == id)
		{
			selected.decreaseNumberOfBook();
			int pos= sizeof(selected); //move the cursure
			studentFile.seekp(-1 * pos,ios::cur);
			studentFile.write((char*)&selected,sizeof(selected));
		}
	}
	studentFile.close();
}


void Library::updateBookReturn(int id){
	Book selected;
	bookFile.open(bookFiles.c_str(),ios::in|ios::out);
	while(bookFile.read((char*)&selected,sizeof(selected)))
	{
		if(selected.getId() == id)
		{
			selected.setAmount(selected.getAmount()+1);
			selected.decreaseNumberOfStudent();
			int pos= sizeof(selected); //move the cursure
			bookFile.seekp(-1 * pos,ios::cur);
			bookFile.write((char*)&selected,sizeof(selected));
		}
	}
	bookFile.close();
}

void Library::deleteBook(int id){
	Book selected;
	bookFile.open(bookFiles.c_str(),ios::in|ios::out);
	while(bookFile.read((char*)&selected,sizeof(Book)))
	{
		if(selected.getId() == id)
		{
			selected.setId(-1);
			int pos= sizeof(selected); //move the cursure
			bookFile.seekp(-1 * pos,ios::cur);
			bookFile.write((char*)&selected,sizeof(selected));
		}
	}
	bookFile.close();
}

void Library::deleteStudent(int id){
	Student selected;
	studentFile.open(bookFiles.c_str(),ios::in|ios::out);
	while(studentFile.read((char*)&selected,sizeof(Student)))
	{
		if(selected.getId() == id)
			bool findBook(int id);{
			selected.setId(-1);
			int pos= sizeof(selected); //move the cursure
			studentFile.seekp(-1 * pos,ios::cur);
			studentFile.write((char*)&selected,sizeof(selected));
		}
	}
	studentFile.close();
}

void Library::deleteAllBooks(){
	bookFile.open(bookFiles.c_str(),ios::out);
	bookFile.close();
	int generateId = 0;
	char a[1] ;
	string s = libName + "BookID.txt";
	bookFile.open(s.c_str(),ios::out);
	a[0] = (char)generateId;
	bookFile.write(a,sizeof(a));
	bookFile.close();
}

void Library::deleteAllStudents(){
	studentFile.open(studentFiles.c_str(),ios::out);
	studentFile.close();
	int generateId = 0;
	char a[1] ;
	string s = libName + "StudentID.txt";
	studentFile.open(s.c_str(),ios::out);
	a[0] = (char)generateId;
	studentFile.write(a,sizeof(a));
	studentFile.close();
}

void Library::borrowBook(int bookId,int studentId) {
	if(findBook(bookId) == 0){
		cout << "book not found" << endl;
		return;
	}
	else if(findStudent(studentId) == 0){
		cout << " student not found" << endl;
		return;
	}
	Book selected;
	bookFile.open(bookFiles.c_str(),ios::in|ios::out);
	fstream file;
	string s = libName + "Borrow_return.txt";
	file.open(s.c_str(),ios::app);
	while(bookFile.read((char*)&selected,sizeof(Book)))
	{
		if(selected.getId() == bookId)
		{
			if(selected.getAmount() > 0){
				selected.plusNumberOfStudent();
				selected.setAmount(selected.getAmount()-1);
				updateStudentBorrow(studentId);
				d.bookId = bookId;
				d.studentId = studentId;
				file.write((char*)&d,sizeof(data));
				int pos= sizeof(selected); //move the cursure
				bookFile.seekp(-1 * pos,ios::cur);
				bookFile.write((char*)&selected,sizeof(selected));
				bookFile.close();
				break;
			}
			else {
				cout << "can't borrow" << endl;
			}
		}
	}
	bookFile.close();
	file.close();
}

void Library::returnBook(int bookId,int studentId) {
	if(findBook(bookId) == 0){
		cout << "book not found" << endl;
		return;
	}
	else if(findStudent(studentId) == 0){
		cout << " student not found" << endl;
		return;
	}
	fstream file;
	string s = libName + "Borrow_return.txt";
	file.open(s.c_str(),ios::out);
	while(file.read((char *)&d,sizeof(d))){
		if(d.bookId == bookId && d.studentId == studentId){
			updateStudentReturn(studentId);
			updateBookReturn(bookId);
			int pos= sizeof(data); //move the cursure
			file.seekp(-1 * pos,ios::cur);
			file.write((char*)&d,sizeof(data));
			break;
		}
	}
	file.close();
}
void Library::headBorrow(){
	cout<<"\n\n\t\t\t\tBorrow LIST\n\n";
	cout<<"============================================================================================\n";
	cout<<"Book ID"<<setw(15)<<"Student ID"<< endl;
	cout<<"============================================================================================\n";
}

void Library::displayAllBorrow(){
	fstream file;
	string s = libName + "Borrow_return.txt";
	file.open(s.c_str(),ios::in);
	headBorrow();
	while(file.read((char *)&d,sizeof(d))){
		cout << d.bookId << setw(15) << d.studentId <<endl;
	}
	file.close();
}
