#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_ACCOUNTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 50
#define FILE_NAME "bank_data.dat"

// Enum for account types
typedef enum {
    SAVINGS = 1,
    CURRENT = 2,
    FIXED_DEPOSIT = 3
} AccountType;

// Enum for transaction types
typedef enum {
    DEPOSIT = 1,
    WITHDRAW = 2,
    TRANSFER = 3
} TransactionType;

// Structure for account holder
typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    AccountType account_type;
    float balance;
    char phone[15];
    char email[50];
    time_t account_created;
} Account;

// Structure for transaction
typedef struct {
    int account_number;
    TransactionType type;
    float amount;
    time_t timestamp;
} Transaction;

// Global arrays to store accounts and transactions
Account accounts[MAX_ACCOUNTS];
Transaction transactions[MAX_ACCOUNTS * 10];
int account_count = 0;
int transaction_count = 0;

// Function prototypes
void initialize_system();
int create_account();
int login();
void display_account_info(int account_index);
void deposit(int account_index);
void withdraw(int account_index);
void transfer_funds(int account_index);
void save_data();
void load_data();
void generate_account_statement(int account_index);
void admin_panel();
float calculate_interest(Account *account);

// Main function
int main() {
    int choice, logged_in_index = -1;

    // Load existing data
    load_data();

    while (1) {
        printf("\n=== Bank Management System ===\n");
        printf("1. Create New Account\n");
        printf("2. Login\n");
        printf("3. Admin Panel\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                logged_in_index = login();
                if (logged_in_index != -1) {
                    int user_choice;
                    while (1) {
                        printf("\n=== Account Menu ===\n");
                        printf("1. View Account Info\n");
                        printf("2. Deposit\n");
                        printf("3. Withdraw\n");
                        printf("4. Transfer Funds\n");
                        printf("5. Account Statement\n");
                        printf("6. Logout\n");
                        printf("Enter your choice: ");
                        scanf("%d", &user_choice);

                        switch (user_choice) {
                            case 1:
                                display_account_info(logged_in_index);
                                break;
                            case 2:
                                deposit(logged_in_index);
                                break;
                            case 3:
                                withdraw(logged_in_index);
                                break;
                            case 4:
                                transfer_funds(logged_in_index);
                                break;
                            case 5:
                                generate_account_statement(logged_in_index);
                                break;
                            case 6:
                                logged_in_index = -1;
                                break;
                        }

                        if (logged_in_index == -1) break;
                    }
                }
                break;
            case 3:
                admin_panel();
                break;
            case 4:
                save_data();
                printf("Thank you for using the Bank Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
int create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return -1;
    }

    Account *new_account = &accounts[account_count];
    
    // Generate unique account number
    new_account->account_number = 10000 + account_count;
    
    printf("Enter Name: ");
    scanf(" %[^\n]", new_account->name);
    
    printf("Set Password: ");
    scanf("%s", new_account->password);
    
    printf("Select Account Type:\n");
    printf("1. Savings\n2. Current\n3. Fixed Deposit\n");
    scanf("%d", (int*)&new_account->account_type);
    
    printf("Initial Deposit Amount: ");
    scanf("%f", &new_account->balance);
    
    printf("Phone Number: ");
    scanf("%s", new_account->phone);
    
    printf("Email: ");
    scanf("%s", new_account->email);
    
    // Set account creation time
    new_account->account_created = time(NULL);
    
    account_count++;
    save_data();
    
    printf("Account created successfully!\n");
    printf("Your Account Number is: %d\n", new_account->account_number);
    
    return account_count - 1;
}

// Function to login
int login() {
    int account_number;
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    
    printf("Enter Password: ");
    scanf("%s", password);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number && 
            strcmp(accounts[i].password, password) == 0) {
            printf("Login Successful!\n");
            return i;
        }
    }
    
    printf("Invalid Account Number or Password!\n");
    return -1;
}

// Function to display account information
void display_account_info(int account_index) {
    Account *account = &accounts[account_index];
    
    printf("\n=== Account Information ===\n");
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Account Type: %d\n", account->account_type);
    printf("Balance: $%.2f\n", account->balance);
    printf("Phone: %s\n", account->phone);
    printf("Email: %s\n", account->email);
    printf("Account Created: %s", ctime(&account->account_created));
}

// Function to deposit money
void deposit(int account_index) {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    
    accounts[account_index].balance += amount;
    
    // Record transaction
    Transaction *transaction = &transactions[transaction_count++];
    transaction->account_number = accounts[account_index].account_number;
    transaction->type = DEPOSIT;
    transaction->amount = amount;
    transaction->timestamp = time(NULL);
    
    save_data();
    printf("Deposit successful. New balance: $%.2f\n", accounts[account_index].balance);
}

