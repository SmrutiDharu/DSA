#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ExpenseNode {
public:
    float amount;
    string description;
    string date;
    string category;
    ExpenseNode* next;

    ExpenseNode(float amt, const string& desc, const string& dt, const string& cat)
        : amount(amt), description(desc), date(dt), category(cat), next(nullptr) {}
};

class ExpenseTracker {
private:
    ExpenseNode* head;

public:
    ExpenseTracker() : head(nullptr) {}

    void addExpense(float amount, const string& description, const string& date, const string& category) {
        ExpenseNode* newExpense = new ExpenseNode(amount, description, date, category);
        if (!head) {
            head = newExpense;
        } else {
            ExpenseNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newExpense;
        }
    }

    void displayExpenses() {
        ExpenseNode* current = head;
        if (!current) {
            cout << "No expenses recorded." << endl;
            return;
        }
        while (current) {
            cout << "Date: " << current->date
                 << ", Amount: " << fixed << setprecision(2) << current->amount
                 << ", Description: " << current->description
                 << ", Category: " << current->category << endl;
            current = current->next;
        }
    }

    void searchByDateRange(const string& startDate, const string& endDate) {
        ExpenseNode* current = head;
        bool found = false;

        cout << "Expenses from " << startDate << " to " << endDate << ":" << endl;

        while (current) {
            if (current->date >= startDate && current->date <= endDate) {
                cout << "Date: " << current->date
                     << ", Amount: " << fixed << setprecision(2) << current->amount
                     << ", Description: " << current->description
                     << ", Category: " << current->category << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No expenses found in the specified date range." << endl;
        }
    }

    ~ExpenseTracker() {
        ExpenseNode* current = head;
        while (current) {
            ExpenseNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

void displayMenu() {
    cout << "\n=== Expense Tracker Menu ===" << endl;
    cout << "1. Add Expense" << endl;
    cout << "2. Display Expenses" << endl;
    cout << "3. Search by Date Range" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    ExpenseTracker tracker;
    int choice;

    do {
        displayMenu();
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                float amount;
                string description, date, category;
                cout << "Enter amount: ";
                cin >> amount;
                cin.ignore();
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter date (YYYY-MM-DD): ";
                getline(cin, date);
                cout << "Enter category: ";
                getline(cin, category);
                tracker.addExpense(amount, description, date, category);
                break;
            }
            case 2:
                tracker.displayExpenses();
                break;
            case 3: {
                string startDate, endDate;
                cout << "Enter start date (YYYY-MM-DD): ";
                cin >> startDate;
                cout << "Enter end date (YYYY-MM-DD): ";
                cin >> endDate;
                tracker.searchByDateRange(startDate, endDate);
                break;
            }
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
