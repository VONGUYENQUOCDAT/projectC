#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

Book library[MAX_BOOKS];
int book_count=0;

void displayBooks(){
	if(book_count == 0){
		printf("\nKhong co sach trong thu vien.\n");
	}else{
		printf("%55s","****ALL BOOKS****");
		printf("\n=============================================================================================\n");
		printf("|%-10s|%-30s|%-20s|%-8s|%-8s|%-10s|\n","Book ID","Tieu de","Tac gia","So luong","Gia","Xuat ban");
		printf("=============================================================================================\n");
		for(int i=0; i<book_count; i++){
			printf("|%-10s|%-30s|%-20s|%-8d|%-8d|%02d/%02d/%04d|",library[i].bookId, library[i].title, library[i].author,library[i].quantity, library[i].price, library[i].publication.day, library[i].publication.month, library[i].publication.year);
			printf("\n---------------------------------------------------------------------------------------------\n");
		}
	}
}

void addBook(){
	if(book_count>=MAX_BOOKS){
		printf("\nThu vien da day, khong the them sach nua");
		return;
	}
	Book newBook;
	
	printf("Nhap ma sach: ");
	scanf("%s", newBook.bookId);
	
	printf("Nhap tieu de cua sach: ");
	getchar(); // xoa bo dem
	fgets(newBook.title, sizeof(newBook.title), stdin);
	newBook.title[strcspn(newBook.title, "\n")] = 0; // bo ki tu xuong dong cua fgets
	
	printf("Nhap tac gia cua sach: ");
	fgets(newBook.author, sizeof(newBook.author), stdin);
	newBook.author[strcspn(newBook.author, "\n")] = 0; // bo ki tu xuong dong cua fgets
	
	printf("Nhap so luong: ");
	scanf("%d",&newBook.quantity);
	
	printf("Nhap gia: ");
	scanf("%d",&newBook.price);
	
	printf("Nhap ngay xuat ban(dd mm yyyy): ");
	scanf("%d %d %d",&newBook.publication.day,&newBook.publication.month,&newBook.publication.year);
	
	library[book_count++] = newBook;// Them sach moi vao mang library tai vi tri book_count va tang bien dem len 1.
	printf("\nDanh sach da duoc them thanh cong!\n");
}
