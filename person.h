#include <iostream>
#include <unordered_map>

class person
{
    std::string full_Name;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone_Number;
    std::unordered_map<int, std::string> person_detail_pair;

public:
    person(){};
    person(std::string full_Name);
    void set_Address(std::string address);
    void set_City(std::string city);
    void set_State(std::string state);
    void set_Zip(std::string zip);
    void set_Phone_Number(std::string phone_Number);
    std::unordered_map<int, std::string> get_Mapping_Details();
    void set_Mapping_Details(std::unordered_map<int, std::string> detail_pair)
    {
        this -> person_detail_pair = detail_pair;
    }
};

person::person(std::string full_Name)
{
    this->full_Name = full_Name;
    person_detail_pair[0] = this -> full_Name;
}

void person::set_Address(std::string address)
{
    this->address = address;
    person_detail_pair[1] = this -> address;
}

void person::set_City(std::string city)
{
    this->city = city;
     person_detail_pair[2] = this -> city;
}

void person::set_State(std::string state)
{
    this->state = state;
    person_detail_pair[3] = this -> state;
}

void person::set_Zip(std::string zip)
{
    this->zip = zip;
    person_detail_pair[4] = this -> zip;
}

void person::set_Phone_Number(std::string phone_Number)
{
    this->phone_Number = phone_Number;
    person_detail_pair[5] = this -> phone_Number;
}

std::unordered_map<int, std::string> person::get_Mapping_Details()
{
    return person_detail_pair;
}