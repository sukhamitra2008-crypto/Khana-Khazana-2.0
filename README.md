# 🍽️ **Khana Khazana 2.0 --- Restaurant Management System (C Project)**

A fast, clean, and beginner-friendly **restaurant management system**
built entirely in **C**.\
Manage menu, orders, billing, and totals --- all through a simple
terminal interface.

------------------------------------------------------------------------

## 📸 Screenshots

<p align="center">
  <img src="https://raw.githubusercontent.com/sukhamitra2008-crypto/Khana-Khazana-2.0/0aba5bc8eeb55efd4b22963984dd5fff0f8cf492/Resturant-SS-01.png" width="80%" />
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/sukhamitra2008-crypto/Khana-Khazana-2.0/0aba5bc8eeb55efd4b22963984dd5fff0f8cf492/Resturant-SS-02.png" width="80%" />
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/sukhamitra2008-crypto/Khana-Khazana-2.0/0aba5bc8eeb55efd4b22963984dd5fff0f8cf492/Resturant-SS-03.png" width="80%" />
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/sukhamitra2008-crypto/Khana-Khazana-2.0/0aba5bc8eeb55efd4b22963984dd5fff0f8cf492/Resturant-SS-04.png" width="80%" />
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/sukhamitra2008-crypto/Khana-Khazana-2.0/0aba5bc8eeb55efd4b22963984dd5fff0f8cf492/Resturant-SS-05.png" width="80%" />
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/sukhamitra2008-crypto/Khana-Khazana-2.0/0aba5bc8eeb55efd4b22963984dd5fff0f8cf492/Resturant-SS-06.png" width="80%" />
</p>


## 🚀 **Features**

### 📜 Pre-Loaded Menu

Food items with IDs, names, and prices already added.

### ➕ Add Items to Order

Search by ID → add quantity → auto-update totals.

### 👀 View Current Order

See everything you added, with subtotal.

### 🧾 Auto Bill Generation

Includes:\
- Itemized bill\
- Subtotals\
- **5% GST calculation**\
- Grand total

### 🗑️ Clear Order

Reset everything instantly.

### 💻 100% Terminal Based

No external dependencies --- pure C.

------------------------------------------------------------------------

## 🧩 **How It Works**

``` c
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
```

------------------------------------------------------------------------

## 📺 **Terminal Preview**

    ========================================
           RESTAURANT MANAGEMENT SYSTEM
    ========================================
    1. Show Menu
    2. Add Item to Order
    3. View Current Order
    4. Generate Bill
    5. Clear Order
    0. Exit

### 🧾 Sample Bill

    ============== FINAL BILL ==============
    ID    Item                Qty     Subtotal
    -----------------------------------------
    1     Veg Burger          2       Rs. 160.00
    6     Soft Drink          1       Rs. 40.00
    -----------------------------------------
    Subtotal      : Rs. 200.00
    Tax (5%)      : Rs. 10.00
    Grand Total   : Rs. 210.00
    ========================================
    Thank you! Visit again.

------------------------------------------------------------------------

## 🛠️ **Installation & Usage**

### 1️⃣ Clone the repo

``` sh
git clone https://github.com/yourusername/Khana-Khazana-2.0.git
```

### 2️⃣ Compile

``` sh
gcc restaurant.c -o restaurant
```

### 3️⃣ Run

``` sh
./restaurant
```

------------------------------------------------------------------------

## 📂 **Project Structure**

    📁 Khana-Khazana-2.0
    │── restaurant.c        # Main source code
    │── README.md           # Documentation

------------------------------------------------------------------------

## 🔧 **Core Functions**

-   🍔 `initMenu()` -- loads predefined items\
-   📋 `displayMenu()` -- prints menu\
-   ➕ `addItemToOrder()` -- adds items to order\
-   👀 `viewCurrentOrder()` -- displays current order\
-   🧾 `generateBill()` -- calculates bill + GST\
-   🗑️ `clearOrder()` -- resets order

------------------------------------------------------------------------

## 🎓 **What You Learn**

-   Structs\
-   Arrays\
-   Functions\
-   Modular design\
-   Billing logic\
-   Input validation\
-   Console UI building

------------------------------------------------------------------------

## 🌟 **Future Enhancements**

-   💾 Save bills to text files\
-   ❌ Remove items from order\
-   🛂 Admin mode (edit menu)\
-   🏷️ Discounts & offers\
-   🎨 Color UI

------------------------------------------------------------------------

## 👨‍💻 **Author**

**SUKHAMITRA MARTHA**\
B.Tech CSE -- 1st Semester\
Project: Restaurant Management System in C
