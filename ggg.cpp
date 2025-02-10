#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Customer structure
typedef struct {
    char name[50];
    int id;
    char date[20];
    char time[20];
    char phone[20];
} Customer;

// Shop structure
typedef struct {
    char name[50];
    char address[100];
    int number;
} Shop;

// Product structure
typedef struct {
    int number;
    float price;
    int quantity;
} Product;


int main() {
    Customer customer;
    Shop shop;
    Product product;
    float discount_rate, discount_amount, net_amount,total_amount;
    float total_price = 0;
    int i, n;
    
    // Input customer information
    printf("Enter customer name: ");
    fgets(customer.name, 50, stdin);
    printf("Enter customer ID: ");
    scanf("%d", &customer.id);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", customer.date);
    
    printf("Enter phone number: ");
    scanf("%s", customer.phone);

    // Input shop information
    printf("Enter shop name: ");
    getchar(); // clear input buffer
    fgets(shop.name, 50, stdin);
    
    printf("Enter shop phone number: ");
    scanf("%d", &shop.number);

    // Input number of products
    printf("Enter number of products: ");
    scanf("%d", &n);

    // Input product information
    for (i = 0; i < n; i++) {
        printf("Enter product number: ");
        scanf("%d", &product.number);
        printf("Enter product price: ");
        scanf("%f", &product.price);
        printf("Enter product quantity: ");
        scanf("%d", &product.quantity);
        printf("Enter discount rate (in percentage): ");
        scanf("%f", &discount_rate);
		total_price += product.price * product.quantity;
		discount_amount = total_price * (discount_rate / 100);
		net_amount = total_price - discount_amount;
    }
int paymentMethod;
    printf("Enter payment method (1 for cash, 2 for card, 3 for online): ");
    scanf("%d", &paymentMethod);

    switch (paymentMethod) {
        case 1:
            printf("Payment method: Cash\n");
            printf("Enter cash amount: ");
            float cash;
            scanf("%f", &cash);
            if (cash >= net_amount) {
                printf("Payment successful. Change: Rs. %.2f\n", cash - net_amount);
            } else {
                printf("Payment failed. Insufficient cash.\n");
            }
            break;
        case 2:
            printf("Payment method: Card\n");
            int cardType;
            printf("Enter card type (1 for Rupay, 2 for Mastercard, 3 for Visa): ");
            scanf("%d", &cardType);
            printf("Enter card number: ");
            char cardNumber[20];
            scanf("%s", cardNumber);
            printf("Enter expiry date (MM/YY): ");
            char expiryDate[6];
            scanf("%s", expiryDate);
            printf("Enter CVV: ");
            char cvv[4];
            scanf("%s", cvv);
            printf("Card payment successful.\n");
            break;
        case 3:
            printf("Payment method: Online\n");
            int upiOption;
            printf("Enter UPI option (1 for UPI ID, 2 for QR code): ");
            scanf("%d", &upiOption);
            switch (upiOption) {
                case 1:
                    printf("Enter UPI ID: ");
                    char upiId[50];
                    scanf("%s", upiId);
                    printf("UPI payment successful.\n");
                    break;
                case 2:
                    printf("Scan QR code and complete payment.\n");
                    break;
                default:
                    printf("Invalid UPI option.\n");
            }
            break;
        default:
            printf("Invalid payment method.\n");
    }    

   
    // Print bill
    printf("\n-----------------BILL------------------\n");
    printf("\n\nCustomer name: %s", customer.name);
    printf("Customer ID: %d\n", customer.id);
    printf("Date: %s\n", customer.date);
    
    printf("Phone number: %s\n", customer.phone);
    printf("\nShop name: %s", shop.name);
    
    printf("Shop phone number: %d\n", shop.number);
    printf("\nProduct details:\n");
   printf("Number\tPrice\tQuantity\n");
for (i = 0; i < n; i++) {
    printf("%d\t%.2f\t%d\n", product.number, product.price, product.quantity);
}

    printf("\nTotal price: %.2f\n", total_price);
    printf("Discount Rate: %.2f%%\n", discount_rate);
  printf("Discount Amount: %.2f\n", discount_amount);
  printf("Net Amount: %.2f\n", net_amount);
  

    return 0;
}
