#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 50
#define MAX_ORDER_ITEMS 50

// --------- Structures ---------

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

typedef struct {
    MenuItem item;
    int quantity;
} OrderItem;

typedef struct {
    OrderItem items[MAX_ORDER_ITEMS];
    int count;
} Order;

// --------- Function Declarations ---------

void initMenu(MenuItem menu[], int *menuCount);
void displayMenu(MenuItem menu[], int menuCount);
int findMenuItemById(MenuItem menu[], int menuCount, int id);
void addItemToOrder(MenuItem menu[], int menuCount, Order *order);
void viewCurrentOrder(Order *order);
void generateBill(Order *order);
void clearOrder(Order *order);

// --------- Main Function ---------

int main() {
    MenuItem menu[MAX_MENU_ITEMS];
    int menuCount = 0;
    Order order;
    order.count = 0;

    int choice;

    initMenu(menu, &menuCount);

    while (1) {
        printf("\n========================================\n");
        printf("       RESTAURANT MANAGEMENT SYSTEM     \n");
        printf("========================================\n");
        printf("1. Show Menu\n");
        printf("2. Add Item to Order\n");
        printf("3. View Current Order\n");
        printf("4. Generate Bill\n");
        printf("5. Clear Order\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting...\n");
            return 0;
        }

        switch (choice) {
        case 1:
            displayMenu(menu, menuCount);
            break;
        case 2:
            addItemToOrder(menu, menuCount, &order);
            break;
        case 3:
            viewCurrentOrder(&order);
            break;
        case 4:
            generateBill(&order);
            break;
        case 5:
            clearOrder(&order);
            printf("Order cleared successfully!\n");
            break;
        case 0:
            printf("Thank you for using the system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// --------- Function Definitions ---------

// Pre-load some menu items
void initMenu(MenuItem menu[], int *menuCount) {
    *menuCount = 0;

    menu[*menuCount].id = 1;
    strcpy(menu[*menuCount].name, "Veg Burger");
    menu[*menuCount].price = 80.0;
    (*menuCount)++;

    menu[*menuCount].id = 2;
    strcpy(menu[*menuCount].name, "Chicken Burger");
    menu[*menuCount].price = 120.0;
    (*menuCount)++;

    menu[*menuCount].id = 3;
    strcpy(menu[*menuCount].name, "French Fries");
    menu[*menuCount].price = 60.0;
    (*menuCount)++;

    menu[*menuCount].id = 4;
    strcpy(menu[*menuCount].name, "Cheese Pizza");
    menu[*menuCount].price = 200.0;
    (*menuCount)++;

    menu[*menuCount].id = 5;
    strcpy(menu[*menuCount].name, "Cold Coffee");
    menu[*menuCount].price = 90.0;
    (*menuCount)++;

    menu[*menuCount].id = 6;
    strcpy(menu[*menuCount].name, "Soft Drink");
    menu[*menuCount].price = 40.0;
    (*menuCount)++;
}

void displayMenu(MenuItem menu[], int menuCount) {
    int i;
    printf("\n------------- MENU -------------\n");
    printf("%-5s %-20s %-10s\n", "ID", "Item", "Price");
    printf("--------------------------------\n");
    for (i = 0; i < menuCount; i++) {
        printf("%-5d %-20s Rs. %-10.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("--------------------------------\n");
}

// Find menu index by ID, return -1 if not found
int findMenuItemById(MenuItem menu[], int menuCount, int id) {
    int i;
    for (i = 0; i < menuCount; i++) {
        if (menu[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addItemToOrder(MenuItem menu[], int menuCount, Order *order) {
    int id, quantity;
    int index;

    if (order->count >= MAX_ORDER_ITEMS) {
        printf("Order is full! Cannot add more items.\n");
        return;
    }

    displayMenu(menu, menuCount);

    printf("Enter item ID to add to order: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        return;
    }

    index = findMenuItemById(menu, menuCount, id);
    if (index == -1) {
        printf("Item with ID %d not found in menu.\n", id);
        return;
    }

    printf("Enter quantity: ");
    if (scanf("%d", &quantity) != 1 || quantity <= 0) {
        printf("Invalid quantity!\n");
        return;
    }

    // Check if item is already in order
    int i;
    for (i = 0; i < order->count; i++) {
        if (order->items[i].item.id == id) {
            order->items[i].quantity += quantity;
            printf("Updated quantity of %s to %d.\n",
                   order->items[i].item.name,
                   order->items[i].quantity);
            return;
        }
    }

    // Add new item to order
    order->items[order->count].item = menu[index];
    order->items[order->count].quantity = quantity;
    order->count++;

    printf("Added %d x %s to order.\n", quantity, menu[index].name);
}

void viewCurrentOrder(Order *order) {
    if (order->count == 0) {
        printf("\nNo items in the current order.\n");
        return;
    }

    printf("\n---------- CURRENT ORDER ----------\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Item", "Qty", "Subtotal");
    printf("-----------------------------------\n");

    float total = 0.0;
    int i;
    for (i = 0; i < order->count; i++) {
        float subtotal = order->items[i].item.price * order->items[i].quantity;
        total += subtotal;
        printf("%-5d %-20s %-10d Rs. %-10.2f\n",
               order->items[i].item.id,
               order->items[i].item.name,
               order->items[i].quantity,
               subtotal);
    }

    printf("-----------------------------------\n");
    printf("Total: Rs. %.2f\n", total);
}

void generateBill(Order *order) {
    if (order->count == 0) {
        printf("No items in order. Add items before generating bill.\n");
        return;
    }

    printf("\n============== FINAL BILL ==============\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Item", "Qty", "Subtotal");
    printf("----------------------------------------\n");

    float total = 0.0;
    int i;
    for (i = 0; i < order->count; i++) {
        float subtotal = order->items[i].item.price * order->items[i].quantity;
        total += subtotal;
        printf("%-5d %-20s %-10d Rs. %-10.2f\n",
               order->items[i].item.id,
               order->items[i].item.name,
               order->items[i].quantity,
               subtotal);
    }

    float taxRate = 0.05f; // 5% tax
    float tax = total * taxRate;
    float grandTotal = total + tax;

    printf("----------------------------------------\n");
    printf("Subtotal      : Rs. %.2f\n", total);
    printf("Tax (5%%)      : Rs. %.2f\n", tax);
    printf("Grand Total   : Rs. %.2f\n", grandTotal);
    printf("========================================\n");
    printf("Thank you! Visit again.\n");

    // After bill, clear order
    clearOrder(order);
}

void clearOrder(Order *order) {
    order->count = 0;
}