#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class item
{
public:
    string name;
    int quantity;
    double price;

    bool login()
    {

        string user, pass;
        cout << "========Login Page=======" << endl;
        cout << "Enter username : " << endl;
        cin >> user;
        cout << "Enter Password : " << endl;
        cin >> pass;
        if (user == "admin" && pass == "1234")
        {
            cout << "Login Successfully!";
            return true;
        }
        else
        {
            cout << "Inavalid password!";
            return false;
        }
    }

    void additem(item inventory[], int &count)
    {
        cout << "Enter name : ";
        cin.ignore();
        getline(cin, inventory[count].name);

        cout << "Enter quantity : ";
        cin >> inventory[count].quantity;

        cout << "Enter price : ";
        cin >> inventory[count].price;

        count++;
        cout << "Item added successfully!\n";
        for (int i = 0; i < count; i++)
        {
            double total = inventory[i].quantity * inventory[i].price;
            cout << "Total Amount : " << total << endl;
        }
    }

    void searchItem(item inventory[], int count)
    {
        if (count == 0)
        {
            cout << "No items to search.\n";
            return;
        }

        string searchName;
        cout << "Enter item name to search: ";
        cin.ignore();
        getline(cin, searchName);
        for (int i = 0; i < count; i++)
        {
            if (inventory[i].name == searchName)
            {
                cout << "\nItem found!\n";
                cout << "Name  : " << inventory[i].name << endl;
                cout << "Qty   : " << inventory[i].quantity << endl;
                cout << "Price : " << inventory[i].price << endl;

                double total = inventory[i].quantity * inventory[i].price;
                cout << "Total Amount : " << total << endl;

                return;
            }
        }
        cout << "Item not found!\n";
    }
    void updateItem(item inventory[], int count)
    {
        if (count == 0)
        {
            cout << "No items to update.\n";
            return;
        }

        string updateName;
        cout << "Enter item name to update: ";
        cin.ignore();
        getline(cin, updateName);

        for (int i = 0; i < count; i++)
        {
            if (inventory[i].name == updateName)
            {
                cout << "Enter new quantity: ";
                cin >> inventory[i].quantity;
                cout << "Enter new price: ";
                cin >> inventory[i].price;

                cout << "Item updated successfully!\n";
                return;
            }
        }

        cout << "Item not found!\n";
    }

    void deleteItem(item inventory[], int &count)
    {
        if (count == 0)
        {
            cout << "No items to delete.\n";
            return;
        }

        string deleteName;
        cout << "Enter item name to delete: ";
        cin.ignore();
        getline(cin, deleteName);

        for (int i = 0; i < count; i++)
        {
            if (inventory[i].name == deleteName)
            {

                for (int j = i; j < count - 1; j++)
                {
                    inventory[j] = inventory[j + 1];
                }
                count--;
                cout << "Item deleted successfully!\n";
                return;
            }
        }

        cout << "Item not found!\n";
    }

    void display(item inventory[], int count)
    {
        if (count == 0)
        {
            cout << "No items found.\n";
            return;
        }

        cout << "\n--- INVENTORY LIST ---\n";
        for (int i = 0; i < count; i++)
        {
            cout << "Name  : " << inventory[i].name << endl;
            cout << "Qty   : " << inventory[i].quantity << endl;
            cout << "Price : " << inventory[i].price << endl;
            cout << "------------------------" << endl;
        }
    }
};

int main()
{

    item inventory[50];
    int count = 0;
    item obj;
    int choice;

    if (!obj.login())
    {
        return 0;
    }

    cout << "\nWelcome to Inventory System!\n";

    while (true)
    {
        cout << "\n====== INVENTORY MENU ======\n";
        cout << "1. Add Item\n";
        cout << "2. Search Item\n";
        cout << "3. Update Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Display All Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.additem(inventory, count);
            break;
        case 2:
            obj.searchItem(inventory, count);
            break;
        case 3:
            obj.updateItem(inventory, count);
            break;
        case 4:
            obj.deleteItem(inventory, count);
            break;
        case 5:
            obj.display(inventory, count);
            break;
        case 6:
            cout << "Thankyou for visiting....";
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }
}