#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

namespace easy_csv_spc
{
    bool fexists(std::string file_path)
    {
        std::ifstream ifile(file_path);
        return ifile.good();
    }

    void easy_csv(std::string file_path, std::string header_csv[], int total_Header_Fields)
    {
        if(!fexists(file_path))
        {
            std::ofstream out_file;
            out_file.open(file_path, std::ios::out);
            for(int i = 0; i < total_Header_Fields; i++)
            {
                if(i < total_Header_Fields - 1)
                {
                    out_file << header_csv[i] << ',';
                }
                else
                {
                    out_file << header_csv[i] << ',' << std::endl;
                }
            }
        }
    }
    
    template<typename T>
    void convert_object_to_csv(std::string file_path, std::vector<T> data, int number_Of_Header_Fields)
    {
        std::fstream fileStream;
        fileStream.open(file_path, std::ios::out | std::ios::app);
        if(fileStream.is_open())
        {
            for (T itr : data)
            {
                for (int i = 0; i < number_Of_Header_Fields; i++)
                {
                    if(i < 1 )
                    {
                        fileStream << itr.get_Mapping_Details().at(i) << ',';
                    }


                    if((i < number_Of_Header_Fields - 1) && (i > 0) )
                    {
                        fileStream << itr.get_Mapping_Details().at(i) << ',';
                    }

                    if ((i > number_Of_Header_Fields - 2) && (i < number_Of_Header_Fields))
                    {
                        fileStream << itr.get_Mapping_Details().at(i) << std::endl;
                    }
                }
            }
        }
    }

    std::vector<std::unordered_map<int, std::string>> convert_csv_to_object()
    {
        std::fstream fin; 
        fin.open("address_book.csv", std::ios::in);
        
        std::vector<std::unordered_map<int, std::string>> row; 
        std::string line, word, temp; 

        int j = 0;
        while (fin >> temp) 
        {   
            getline(fin, line); 
            
            std::stringstream s(line);
            std::unordered_map<int, std::string> mapping_details; 
            if(j > 0)
            {
                int i = 0;
                while (getline(s, word, ',')) 
                {
                    mapping_details[i] = word;
                    i++;
                }
                row.push_back(mapping_details);
            }
            j++;
        }

        return row;
    }
}
