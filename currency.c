#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Maximum number of supported currencies
#define MAX_CURRENCIES 10

// Currency structure
typedef struct {
    char code[4];     // Currency code (USD, EUR, etc.)
    char name[50];    // Full currency name
    double rate;      // Exchange rate to base currency (USD)
} Currency;

// Global currency array
Currency currencies[MAX_CURRENCIES] = {
    {"USD", "US Dollar", 1.0},
    {"EUR", "Euro", 0.92},
    {"GBP", "British Pound", 0.79},
    {"JPY", "Japanese Yen", 149.50},
    {"CAD", "Canadian Dollar", 1.35},
    {"AUD", "Australian Dollar", 1.52},
    {"CHF", "Swiss Franc", 0.88},
    {"CNY", "Chinese Yuan", 7.15},
    {"INR", "Indian Rupee", 83.20},
    {"BRL", "Brazilian Real", 4.95}
};

// Number of currently supported currencies
int currency_count = 10;

// Function prototypes
void display_currencies();
int find_currency(char* code);
void convert_currency();
void add_currency();
void remove_currency();
void save_rates();
void load_rates();
void currency_history();

// Main function
int main() {
    int choice;
    
    // Attempt to load saved rates
    load_rates();

    while (1) {
        // Clear screen (works on most systems)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n=== Currency Converter ===\n");
        printf("1. Convert Currency\n");
        printf("2. View Available Currencies\n");
        printf("3. Add New Currency\n");
        printf("4. Remove Currency\n");
        printf("5. Currency Conversion History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                convert_currency();
                break;
            case 2:
                display_currencies();
                break;
            case 3:
                add_currency();
                break;
            case 4:
                remove_currency();
                break;
            case 5:
                currency_history();
                break;
            case 6:
                // Save rates before exiting
                save_rates();
                printf("Thank you for using Currency Converter!\n");
                exit(0);
            default:
                printf("Invalid choice. Press Enter to continue...");
                getchar(); getchar();
        }
    }
    return 0;
}

// Display available currencies
void display_currencies() {
    printf("\n=== Available Currencies ===\n");
    printf("Code | Currency Name | Current Rate to USD\n");
    printf("-----+---------------+--------------------\n");
    
    for (int i = 0; i < currency_count; i++) {
        printf("%4s | %-13s | %.4f\n", 
               currencies[i].code, 
               currencies[i].name, 
               currencies[i].rate);
    }
    
    printf("\nPress Enter to continue...");
    getchar(); getchar();
}

// Find currency index by code
int find_currency(char* code) {
    for (int i = 0; i < currency_count; i++) {
        if (strcasecmp(currencies[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}

// Currency conversion function
void convert_currency() {
    char from[4], to[4];
    double amount;
    
    printf("Enter source currency code: ");
    scanf("%3s", from);
    
    int from_index = find_currency(from);
    if (from_index == -1) {
        printf("Invalid source currency!\n");
        return;
    }
    
    printf("Enter target currency code: ");
    scanf("%3s", to);
    
    int to_index = find_currency(to);
    if (to_index == -1) {
        printf("Invalid target currency!\n");
        return;
    }
    
    printf("Enter amount to convert: ");
    scanf("%lf", &amount);
    
    // Conversion calculation
    // Convert to USD first, then to target currency
    double usd_amount = amount / currencies[from_index].rate;
    double converted_amount = usd_amount * currencies[to_index].rate;
    
    printf("\n--- Conversion Result ---\n");
    printf("%.2f %s = %.2f %s\n", 
           amount, currencies[from_index].name, 
           converted_amount, currencies[to_index].name);
    
    // Save conversion to history
    FILE *history = fopen("conversion_history.txt", "a");
    time_t now;
    time(&now);
    
    fprintf(history, "%.2f %s → %.2f %s (on %s)", 
            amount, currencies[from_index].name, 
            converted_amount, currencies[to_index].name, 
            ctime(&now));
    fclose(history);
    
    printf("\nPress Enter to continue...");
    getchar(); getchar();
}

// Add new currency
void add_currency() {
    if (currency_count >= MAX_CURRENCIES) {
        printf("Maximum currency limit reached!\n");
        return;
    }
    
    Currency new_currency;
    
    printf("Enter 3-letter currency code: ");
    scanf("%3s", new_currency.code);
    
    // Check if currency already exists
    if (find_currency(new_currency.code) != -1) {
        printf("Currency already exists!\n");
        return;
    }
    
    printf("Enter full currency name: ");
    scanf("%49s", new_currency.name);
    
    printf("Enter exchange rate to USD: ");
    scanf("%lf", &new_currency.rate);
    
    currencies[currency_count++] = new_currency;
    
    // Save updated rates
    save_rates();
    
    printf("Currency added successfully!\n");
}

// Remove a currency
void remove_currency() {
    char code[4];
    
    printf("Enter currency code to remove: ");
    scanf("%3s", code);
    
    int index = find_currency(code);
    if (index == -1) {
        printf("Currency not found!\n");
        return;
    }
    
    // Shift array to remove currency
    for (int i = index; i < currency_count - 1; i++) {
        currencies[i] = currencies[i + 1];
    }
    currency_count--;
    
    // Save updated rates
    save_rates();
    
    printf("Currency removed successfully!\n");
}

// Save currency rates to file
void save_rates() {
    FILE *file = fopen("currency_rates.dat", "wb");
    if (file == NULL) {
        printf("Error saving rates!\n");
        return;
    }
    
    fwrite(&currency_count, sizeof(int), 1, file);
    fwrite(currencies, sizeof(Currency), currency_count, file);
    
    fclose(file);
}

// Load currency rates from file
void load_rates() {
    FILE *file = fopen("currency_rates.dat", "rb");
    if (file == NULL) {
        printf("No saved rates found. Using default rates.\n");
        return;
    }
    
    fread(&currency_count, sizeof(int), 1, file);
    fread(currencies, sizeof(Currency), currency_count, file);
    
    fclose(file);
}

// View conversion history
void currency_history() {
    FILE *history = fopen("conversion_history.txt", "r");
    if (history == NULL) {
        printf("No conversion history found.\n");
        return;
    }
    
    printf("\n=== Conversion History ===\n");
    
    char line[200];
    while (fgets(line, sizeof(line), history)) {
        printf("%s", line);
    }
    
    fclose(history);
    
    printf("\nPress Enter to continue...");
    getchar(); getchar();
}