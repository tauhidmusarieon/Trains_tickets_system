#include <bits/stdc++.h>
using namespace std;

void login();
void signup();
void forgot();

string username, username1, username2, password, password1;

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
    cout << "4. Exit" << endl;
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
        cout << "No tickets available." << endl;
    }
}
bool confirmPurchase() {
    char response;
    cout << "Do you want to proceed with the purchase? (y/n): ";
    cin >> response;

    return (response == 'y' || response == 'Y');
}
void buyTicket() {
    if (head != nullptr) {
        int numTicketsToBuy;
        cout << "Enter the number of tickets you want to buy: ";
        cin >> numTicketsToBuy;

        if (numTicketsToBuy <= 0) {
            cout << "Invalid number of tickets." << endl;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < numTicketsToBuy && temp != nullptr; ++i) {
            if (confirmPurchase()) {
                cout << "You have purchased Ticket " << temp->ticketNumber << " for TK" << fixed << setprecision(2) << temp->ticketPrice << endl;
                Node* nextTicket = temp->next;
                delete temp;
                temp = nextTicket;
            } else {
                cout << "Purchase canceled." << endl;
                break;
            }
        }

        head = temp;
    } else {
        cout << "Sorry, no tickets available." << endl;
        cout << "please try to next day";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int refundTicket(){

}

void runTicketSystem() {
    int option;

    //initializeTickets(20, 150.0);

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
                cout << "Exiting program. Goodbye!" << endl;
                break;
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
    int n;
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
