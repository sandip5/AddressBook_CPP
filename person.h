#include <iostream>

class person
{
    std::string full_Name;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone_Number;

public:
    person(){};
    person(std::string full_Name);
    std::string get_Full_Name();
    void set_Address(std::string address);
    std::string get_Address();
    void set_City(std::string city);
    std::string get_City();
    void set_State(std::string state);
    std::string get_State();
    void set_Zip(std::string zip);
    std::string get_Zip();
    void set_Phone_Number(std::string phone_Number);
    std::string get_Phone_Number();  
};

person::person(std::string full_Name)
{
    this -> full_Name = full_Name;
    this -> address = address;
    this -> city = city;
    this -> state = state;
    this -> zip = zip;
    this -> phone_Number = phone_Number;
}        

std::string person::get_Full_Name()
{
    return full_Name;
}

void person::set_Address(std::string address)
{
    this -> address = address;
}

std::string person::get_Address()
{
    return address;
}

void person::set_City(std::string city)
{
    this -> city = city;
}

std::string person::get_City()
{
    return city;
}

void person::set_State(std::string state)
{
    this -> state = state;
}

std::string person::get_State()
{
    return state;
}

void person::set_Zip(std::string zip)
{
    this -> zip = zip;
}

std::string person::get_Zip()
{
    return zip;
}

void person::set_Phone_Number(std::string phone_Number)
{
    this -> phone_Number = phone_Number;
}

std::string person::get_Phone_Number()
{
    return phone_Number;
}