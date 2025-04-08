#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 5

typedef struct {
    char name[50];
    float price;
    int stock;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    float balance;
    int product_count;
} VendingMachine;

void initialize_machine(VendingMachine *machine) {
    machine->balance = 0.0;
    machine->product_count = 0;
    
    // Add some products
    strcpy(machine->products[0].name, "Soda");
    machine->products[0].price = 1.50;
    machine->products[0].stock = 10;
    
    strcpy(machine->products[1].name, "Chips");
    machine->products[1].price = 1.00;
    machine->products[1].stock = 8;
    
    strcpy(machine->products[2].name, "Chocolate");
    machine->products[2].price = 1.25;
    machine->products[2].stock = 5;
    
    strcpy(machine->products[3].name, "Water");
    machine->products[3].price = 1.00;
    machine->products[3].stock = 12;
    
    strcpy(machine->products[4].name, "Candy");
    machine->products[4].price = 0.75;
    machine->products[4].stock = 15;
    
    machine->product_count = 5;
}

void display_products(VendingMachine *machine) {
    printf("\n===== AVAILABLE PRODUCTS =====\n");
    for (int i = 0; i < machine->product_count; i++) {
        if (machine->products[i].stock > 0) {
            printf("%d. %s - $%.2f (%d in stock)\n", 
                   i+1, 
                   machine->products[i].name, 
                   machine->products[i].price,
                   machine->products[i].stock);
        }
    }
}

void insert_coin(VendingMachine *machine, float coin) {
    machine->balance += coin;
    printf("Inserted $%.2f. Current balance: $%.2f\n", coin, machine->balance);
}

int select_product(VendingMachine *machine, int choice) {
    int product_idx = choice - 1;
    
    if (product_idx < 0 || product_idx >= machine->product_count) {
        printf("Invalid product selection.\n");
        return 0;
    }
    
    Product *selected = &machine->products[product_idx];
    
    if (selected->stock <= 0) {
        printf("Sorry, %s is out of stock.\n", selected->name);
        return 0;
    }
    
    if (machine->balance < selected->price) {
        printf("Insufficient funds. Please insert more money.\n");
        printf("Current balance: $%.2f, %s price: $%.2f\n", 
               machine->balance, selected->name, selected->price);
        return 0;
    }
    
    // Dispense product
    selected->stock--;
    machine->balance -= selected->price;
    printf("Dispensing %s. Enjoy!\n", selected->name);
    return 1;
}

void return_change(VendingMachine *machine) {
    if (machine->balance > 0) {
        printf("Returning change: $%.2f\n", machine->balance);
        machine->balance = 0.0;
    }
}

void simulate_vending_machine() {
    VendingMachine machine;
    initialize_machine(&machine);
    
    printf("=== VENDING MACHINE SIMULATION ===\n");
    
    // Simulate a sequence of operations
    printf("\n--- Simulation Start ---\n");
    
    display_products(&machine);
    
    printf("\nCustomer 1 approaches the machine\n");
    insert_coin(&machine, 1.00);
    insert_coin(&machine, 0.25);
    select_product(&machine, 2); // Chips for $1.00
    return_change(&machine);
    
    printf("\nCustomer 2 approaches the machine\n");
    insert_coin(&machine, 1.00);
    insert_coin(&machine, 0.50);
    select_product(&machine, 1); // Attempt to buy Soda for $1.50
    insert_coin(&machine, 0.25); // Add more coins
    select_product(&machine, 1); // Now successfully buy Soda
    return_change(&machine);
    
    printf("\nCustomer 3 approaches the machine\n");
    insert_coin(&machine, 5.00);
    select_product(&machine, 3); // Chocolate for $1.25
    select_product(&machine, 4); // Water for $1.00
    return_change(&machine);
    
    printf("\n--- Final Machine Status ---\n");
    display_products(&machine);
}

int main() {
    simulate_vending_machine();
    return 0;
}