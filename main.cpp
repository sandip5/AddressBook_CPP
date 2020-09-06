#include <stdlib.h>
#include "address_book.h"

address_book g_Address_Book;

std::string file_Path ="address_book.csv";
std::string header[] = {"Full Name", "Address", "City", "State", "Zip", "Phone Number"};
int total_Header_Fields = 6;

void show_Welcome_Msg();
void display_Menu();
int select_Menu_Option();
void perform_Selected_Operation();
void register_Person_To_Address_Book();
void display_Persons_From_Address_Book();
void edit_Person_Details_In_Address_Book();
person take_Input_As_Person_Details(std::string full_Name);
void delete_Person_From_Address_Book();
std::string take_Input_As_Person_Name();
void sort_Address_Book_Records();
void search_Person_By_City_And_State();
void search_Person_By_City_Or_State();
void check_File_Exist_If_Not_Then_Create_With_Header();
void write_Address_Book_Details_Into_File();
void read_Csv_Data_Store_Into_Address_Book();

int main()
{
    show_Welcome_Msg();
    check_File_Exist_If_Not_Then_Create_With_Header();
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
    std::cout << "1. Add New Person Details, To Save Details Of Person In Address Book Directory.\n"
              << "2. Display All Person Details From Address Book Directory.\n"
              << "3. Edit Person Details In Address Book Directory.\n"
              << "4. Delete Person From Address Book Directory By Using Person Full Name.\n"
              << "5. Sort All Person Record According To Alphabetical Order In Address Book.\n"
              << "6. Search Person Record By City And State Both.\n"
              << "7. Search Person Record By City Or State Both.\n"
              << "8. Clear Screen\n"
              << "9. Write Address Book Details Into CSV File.\n"
              << "10. Read CSV File\n"
              << "11. Close Address Book." << std::endl;
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
        SORT_PERSON_NAME,
        SEARCH_CITY_AND_STATE,
        SEARCH_CITY_OR_STATE,
        CLEAR_SCREEN,
        WRITE_INTO_FILE,
        READ_FILE,
        EXIT
    };

    while (!is_Start)
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
        case select_choice::SORT_PERSON_NAME:
            sort_Address_Book_Records();
            break;
        case select_choice::SEARCH_CITY_AND_STATE:
            search_Person_By_City_And_State();
            break;
        case select_choice::SEARCH_CITY_OR_STATE:
            search_Person_By_City_Or_State();
            break;
        case select_choice::CLEAR_SCREEN:
            system("cls");
            break;
        case select_choice::WRITE_INTO_FILE:
            write_Address_Book_Details_Into_File();
            break;
        case select_choice::READ_FILE:
            read_Csv_Data_Store_Into_Address_Book();
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
    std::cout << "Enter How Many Person Contact Details You Want To Add: ";
    int number_Of_Person;
    std::cin >> number_Of_Person;
    std::cin.get();

    for (int person_Counter = 0; person_Counter < number_Of_Person; person_Counter++)
    {
        if (person_Counter > 0)
            std::cout << "\nEnter New Person Details..." << std::endl;

        std::string full_Name = take_Input_As_Person_Name();
        bool check_Duplicates = g_Address_Book.check_Duplicate_Entry(full_Name);
        if (check_Duplicates)
        {
            person person_Details = take_Input_As_Person_Details(full_Name);
            g_Address_Book.add_Person(person_Details);
        }
        else
        {
            std::cout << "Try Again With Unique Name..." << std::endl;
            person_Counter = person_Counter - 1;
        }
    }
}

std::string take_Input_As_Person_Name()
{
    std::cout << "Enter Full Name Of Person: ";
    std::string full_Name;
    std::getline(std::cin, full_Name);

    return full_Name;
}

person take_Input_As_Person_Details(std::string full_Name)
{
    person person_Details(full_Name);

    std::cout << "Enter Address Of Person: ";
    std::string address;
    std::getline(std::cin, address);
    person_Details.set_Address(address);

    std::string city;
    std::cout << "Enter City Of Person: ";
    std::getline(std::cin, city);
    person_Details.set_City(city);

    std::string state;
    std::cout << "Enter State Of Person: ";
    std::getline(std::cin, state);
    person_Details.set_State(state);

    std::string zip;
    std::cout << "Enter Zip Of Person: ";
    std::getline(std::cin, zip);
    person_Details.set_Zip(zip);

    std::string phone_Number;
    std::cout << "Enter Mobile Number Of Person: ";
    std::getline(std::cin, phone_Number);
    person_Details.set_Phone_Number(phone_Number);

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

    std::string edit_Field;
    std::cout << "Enter Full Name Of Person, For Whom You Want To Edit Details..." << std::endl;
    std::getline(std::cin, edit_Field);

    g_Address_Book.edit_Person_Details(edit_Field, select);
}

void delete_Person_From_Address_Book()
{
    std::string full_Name;
    std::cout << "Enter Full Name Of Person, For Whom You Want To Delete..." << std::endl;
    std::getline(std::cin, full_Name);

    g_Address_Book.delete_Person(full_Name);
}

void sort_Address_Book_Records()
{
    std::cout << "Enter Selection According To Which Person(s) Detail Or Field You Want To Sort." << std::endl;
    std::cout << "1. Sort Address Book Record According To Person(s) Name.\n"
              << "2. Sort Address Book Record According To Person(s) City.\n"
              << "3. Sort Address Book Record According To Person(s) State.\n"
              << "4. Sort Address Book Record According To Person(s) Zip.\n"
              << std::endl;

    int choice;
    std::cin >> choice;
    std::cin.get();

    enum sort_choice
    {
        SORT_BY_PERSON_NAME,
        SORT_BY_CITY,
        SORT_BY_STATE,
        SORT_BY_ZIP
    };

    switch (choice - 1)
    {
    case sort_choice::SORT_BY_PERSON_NAME:
        g_Address_Book.sort_As_Per_Name();
        break;
    case sort_choice::SORT_BY_CITY:
        g_Address_Book.sort_As_Per_City();
        break;
    case sort_choice::SORT_BY_STATE:
        g_Address_Book.sort_As_Per_State();
        break;
    case sort_choice::SORT_BY_ZIP:
        g_Address_Book.sort_As_Per_Zip();
        break;
    default:
        std::cout << "Invalid Input, Try Again..." << std::endl;
        break;
    }
}

void search_Person_By_City_And_State()
{
    std::cout << "Enter City Name: ";
    std::string city_Name;
    std::getline(std::cin, city_Name);

    std::cout << "Enter State Name: ";
    std::string state_Name;
    std::getline(std::cin, state_Name);

    g_Address_Book.search_Person_BY_City_And_State(city_Name, state_Name);
}

void search_Person_By_City_Or_State()
{
    std::cout << "Enter City Or State Name: ";
    std::string city_Or_State_Name;
    std::getline(std::cin, city_Or_State_Name);

    g_Address_Book.search_Person_BY_City_Or_State(city_Or_State_Name);
}

void check_File_Exist_If_Not_Then_Create_With_Header()
{
    g_Address_Book.if_Csv_File_Not_Found_Create_New_File(file_Path, header, total_Header_Fields);
}

void write_Address_Book_Details_Into_File()
{
    g_Address_Book.write_Into_Csv_From_Contact_Book(file_Path, total_Header_Fields);
}

void read_Csv_Data_Store_Into_Address_Book()
{
    g_Address_Book.read_Csv_File();
}