#include "Lab2.h"
#include <string>
#include <iomanip>
namespace lab2
{
    std::string trash;
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        int num;
        out << std::setfill(' ') << std::setw(12) << "oct"
            << std::setw(11) << "dec"
            << std::setw(9) << "hex" << std::endl;
        out << std::setfill('-') << std::setw(13) << ' '
            << std::setw(11) << ' '
            << std::setw(8) << "" << std::endl;

        while (true)
        {
            in >> num;

            if (in.fail())
            {
                in.clear();
                in >> trash;
            }
            else
            {
                out << std::setfill(' ') << std::setw(12) << std::oct << num
                    << std::setw(11) << std::dec << num
                    << std::setw(9) << std::uppercase << std::hex << num << std::endl;
            }

            if (in.eof()) {
                break;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        float num;
        float max;
        bool chk_first = true;
        while (true)
        {
            in >> num;

            if (chk_first)
            {
                out << "chk_first =  " << num << std::endl;
                max = num;
                chk_first = false;
            }

            if (num > max && !in.fail())
            {
                max = num;
                out << "max = " << num << std::endl;
            }

            if (in.fail())
            {
                in.clear();
                in >> trash;
            }
            else
            {
                out << std::setw(5) << std::setfill('.') << ""
                    << std::setw(15) << std::showpos << std::fixed << std::setprecision(3) << std::internal << num << std::endl;
            }

            if (in.eof())
            {
                out << std::setw(5) << std::setfill('.') << std::left << "max:"
                    << std::setw(15) << std::showpos << std::fixed << std::setprecision(3) << std::internal << max << std::endl;
                break;
            }
        }
    }
}