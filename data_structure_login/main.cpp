#include <bits/stdc++.h>
using namespace std;

void login();
void signup();
void forgot();
void search_tickyet_status();
void runTicketSystem();
string username, username1, username2, password, password1;
int mainBalance = 100;
struct Node{
int ticketNumber;
float ticketPrice;
Node* next;
};

Node* head = nullptr;

void displayMenu() {
    cout << "===== Train Ticket Reservation System =====" << endl;
    cout << "1. View Available Tickets" << endl;
    cout << "2. Buy Ticket" << endl;
    cout << "3. Refund Ticket" << endl;
    cout << "4. Search Ticket status" << endl;
    cout << "5. Check Balance " << endl;
    cout << "6. Add Balance " << endl;
    cout << "7. Exit" << endl;
}

void viewAvailableTickets() {
    Node* current = head;
    int count = 0;

    cout << "Available Tickets:" << endl;

    while (current != nullptr) {
        cout << "Ticket " << current->ticketNumber << ": TK" << fixed << setprecision(2) << current->ticketPrice << endl;
        current = current->next;
        count++;
    }
    if (count == 0) {
        cout << "No tickets available." << endl << endl;
    }
}
bool confirmPurchase() {
    char response;
    cout << "Do you want to proceed with the purchase? (y/n): ";
    cin >> response;

    return (response == 'y' || response == 'Y');
}
void addBalance ()
{
            int add;
            cout << "Enter the amount you want to add : ";
            cin >> add;
            mainBalance+=add;
            cout << "money added successfull." << endl;
            cout << "Your current balance is = " << mainBalance << endl <<endl;
}



void buyTicket() {
    if (head != nullptr) {
        int numTicketsToBuy;
        cout << "Enter the number of tickets you want to buy: ";
        cin >> numTicketsToBuy;


        int totalAmount;
        if (numTicketsToBuy <= 0 || numTicketsToBuy > 4) {
            cout << "Invalid number of tickets." << endl;
            cout << "One person can buy four tickets." << endl;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < numTicketsToBuy && temp != nullptr; ++i) {
            if (confirmPurchase()) {


                cout << "You have purchased Ticket " << temp->ticketNumber << " for TK" << fixed << setprecision(2) << temp->ticketPrice << endl;

                totalAmount += temp->ticketPrice;

                Node* nextTicket = temp->next;
                delete temp;
                temp = nextTicket;
            } else {
                cout << "Purchase canceled." << endl;
                break;
            }
        }

        head = temp;
        totalAmount = totalAmount+20;
        cout << "Total amount to be paid(extra 20 tk for vat,tax): " << fixed << setprecision(2) << totalAmount<< " TK" << endl;
        int paidAmount;
        /*cout << "Enter the amount: ";
        cin >> paidAmount;*/
        cout << "if you want to paid money press 1 : ";
        int z;
        cin >> z;
        if (z==1){

        if (mainBalance>=totalAmount)
        {
            cout << "Payment successful. Happy journey " << endl << endl;
            mainBalance-= totalAmount;
        }

        else {

            cout << "Insufficient payment. Ticket purchase unsuccessful." << endl;
            cout << "Please add : " << totalAmount-mainBalance << " TK" << endl;
             cout << "if you want to add money to your account press 1 or exit for 0 : ";

            int b;
            cin >> b;
            if (b==1)
            {
                addBalance();
            }
            else if (b==0)
            {
                exit (0);
            }
            else
            {
                cout << "Invalid choice." << endl<< endl;
            }
        }

        }
        else
        {
            cout << "Invalid choice." << endl<< endl ;
        }




    } else {
        cout << "Sorry, no tickets available." << endl<< endl;
        cout << "please try to next day";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void checkBalance()
{
    cout << "Your current balance is = " << mainBalance << endl;
}

int refundTicket(){
    cout << "Enter the ticket number you want to refund: ";
    int refundNumber;
    cin >> refundNumber;

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->ticketNumber != refundNumber) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous != nullptr) {
            previous->next = current->next;
        } else {
            head = current->next;
        }

        cout << "Ticket " << current->ticketNumber << " refunded for TK" << fixed << setprecision(2) << current->ticketPrice << endl;

        current->next = head;
        head = current;
    } else {
        cout << "Ticket not found or already refunded." << endl;
    }


    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
void initializeTickets(int numTickets, float price) {
    for (int i = 1; i <= numTickets; ++i) {
        Node* newNode = new Node;
        newNode->ticketNumber = i;
        newNode->ticketPrice = price;
        newNode->next = head;
        head = newNode;
    }
}

void search_tickyet_status() {
    cout << "Enter the ticket number to check its status: ";
    int ticketToCheck;
    cin >> ticketToCheck;

    Node* current = head;
    bool found = true;

    while (current != nullptr) {
        if (current->ticketNumber == ticketToCheck) {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found) {
        if (current->next == nullptr) {
            cout << "Ticket " << ticketToCheck << ": Already purchased" << endl;
        } else {

            cout << "Ticket " << ticketToCheck << ": Available" << endl;
        }
    } else {
        cout << "Ticket not found." << endl;
    }

    runTicketSystem();
}



void runTicketSystem() {
    int option;

    initializeTickets(20, 150);

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                viewAvailableTickets();
                break;
            case 2:
                buyTicket();
                break;
            case 3:
                refundTicket();
                break;
            case 4:
                search_tickyet_status();
                break;
            case 5:
                checkBalance();
                break;
            case 6 :
                addBalance();
                break;
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (option != 4);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void login()
{
    cout << "       Login system        " << endl;
    cout << "Enter username: ";
    cin >> username1;
    cout << "Enter password: ";
    cin >> password1;

    if (username == username1 && password == password1)
    {
        cout << "Login successful." << endl;
        cout << endl ;
        runTicketSystem();

    }
    else
    {
        int y;
        cout << "Login unsuccessful." << endl;
        cout << "if you are not signup press '1', or forgot password, press '3': " ;

        cin >> y;
        if (y == 3)
        {
            forgot();
        }
        else if (y==1)
        {
            signup();
        }
        else
        {
            cout << "Invalid choice.\n" << endl;
        }
        cout << endl;
    }
}

void signup()
{
    cout << "Create username and password " << endl;
    cout << "Enter username : ";
    cin >> username;
    cout << "Enter password : ";
    cin >> password;
    cout << endl;
    login();
}

void forgot()
{
    cout << "Enter the username : ";
    cin >> username2;
    if (username == username2)
    {
        signup();
    }
    else
    {
        cout << "Your username is wrong." << endl;
        cout << "Please contact the Admin panel." << endl;
        cout << "Admin name: Tauhid Musa Rieon" << endl;
        cout << "Email: tauhidmusarieon01@gmail.com" << endl;
        cout << "Thanks." << endl;
        cout << endl;
    }
}



int main()
{
    int n,payment;
    cout << "Welcome to the ticket system : " << endl;
    cout << "1. Sign up\n2. Login\n3. Exit\nEnter your option : ";
    cin >> n;

    switch (n)
    {
    case 1:
        signup();
        break;
    case 2:
        login();
        break;
    case 3:
        cout << "Exiting the program. thanks!" << endl;
        return 0;
    default:
        cout << "Invalid option. Please choose a valid option." << endl;
    }

    return 0;

}
