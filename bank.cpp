#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    long accountNumber;
    double balance;

public:
    BankAccount(const std::string& name, long accNumber, double initialBalance)
        : accountHolderName(name), accountNumber(accNumber), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit of $" << amount << " successful. New balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds." << std::endl;
        }
    }

    void displayBalance() const {
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }
};

int main() {
    BankAccount myAccount("Santhosh", 123456789, 1000.0);

    int choice;
    double amount;

    do {
        // Display menu
        std::cout << "\nBanking System Menu:\n";
        std::cout << "1. Display Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myAccount.displayBalance();
                break;
            case 2:
                std::cout << "Enter the deposit amount: $";
                std::cin >> amount;
                myAccount.deposit(amount);
                break;
            case 3:
                std::cout << "Enter the withdrawal amount: $";
                std::cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
