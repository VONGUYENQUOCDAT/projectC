#include <stdio.h>
#include "library.h"

int main(){
	int choice;
	if(authenticateAdmin()){
	do{
	printf("\n*** Library Manager ***\n");
	printf("1. LIBRARY MANAGEMENT SYSTEM\n");
	printf("2. CUSTOMER MANAGEMENT\n");
	printf("3. Exit.\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:{
			clearScreen();
			int LibraryChoice;
			do{
				displayMenu();
				scanf("%d", &LibraryChoice);
				switch(LibraryChoice){
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
						clearScreen();
						editBook();
						saveBooksToFile();
						break;
					case 4:
						clearScreen();
						deleteBook();
						saveBooksToFile();
						break;
					case 5:
						clearScreen();
						sortBooksByPrice();
						saveBooksToFile();
						break;
					case 6:
						clearScreen();
						searchBookByTitle();
						break;
					case 7:
						clearScreen();
						printf("\n========= Thank You =========\n");
						printf("======== See You Soon =======\n");
						break;
					default:
						clearScreen();
						printf("\nInvalid selection, please select again.\n");
					}
				}while(LibraryChoice!=7);
				break;
			}
		case 2:
			clearScreen();
			displayCustomerMenu();
			break;
		case 3:
			clearScreen();
			return 0;
		default:
			printf("\nInvalid selection, please select again.\n");
		}
	}while(choice!=3);
	}
	return 0;
}
