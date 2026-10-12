
#include <iostream>
#include <string>
using namespace std;

// Order details
string item1 = "Cake";
string item2 = "Biscuits";
string item3 = "Bread";

float price1 = 500;
float price2 = 200;
float price3 = 100;

// Customer order details
int q1 = 0, q2 = 0, q3 = 0;
float orderTotal = 0;
float orderPrice1 = 0, orderPrice2 = 0, orderPrice3 = 0;
bool orderPlaced = false;

// Function to display menu
void showMenu()
{
    cout << "\n----- BAKERY MENU -----\n";
    cout << "1. " << item1 << " - Rs. " << price1 << endl;
    cout << "2. " << item2 << " - Rs. " << price2 << endl;
    cout << "3. " << item3 << " - Rs. " << price3 << endl;
}

// Function for admin
void adminMenu()
{
    int choice;

    do
    {
        cout << "\n----- ADMIN PANEL -----\n";
        cout << "1. View Menu\n";
        cout << "2. Change Menu Item and Price\n";
        cout << "3. View Customer Order and Bill\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            showMenu();
        }
        else if (choice == 2)
        {
            int item;

            cout << "Enter item number (1-3): ";
            cin >> item;

            if (item == 1)
            {
                cout << "Enter new item name: ";
                cin >> ws;
                getline(cin, item1);

                cout << "Enter new price: ";
                cin >> price1;
            }
            else if (item == 2)
            {
                cout << "Enter new item name: ";
                cin >> ws;
                getline(cin, item2);

                cout << "Enter new price: ";
                cin >> price2;
            }
            else if (item == 3)
            {
                cout << "Enter new item name: ";
                cin >> ws;
                getline(cin, item3);

                cout << "Enter new price: ";
                cin >> price3;
            }
            else
            {
                cout << "Invalid item number!\n";
                continue;
            }

            cout << "Menu updated successfully!\n";
        }
        else if (choice == 3)
        {
            if (orderPlaced)
            {
                cout << "\n----- CUSTOMER ORDER -----\n";

                if (q1 > 0)
                    cout << item1 << " x " << q1
                         << " = Rs. " << q1 * orderPrice1 << endl;

                if (q2 > 0)
                    cout << item2 << " x " << q2
                         << " = Rs. " << q2 * orderPrice2 << endl;

                if (q3 > 0)
                    cout << item3 << " x " << q3
                         << " = Rs. " << q3 * orderPrice3 << endl;

                cout << "Total Bill: Rs. " << orderTotal << endl;
            }
            else
            {
                cout << "No customer order placed yet.\n";
            }
        }
        else if (choice == 0)
        {
            cout << "Admin logged out.\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

// Function for customer
void customerMenu()
{
    int choice, quantity;

    q1 = 0;
    q2 = 0;
    q3 = 0;
    orderTotal = 0;
    orderPlaced = false;

    do
    {
        showMenu();

        cout << "\nEnter item number to add to cart\n";
        cout << "Enter 0 to checkout: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity > 0)
            {
                q1 = q1 + quantity;
                cout << "Item added to cart!\n";
            }
            else
            {
                cout << "Quantity must be greater than zero.\n";
            }
        }
        else if (choice == 2)
        {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity > 0)
            {
                q2 = q2 + quantity;
                cout << "Item added to cart!\n";
            }
            else
            {
                cout << "Quantity must be greater than zero.\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity > 0)
            {
                q3 = q3 + quantity;
                cout << "Item added to cart!\n";
            }
            else
            {
                cout << "Quantity must be greater than zero.\n";
            }
        }
        else if (choice != 0)
        {
            cout << "Invalid item number!\n";
        }

    } while (choice != 0);

    if (q1 + q2 + q3 > 0)
    {
        // Save prices at the time of ordering
        orderPrice1 = price1;
        orderPrice2 = price2;
        orderPrice3 = price3;

        orderTotal = (q1 * orderPrice1)
                   + (q2 * orderPrice2)
                   + (q3 * orderPrice3);

        orderPlaced = true;

        cout << "\n===== FINAL BILL =====\n";

        if (q1 > 0)
            cout << item1 << " x " << q1
                 << " = Rs. " << q1 * orderPrice1 << endl;

        if (q2 > 0)
            cout << item2 << " x " << q2
                 << " = Rs. " << q2 * orderPrice2 << endl;

        if (q3 > 0)
            cout << item3 << " x " << q3
                 << " = Rs. " << q3 * orderPrice3 << endl;

        cout << "----------------------\n";
        cout << "Total Bill: Rs. " << orderTotal << endl;
        cout << "Thank you for shopping!\n";
    }
    else
    {
        cout << "Your cart is empty.\n";
    }
}

// Main function
int main()
{
    int user;

    do
    {
        cout << "\n===== BAKERY MANAGEMENT SYSTEM =====\n";
        cout << "1. Admin Login\n";
        cout << "2. Customer\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> user;

        if (user == 1)
        {
            adminMenu();
        }
        else if (user == 2)
        {
            customerMenu();
        }
        else if (user == 0)
        {
            cout << "Thank you for visiting!\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (user != 0);

    return 0;
}
