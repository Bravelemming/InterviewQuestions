#include <iostream>
#include <ccstring>

using namespace std;

void outputBookInfo(struct books *bookName) {
    // Print all info
    cout << "Book title : " << bookName->title << endl;
    cout << "Book author : " << bookName->author << endl;
    cout << "Book subject : " << bookName->subject << endl;
    cout << "Book id : " << bookName->book_id << endl;
}


//lets make a structure for any book we find!
struct books {
	char title[25]; 
	char author[50];
	char subject[75];
	int bookID; // internal id for our purposes
}

int main() {
	//instance of books, can be auto generated.
	struct books theFirstBook; 

	// book 1 specs
    strcpy( theFirstBook.title, "Learn C++");
    strcpy( theFirstBook.author, "some person"); 
    strcpy( theFirstBook.subject, "programming");
    theFirstBook.book_id = 1;

	//output info, passing address so we don't make a copy
    outputBookInfo(&theFirstBook);

	return 0;
}