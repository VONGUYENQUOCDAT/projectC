#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

void displayCustomerMenu(){
	int CustomerChoice;
	do{
		printf("\n===== CUSTOMER MANAGEMENT =====\n");
		printf("1. Display customer list\n");
		printf("2. Add new customers\n");
		printf("3. Edit customer information\n");
		printf("4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &CustomerChoice);
		
		switch(CustomerChoice){
			case 1:
				clearScreen();
				displayCustomers();
				break;
			case 2:
				clearScreen();
				addCustomer();
				break;
			case 3:
				clearScreen();
				editCustomer();
				break;
			case 4:
				clearScreen();
				printf("\nExit customer management.\n");
				break;
			default:
				clearScreen();
				printf("\nInvalid selection, please try again.\n");
		}
	}while(CustomerChoice!=4);
}

void displayCustomers(){
	if (customer_count==0){
		printf("\nThere are no customers.\n");
	}else{
		printf("\nList of customers:\n");
		for(int i=0; i<customer_count; i++){
			printf("ID: %s | Name: %s | Phone number: %s | Email: %s | Address: %s | Status: %s\n", customers[i].customerId, customers[i].name, customers[i].phone, customers[i].email, customers[i].address, customers[i].status);
		}
	}
}

void addCustomer(){
	if (customer_count>=MAX_CUSTOMERS){
		printf("\nThe customer list is full.\n");
		return;
	}
	Customer newCustomer;
	printf("\nEnter customer ID: ");
	scanf("%s", newCustomer.customerId);
	printf("Enter the customer's name: ");
	scanf("%s", newCustomer.name);
	printf("Enter phone number: ");
	scanf("%s", newCustomer.phone);
	printf("Enter Email: ");
	scanf("%s", newCustomer.email);
	printf("Enter Address: ");
	scanf("%s", newCustomer.address);
	printf("Enter Status: ");
	scanf("%s", newCustomer.status);
	
	customers[customer_count++] = newCustomer;
	printf("\nCustomer has been added successfully!\n");
}

void editCustomer(){
	char id[10];
	printf("\nEnter the customer ID that needs editing: ");
	scanf("%s", &id);
	
	for(int i=0; i<customer_count; i++){
		if(strcmp(customers[i].customerId, id)==0){
			printf("\nCurrent information:\n");
			printf("Name: %s | Phone: %s | Email: %s | Address: %s | Status: %s\n", customers[i].name, customers[i].phone, customers[i].email, customers[i].address, customers[i].status);
			
			printf("\nEnter new information (Do not edit status):\n");
			printf("Enter new name: ");
			scanf("%s", customers[i].name);
			printf("Enter new phone number: ");
			scanf("%s", customers[i].phone);
			printf("Enter new Email: ");
			scanf("%s", customers[i].email);
			printf("Enter new Address: ");
			scanf("%s", customers[i].address);
			
			printf("\nCustomer information has been successfully updated!\n");
			return;
		}
	}
	printf("\nNo customer found with ID: %s\n", id);
}
