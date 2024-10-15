#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<int> Records;

class RecordsManager
{
private:
    std::fstream _file;
    std::string _filename;

public:
    RecordsManager(std::string filename) : _filename(filename) {}

    void read(Records &records)
    {
        _file.open(_filename, std::ios::in);
        if (_file.is_open())
        {
            try
            {
                std::string line;
                while (std::getline(_file, line))
                {
                    try
                    {
                        records.push_back(std::stoi(line));
                    }
                    catch (const std::out_of_range &e)
                    {
                        _file.close();
                        throw std::runtime_error("Out of range when reading the file: " + std::string(e.what()));
                    }
                    catch (const std::invalid_argument &e)
                    {
                        _file.close();
                        throw std::runtime_error("Wrong argument when reading the file: " + std::string(e.what()));
                    }
                }
                _file.close();
            }
            catch (...)
            {
                _file.close();
                throw;
            }
        }
        else
        {
            throw std::runtime_error("Unable to open file: " + _filename);
        }
    }
};

int main()
{
    try
    {
        RecordsManager receordM("test_clean.txt");
        RecordsManager receordM("test_corrupt1.txt");
        RecordsManager receordM("test_corrupt2.txt");
        Records myRecords;

        receordM.read(myRecords);

        int sum = 0;
        for (int i = 0; i < myRecords.size(); i++)
        {
            sum += myRecords[i];
        }
        std::cout << sum << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}