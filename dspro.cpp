
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store user account details
typedef struct {
    char name[50];
    int accountNumber;
    int pin;
    float balance;
} Account;

// Global account instance
Account userAccount;

// Function prototypes
void createAccount();
void authenticate();
void mainMenu();
void checkBalance();
void depositMoney();
void withdrawMoney();

// Main function
int main() {
    printf("Welcome to the Virtual ATM!\n");
    createAccount();  // Create a new account
    authenticate();   // Authenticate user
    mainMenu();       // Show main menu
    return 0;
}

// Function to create a new account
void createAccount() {
    printf("\n--- Account Creation ---\n");
    printf("Enter your name: ");
    fgets(userAccount.name, 50, stdin);
    userAccount.name[strcspn(userAccount.name, "\n")] = '\0'; // Remove newline character
    printf("Enter a 4-digit PIN: ");
    scanf("%d", &userAccount.pin);
    userAccount.accountNumber = rand() % 100000 + 100000; // Generate random account number
    userAccount.balance = 0.0;
    printf("Account created successfully!\n");
    printf("Your Account Number: %d\n", userAccount.accountNumber);
}

// Function to authenticate the user
void authenticate() {
    int enteredPin;
    printf("\n--- Authentication ---\n");
    printf("Enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    while (enteredPin != userAccount.pin) {
        printf("Incorrect PIN. Please try again: ");
        scanf("%d", &enteredPin);
    }
    printf("Authentication successful!\n");
}

// Function to display the main menu
void mainMenu() {
    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                printf("Thank you for using the Virtual ATM! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Function to check account balance
void checkBalance() {
    printf("\n--- Check Balance ---\n");
    printf("Your current balance is: %.2f\n", userAccount.balance);
}

// Function to deposit money into the account
void depositMoney() {
    float amount;
    printf("\n--- Deposit Money ---\n");
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0) {
        userAccount.balance += amount;
        printf("Deposit successful! Your new balance is: %.2f\n", userAccount.balance);
    } else {
        printf("Invalid amount. Deposit failed.\n");
    }
}

// Function to withdraw money from the account
void withdrawMoney() {
    float amount;
    printf("\n--- Withdraw Money ---\n");
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= userAccount.balance) {
        userAccount.balance -= amount;
        printf("Withdrawal successful! Your new balance is: %.2f\n", userAccount.balance);
    } else if (amount > userAccount.balance) {
        printf("Insufficient balance. Withdrawal failed.\n");
    } else {
        printf("Invalid amount. Withdrawal failed.\n");
    }
}