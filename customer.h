#ifndef CUSTOMER_H
#define CUSTOMER_H

#define MAX_CUSTOMERS 100

typedef struct{
	char customerId[10];
	char name[50];
	char phone[15];
	char email[50];
	char address[100];
	char status[15]; //khong duoc sua
}Customer;

extern Customer customers[MAX_CUSTOMERS];
extern int customer_count;

void displayCustomerMenu();
void displayCustomers();
void addCustomer();
void editCustomer();

#endif // Dong lai pham vi cua #ifndef
