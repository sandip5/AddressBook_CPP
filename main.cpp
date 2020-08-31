#include "address_book.h"

address_book_spc::address_book g_Address_Book;

void show_Welcome_Msg();
void display_Menu();
int select_Menu_Option();
void perform_Selected_Operation();
void register_Person_To_Address_Book();
void display_Persons_From_Address_Book();
void edit_Person_Details_In_Address_Book();
person_spc::person take_Input_As_Person_Details();
void delete_Person_From_Address_Book();

int main()
{
    show_Welcome_Msg();
    perform_Selected_Operation();

    return 0;
}

void show_Welcome_Msg()
{
    std::cout << "Welcome To Address Book Problem..." << std::endl;
}

void display_Menu()
{
    std::cout << "Select Option Which Operation Do You Want To Perform..." << std::endl;
    std::cout << "1. Add New Person Details, To Save Details Of Person In Address Book Directory.\n" <<
                 "2. Display All Person Details From Address Book Directory.\n" <<
                 "3. Edit Person Details In Address Book Directory.\n" <<
                 "4. Delete Person From Address Book Directory By Using Person Full Name.\n"
                "5. Close Address Book." << std::endl;
}

int select_Menu_Option()
{
    std::cout << "Enter Option Which You Want To Perform..." << std::endl;
    int select_Menu_Option;
    std::cin >> select_Menu_Option;
    std::cin.get();
    return select_Menu_Option;
}

void perform_Selected_Operation()
{
    bool is_Start = false;

    enum select_choice
    {
        ADD_NEW_PERSON,
        DISPLAY_ALL_PERSON_DETAILS,
        EDIT_PERSON_DETAILS,
        DELETE_PERSON,
        EXIT
    };

    while(!is_Start)
    {
        display_Menu();
        int selected_Menu_Option = select_Menu_Option();

        switch (selected_Menu_Option - 1)
        {
            case select_choice::ADD_NEW_PERSON:
                register_Person_To_Address_Book();
                break;
            case select_choice::DISPLAY_ALL_PERSON_DETAILS:
                display_Persons_From_Address_Book();
                break;
            case select_choice::EDIT_PERSON_DETAILS:
                edit_Person_Details_In_Address_Book();
                break;
            case select_choice::DELETE_PERSON:
                delete_Person_From_Address_Book();
                break;    
            case select_choice::EXIT:
                is_Start = true;
                break;
            default:
                std::cout << "Invalid Selection Of Menu. Please Try With Valid Menu Option..." << std::endl;
                break;
        }
    }
}

void register_Person_To_Address_Book()
{
    person_spc::person person_Details = take_Input_As_Person_Details();

    g_Address_Book.add_Person(person_Details);
}

person_spc::person take_Input_As_Person_Details()
{
    std::cout << "Enter Full Name Of Person: ";
    std::string full_Name;
    std::getline (std::cin, full_Name);

    std::cout << "Enter Address Of Person: ";
    std::string address;
    std::getline (std::cin, address);
    
    std::string city;
    std::cout << "Enter City Of Person: ";
    std::getline (std::cin, city);
    
    std::string state;
    std::cout << "Enter State Of Person: ";
    std::getline (std::cin, state);
    
    std::string zip;
    std::cout << "Enter Zip Of Person: ";
    std::getline (std::cin, zip);
   
    std::string phone_Number;
    std::cout << "Enter Mobile Number Of Person: ";
    std::getline (std::cin, phone_Number);

    person_spc::person person_Details(full_Name, address, city, state, zip, phone_Number);

    return person_Details;
}

void display_Persons_From_Address_Book()
{
    g_Address_Book.display_Person_Details();
}
void edit_Person_Details_In_Address_Book()
{
    std::cout << "1. Edit Address\n2. Edit City\n3. Edit State\n4. Edit Zip\n5. Edit Phone Number " << std::endl;
    std::cout << "Select Choice Of Which Person's Details You Want To Edit: " << std::endl;
                
    int select;
    std::cin >> select;
    std::cin.get();
    
    g_Address_Book.edit_Person_Details("Sandip Singh", select);
}

void delete_Person_From_Address_Book()
{
    g_Address_Book.delete_Person("Sandip Singh");
}