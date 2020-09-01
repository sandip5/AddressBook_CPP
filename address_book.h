#include <iostream>
#include <string>
#include <vector>
#include "person.h"

class address_book
{
    std::vector<person> person_Contact_Book;

public:
    void add_Person(person person_Details);
    void display_Person_Details();
    void edit_Person_Details(std::string full_name, int select);
    void delete_Person(std::string full_Name);
    bool check_Duplicate_Entry(std::string full_Name);
    void sort_As_Per_Name();
    void sort_As_Per_City();
    void sort_As_Per_State();
    void sort_As_Per_Zip();
    void search_Person_BY_City_And_State(std::string city, std::string state);
    void search_Person_BY_City_Or_State(std::string city_Or_State_Name);
};

void address_book::add_Person(person person_Details)
{
    this->person_Contact_Book.push_back(person_Details);
}

void address_book::display_Person_Details()
{
    for (person display : person_Contact_Book)
    {
        std::cout << "*---------------Address Book All Person Details---------------------*" << std::endl;
        std::cout << "Person Full Name   : " << display.get_Full_Name() << std::endl;
        std::cout << "Person Address     : " << display.get_Address() << std::endl;
        std::cout << "Person City        : " << display.get_City() << std::endl;
        std::cout << "Person State       : " << display.get_State() << std::endl;
        std::cout << "Person Zip         : " << display.get_Zip() << std::endl;
        std::cout << "Person Phone Number: " << display.get_Phone_Number() << std::endl;
    }
}

void address_book::edit_Person_Details(std::string full_Name, int select)
{
    enum edit_person
    {
        EDIT_ADDRESS,
        EDIT_CITY,
        EDIT_STATE,
        EDIT_ZIP,
        EDIT_PHONE_NUMBER
    };

    int position = 0;
    for (person person_Details : person_Contact_Book)
    {
        if (person_Details.get_Full_Name() == full_Name)
        {
            std::cout << "Enter New Detail Which You Want To Replace With Previous Detail: " << std::endl;
            std::string edit_Statement;
            std::getline(std::cin, edit_Statement);

            switch (select - 1)
            {
            case edit_person::EDIT_ADDRESS:
            {
                this->person_Contact_Book[position].set_Address(edit_Statement);
                break;
            }
            case edit_person::EDIT_CITY:
            {
                this->person_Contact_Book[position].set_City(edit_Statement);
                break;
            }
            case edit_person::EDIT_STATE:
            {
                this->person_Contact_Book[position].set_State(edit_Statement);
                break;
            }
            case edit_person::EDIT_ZIP:
            {
                this->person_Contact_Book[position].set_Zip(edit_Statement);
                break;
            }
            case edit_person::EDIT_PHONE_NUMBER:
            {
                this->person_Contact_Book[position].set_Phone_Number(edit_Statement);
                break;
            }
            default:
                std::cout << "Invalid Selection..." << std::endl;
            }
        }
        position++;
    }
}

void address_book::delete_Person(std::string full_Name)
{
    int position = 0;
    for (person person_Details : person_Contact_Book)
    {
        if (person_Details.get_Full_Name() == full_Name)
        {
            this->person_Contact_Book.erase(this->person_Contact_Book.begin() + position);
        }
        position++;
    }
}

bool address_book::check_Duplicate_Entry(std::string full_Name)
{
    int position = 0;
    for (person person_Details : person_Contact_Book)
    {
        if (person_Contact_Book[position].get_Full_Name() == full_Name)
        {
            std::cout << "Duplicate Entry Not Allowed..." << std::endl;
            return false;
        }
        position++;
    }

    return true;
}

void address_book::sort_As_Per_Name()
{
    person temp;

    for (int iterate_In_Book = 0; iterate_In_Book < person_Contact_Book.size(); iterate_In_Book++)
    {
        int flag = 0;
        for (int person_Index = 0; person_Index < person_Contact_Book.size() - 1 - iterate_In_Book; person_Index++)
        {
            if (person_Contact_Book[person_Index].get_Full_Name() >
                person_Contact_Book[person_Index + 1].get_Full_Name())
            {
                temp = person_Contact_Book[person_Index];
                person_Contact_Book[person_Index] = person_Contact_Book[person_Index + 1];
                person_Contact_Book[person_Index + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void address_book::sort_As_Per_City()
{
    person temp;

    for (int iterate_In_Book = 0; iterate_In_Book < person_Contact_Book.size(); iterate_In_Book++)
    {
        int flag = 0;
        for (int person_Index = 0; person_Index < person_Contact_Book.size() - 1 - iterate_In_Book; person_Index++)
        {
            if (person_Contact_Book[person_Index].get_City() >
                person_Contact_Book[person_Index + 1].get_City())
            {
                temp = person_Contact_Book[person_Index];
                person_Contact_Book[person_Index] = person_Contact_Book[person_Index + 1];
                person_Contact_Book[person_Index + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void address_book::sort_As_Per_State()
{
    person temp;

    for (int iterate_In_Book = 0; iterate_In_Book < person_Contact_Book.size(); iterate_In_Book++)
    {
        int flag = 0;
        for (int person_Index = 0; person_Index < person_Contact_Book.size() - 1 - iterate_In_Book; person_Index++)
        {
            if (person_Contact_Book[person_Index].get_State() >
                person_Contact_Book[person_Index + 1].get_State())
            {
                temp = person_Contact_Book[person_Index];
                person_Contact_Book[person_Index] = person_Contact_Book[person_Index + 1];
                person_Contact_Book[person_Index + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void address_book::sort_As_Per_Zip()
{
    person temp;

    for (int iterate_In_Book = 0; iterate_In_Book < person_Contact_Book.size(); iterate_In_Book++)
    {
        int flag = 0;
        for (int person_Index = 0; person_Index < person_Contact_Book.size() - 1 - iterate_In_Book; person_Index++)
        {
            if (person_Contact_Book[person_Index].get_Zip() >
                person_Contact_Book[person_Index + 1].get_Zip())
            {
                temp = person_Contact_Book[person_Index];
                person_Contact_Book[person_Index] = person_Contact_Book[person_Index + 1];
                person_Contact_Book[person_Index + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void address_book::search_Person_BY_City_And_State(std::string city, std::string state)
{
    for (person it : person_Contact_Book)
    {
        if (it.get_City() == city && it.get_State() == state)
            std::cout << "Person Name: " << it.get_Full_Name() << " "
                      << "City: " << it.get_City() << " "
                      << "State: " << it.get_State() << "Zip: " << it.get_Zip() << " "
                      << "Phone Number" << it.get_Phone_Number() << std::endl;
    }
}

void address_book::search_Person_BY_City_Or_State(std::string city_Or_State_Name)
{
    for (person it : person_Contact_Book)
    {
        if (it.get_City() == city_Or_State_Name || it.get_State() == city_Or_State_Name)
            std::cout << "Person Name: " << it.get_Full_Name() << " "
                      << "City: " << it.get_City() << " "
                      << "State: " << it.get_State() << "Zip: " << it.get_Zip() << " "
                      << "Phone Number" << it.get_Phone_Number() << std::endl;
    }
}
