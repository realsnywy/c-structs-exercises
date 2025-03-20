//! Question 4: Inventory Control with Pointers
// Create a struct called StockItem, containing:
//* Item name (string up to 50 characters)
//* Code (integer)
//* Quantity (integer)
//* Unit price (float)
// Use dynamic allocation to register up to 10 items, calculate the total inventory value, and display the results. Finally, free the memory.

#include <stdio.h>
#include <stdlib.h>

// Lowkey, I was passing out while making this.
typedef struct
{
    char itemName[50];
    int code;
    int quantity;
    float unitPrice;
} StockItem;

StockItem *createStockItem()
{
    StockItem *si = (StockItem *)malloc(sizeof(StockItem));
    return si;
}

void registerStockItem(StockItem *si)
{
    printf("Enter the item's name: ");
    scanf("%s", si->itemName);
    printf("Enter the item's code: ");
    scanf("%d", &si->code);
    printf("Enter the item's quantity: ");
    scanf("%d", &si->quantity);
    printf("Enter the item's unit price: ");
    scanf("%f", &si->unitPrice);
}

void displayStockItem(StockItem *si)
{
    printf("Item name: %s\n", si->itemName);
    printf("Code: %d\n", si->code);
    printf("Quantity: %d\n", si->quantity);
    printf("Unit price: %.2f\n", si->unitPrice);
}

float totalInventoryValue(StockItem *si)
{
    return si->quantity * si->unitPrice;
}

int main()
{
    StockItem *stockItems[10];
    float totalValue = 0;

    for (int i = 0; i < 10; i++)
    {
        stockItems[i] = createStockItem();
        printf("Registering item %d\n", i + 1);
        registerStockItem(stockItems[i]);
        totalValue += totalInventoryValue(stockItems[i]);
    }

    printf("Total inventory value: %.2f\n", totalValue);

    for (int i = 0; i < 10; i++)
    {
        free(stockItems[i]);
    }

    return 0;
}