// Function to withdraw money
void withdraw(int account_index) {
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    
    if (amount > accounts[account_index].balance) {
        printf("Insufficient funds!\n");
        return;
    }
    
    accounts[account_index].balance -= amount;
    
    // Record transaction
    Transaction *transaction = &transactions[transaction_count++];
    transaction->account_number = accounts[account_index].account_number;
    transaction->type = WITHDRAW;
    transaction->amount = amount;
    transaction->timestamp = time(NULL);
    
    save_data();
    printf("Withdrawal successful. New balance: $%.2f\n", accounts[account_index].balance);
}

// Function to transfer funds
void transfer_funds(int account_index) {
    int target_account_number;
    float amount;
    int target_index = -1;
    
    printf("Enter target account number: ");
    scanf("%d", &target_account_number);
    
    // Find target account
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == target_account_number) {
            target_index = i;
            break;
        }
    }
    
    if (target_index == -1) {
        printf("Target account not found!\n");
        return;
    }
    
    printf("Enter transfer amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    
    if (amount > accounts[account_index].balance) {
        printf("Insufficient funds!\n");
        return;
    }
    
    // Perform transfer
    accounts[account_index].balance -= amount;
    accounts[target_index].balance += amount;
    
    // Record transactions
    Transaction *sender_transaction = &transactions[transaction_count++];
    sender_transaction->account_number = accounts[account_index].account_number;
    sender_transaction->type = TRANSFER;
    sender_transaction->amount = -amount;
    sender_transaction->timestamp = time(NULL);
    
    Transaction *receiver_transaction = &transactions[transaction_count++];
    receiver_transaction->account_number = accounts[target_index].account_number;
    receiver_transaction->type = TRANSFER;
    receiver_transaction->amount = amount;
    receiver_transaction->timestamp = time(NULL);
    
    save_data();
    printf("Transfer successful. New balance: $%.2f\n", accounts[account_index].balance);
}

// Function to generate account statement
void generate_account_statement(int account_index) {
    int account_number = accounts[account_index].account_number;
    
    printf("\n=== Account Statement ===\n");
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].account_number == account_number) {
            printf("Type: %d, Amount: $%.2f, Date: %s", 
                   transactions[i].type, 
                   transactions[i].amount, 
                   ctime(&transactions[i].timestamp));
        }
    }
}

// Function to save data to file
void save_data() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    
    fwrite(&account_count, sizeof(int), 1, file);
    fwrite(accounts, sizeof(Account), account_count, file);
    
    fwrite(&transaction_count, sizeof(int), 1, file);
    fwrite(transactions, sizeof(Transaction), transaction_count, file);
    
    fclose(file);
}

// Function to load data from file
void load_data() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    
    fread(&account_count, sizeof(int), 1, file);
    fread(accounts, sizeof(Account), account_count, file);
    
    fread(&transaction_count, sizeof(int), 1, file);
    fread(transactions, sizeof(Transaction), transaction_count, file);
    
    fclose(file);
}

// Admin panel function
void admin_panel() {
    char admin_password[50];
    printf("Enter Admin Password: ");
    scanf("%s", admin_password);
    
    if (strcmp(admin_password, "admin123") != 0) {
        printf("Invalid Admin Password!\n");
        return;
    }
    
    while (1) {
        int choice;
        printf("\n=== Admin Panel ===\n");
        printf("1. View All Accounts\n");
        printf("2. Total Bank Balance\n");
        printf("3. Exit Admin Panel\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                for (int i = 0; i < account_count; i++) {
                    display_account_info(i);
                }
                break;
            case 2:
                {
                    float total_balance = 0;
                    for (int i = 0; i < account_count; i++) {
                        total_balance += accounts[i].balance;
                    }
                    printf("Total Bank Balance: $%.2f\n", total_balance);
                }
                break;
            case 3:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Optional: Interest calculation function for savings accounts
float calculate_interest(Account *account) {
    float interest_rate = 0;
    
    switch (account->account_type) {
        case SAVINGS:
            interest_rate = 0.04;  // 4% for savings
            break;
        case CURRENT:
            interest_rate = 0.01;  // 1% for current
            break;
        case FIXED_DEPOSIT:
            interest_rate = 0.07;  // 7% for fixed deposit
            break;
    }
    
    return account->balance * interest_rate;
}