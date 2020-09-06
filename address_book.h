#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "easy_csv.h"

class address_book
{
    std::vector<person> person_Contact_Book;

    enum field_Name
    {
        FULL_NAME,
        ADDRESS,
        CITY,
        STATE,
        ZIP,
        PHONE_NUMBER
    };

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
    void if_Csv_File_Not_Found_Create_New_File(std::string file_path, std::string header_csv[], int total_Header_Fields)
    {
        easy_csv_spc::easy_csv(file_path, header_csv, total_Header_Fields);
    }

    void write_Into_Csv_From_Contact_Book(std::string file_Path, int total_Header_Fields)
    {
        easy_csv_spc::convert_object_to_csv(file_Path, person_Contact_Book, total_Header_Fields);
    }

    void read_Csv_File()
    {
        std::vector<std::unordered_map<int, std::string>> mapping_details = easy_csv_spc::convert_csv_to_object();

        for (int i = 0; i < mapping_details.size(); i++)
        {
            person p;
            p.set_Mapping_Details(mapping_details[i]);
            person_Contact_Book.push_back(p);
        }
    }
};

void address_book::add_Person(person person_Details)
{
    this->person_Contact_Book.push_back(person_Details);
}

void address_book::display_Person_Details()
{
    std::cout << "\n*---------------Address Book All Person Details---------------------*\n" << std::endl;

    for (person display : person_Contact_Book)
    {
        std::cout << "Person Full Name   : " << display.get_Mapping_Details().at(field_Name::FULL_NAME) << std::endl;
        std::cout << "Person Address     : " << display.get_Mapping_Details().at(field_Name::ADDRESS) << std::endl;
        std::cout << "Person City        : " << display.get_Mapping_Details().at(field_Name::CITY) << std::endl;
        std::cout << "Person State       : " << display.get_Mapping_Details().at(field_Name::STATE) << std::endl;
        std::cout << "Person Zip         : " << display.get_Mapping_Details().at(field_Name::ZIP) << std::endl;
        std::cout << "Person Phone Number: " << display.get_Mapping_Details().at(field_Name::PHONE_NUMBER) << "\n"<< std::endl;
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
        if (person_Details.get_Mapping_Details().at(field_Name::FULL_NAME) == full_Name)
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
        if (person_Details.get_Mapping_Details().at(field_Name::FULL_NAME) == full_Name)
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
        if (person_Contact_Book[position].get_Mapping_Details().at(field_Name::FULL_NAME) == full_Name)
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
            if (person_Contact_Book[person_Index].get_Mapping_Details().at(field_Name::FULL_NAME) >
                person_Contact_Book[person_Index + 1].get_Mapping_Details().at(field_Name::FULL_NAME))
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
            if (person_Contact_Book[person_Index].get_Mapping_Details().at(field_Name::CITY) >
                person_Contact_Book[person_Index + 1].get_Mapping_Details().at(field_Name::CITY))
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
            if (person_Contact_Book[person_Index].get_Mapping_Details().at(field_Name::STATE) >
                person_Contact_Book[person_Index + 1].get_Mapping_Details().at(field_Name::STATE))
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
            if (person_Contact_Book[person_Index].get_Mapping_Details().at(field_Name::ZIP) >
                person_Contact_Book[person_Index + 1].get_Mapping_Details().at(field_Name::ZIP))
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
        if (it.get_Mapping_Details().at(field_Name::CITY) == city && it.get_Mapping_Details().at(field_Name::STATE) == state)
            std::cout << "Person Name: " << it.get_Mapping_Details().at(field_Name::FULL_NAME) << " "
                      << "City: " << it.get_Mapping_Details().at(field_Name::CITY) << " "
                      << "State: " << it.get_Mapping_Details().at(field_Name::STATE) << "Zip: " << it.get_Mapping_Details().at(field_Name::ZIP) << " "
                      << "Phone Number" << it.get_Mapping_Details().at(field_Name::PHONE_NUMBER) << std::endl;
    }
}

void address_book::search_Person_BY_City_Or_State(std::string city_Or_State_Name)
{
    for (person it : person_Contact_Book)
    {
        if (it.get_Mapping_Details().at(field_Name::CITY) == city_Or_State_Name || it.get_Mapping_Details().at(field_Name::STATE) == city_Or_State_Name)
            std::cout << "Person Name: " << it.get_Mapping_Details().at(field_Name::FULL_NAME) << " "
                      << "City: " << it.get_Mapping_Details().at(field_Name::CITY) << " "
                      << "State: " << it.get_Mapping_Details().at(field_Name::STATE) << "Zip: " << it.get_Mapping_Details().at(field_Name::ZIP) << " "
                      << "Phone Number" << it.get_Mapping_Details().at(field_Name::PHONE_NUMBER) << std::endl;
    }
}
