#include <stdio.h>
#include "library.h"

int main(){
	int choice;
	do{
		displayMenu();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				clearScreen();
				loadBooksFromFile();
				displayBooks();
				break;
			case 2:
				clearScreen();
				addBook();
				saveBooksToFile();
				break;
			case 3:
				editBook();
				saveBooksToFile();
				clearScreen();
				break;
			case 4:
				deleteBook();
				saveBooksToFile();
				clearScreen();
				break;
			case 5:
				sortBooksByPrice();
				saveBooksToFile();
				clearScreen();
				break;
			case 6:
				clearScreen();
				searchBookByTitle();
				break;
			case 7:
				clearScreen();
				printf("\nExit the program.\n");
				break;
			default:
				clearScreen();
				printf("\nInvalid selection, please select again.\n");
			}
		}while(choice!=7);
	return 0;
}
