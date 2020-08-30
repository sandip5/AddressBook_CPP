#include <iostream>
#include <string>
#include <vector>
#include "person.h"

namespace address_book_spc
{
    class address_book
    {
        std::vector<person_spc::person> person_Contact_Book;
    public:
        void add_Person();
        void set_Person_Details_In_Book(std::vector<person_spc::person> &person_Contact_Book);
        std::vector<person_spc::person> get_Person_Details_From_Book();
        void display_Person_Details();
    };

    void address_book::set_Person_Details_In_Book(std::vector<person_spc::person> &person_Contact_Book)
    {
        this -> person_Contact_Book = person_Contact_Book;
    }

    std::vector<person_spc::person> address_book::get_Person_Details_From_Book()
    {
        return person_Contact_Book;
    }

    void address_book::add_Person()
    {
        std::cout << "Enter How Many Person Contact Details You Want To Add: ";
        int number_Of_Person;
        std::cin >> number_Of_Person;

        std::vector<person_spc::person> person_Contact_Book;

        for(int person_Counter = 0; person_Counter < number_Of_Person; person_Counter++)
        {
            if(person_Counter > 0)
            {
                std::cout << "Enter Next Person Details: " << std::endl;
            }

            std::cin.ignore(1,'\n');
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
            long zip;
            std::cout << "Enter Zip Of Person: ";
            std::cin >> zip;
            long phone_Number;
            std::cout << "Enter Mobile Number Of Person: ";
            std::cin >> phone_Number;

            person_spc::person person(full_Name, address, city, state, zip, phone_Number);

            person_Contact_Book.push_back(person);
        }

        address_book::set_Person_Details_In_Book(person_Contact_Book);
    }

    void address_book::display_Person_Details()
    {
        for(person_spc::person display : person_Contact_Book)
        {
            std::cout << "*---------------Address Book All Person Details---------------------*" << std::endl;
            std::cout << "Person Full Name: " << display.get_Full_Name() << std::endl;
            std::cout << "Person Address: " << display.get_Address() << std::endl;
            std::cout << "Person City: " << display.get_City() << std::endl;
            std::cout << "Person State: " << display.get_State() << std::endl;
            std::cout << "Person Zip: " << display.get_Zip() << std::endl;
            std::cout << "Person Phone Number: " << display.get_Phone_Number() << std::endl;
        }
    }
}