#include <iostream>
#include <string>
#include <vector>
#include "person.h"

namespace address_book_spc
{
    class address_book
    {
        person_spc::person person_Details;

    public:
        void add_Person(person_spc::person &person_Details);
        void set_Person_Details_In_Book(person_spc::person &person_Details);
        person_spc::person get_Person_Details_From_Book();
        void display_Person_Details();
        void edit_Person_Details(std::string full_name, int select);
        void edit_Address(std::string edit_Statement);
        void edit_City(std::string edit_Statement);
        void edit_State(std::string edit_Statement);
        void edit_Zip(std::string edit_Statement);
        void edit_Phone_Number(std::string edit_Statement);
        void delete_Person(std::string full_Name);
    };

    void address_book::set_Person_Details_In_Book(person_spc::person &person_Details)
    {
        this -> person_Details = person_Details;
    }

    person_spc::person address_book::get_Person_Details_From_Book()
    {
        return person_Details;
    }

    void address_book::add_Person(person_spc::person &person_Details)
    {
        address_book::set_Person_Details_In_Book(person_Details);
    }

    void address_book::display_Person_Details()
    {
        std::cout << "*---------------Address Book All Person Details---------------------*" << std::endl;
        std::cout << "Person Full Name   : " << person_Details.get_Full_Name() << std::endl;
        std::cout << "Person Address     : " << person_Details.get_Address() << std::endl;
        std::cout << "Person City        : " << person_Details.get_City() << std::endl;
        std::cout << "Person State       : " << person_Details.get_State() << std::endl;
        std::cout << "Person Zip         : " << person_Details.get_Zip() << std::endl;
        std::cout << "Person Phone Number: " << person_Details.get_Phone_Number() << std::endl;
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

        if(person_Details.get_Full_Name() == full_Name)
        {
            std::cout << "Enter New Detail Which You Want To Replace With Previous Detail: " << std::endl;
            std::string edit_Statement;
            std::getline(std::cin, edit_Statement);

            switch (select - 1)
            {
                case edit_person::EDIT_ADDRESS:
                {
                    edit_Address(edit_Statement);
                    break;
                }
                case edit_person::EDIT_CITY:
                {
                    edit_City(edit_Statement);
                    break;
                }
                case edit_person::EDIT_STATE:
                {
                    edit_State(edit_Statement);
                    break;
                }
                case edit_person::EDIT_ZIP:
                {
                    edit_Zip(edit_Statement);
                    break;
                }
                case edit_person::EDIT_PHONE_NUMBER:
                {      
                    edit_Phone_Number(edit_Statement);
                    break;
                }
                default:
                    std::cout << "Invalid Selection..." << std::endl;
                }
            }
        }

    void address_book::edit_Address(std::string edit_Statement)
    {
        person_Details.set_Address(edit_Statement);
        std::cout << "New Address Of " << person_Details.get_Full_Name() << " Is " << person_Details.get_Address() << std::endl;
    }

    void address_book::edit_City(std::string edit_Statement)
    {
        person_Details.set_City(edit_Statement);
        std::cout << "New City Of " << person_Details.get_Full_Name() << " Is " << person_Details.get_City() << std::endl;
    }
    
    void address_book::edit_State(std::string edit_Statement)
    {
        person_Details.set_State(edit_Statement);
        std::cout << "New State Of " << person_Details.get_Full_Name() << " Is " << person_Details.get_State() << std::endl;
    }

    void address_book::edit_Zip(std::string edit_Statement)
    {
        person_Details.set_Zip(edit_Statement);
        std::cout << "New Zip Of " << person_Details.get_Full_Name() << " Is " << person_Details.get_Zip() << std::endl;
    }

    void address_book::edit_Phone_Number(std::string edit_Statement)
    {
        person_Details.set_Phone_Number(edit_Statement);
        std::cout << "New Address Of " << person_Details.get_Full_Name() << " Is " << person_Details.get_Phone_Number() << std::endl;
    }

    void address_book::delete_Person(std::string full_Name)
    {
        if(person_Details.get_Full_Name() == full_Name)
        {
            person_spc::person empty_Person_Details;
            address_book::set_Person_Details_In_Book(empty_Person_Details);
        }
    }           
}