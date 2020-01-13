#include "Lab2.h"
#include <string>
#include <iomanip>

namespace lab2
{
	std::string Trash;
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;
		out << std::setfill(' ') << std::setw(12) << "oct"
			<< std::setw(11) << "dec"
			<< std::setw(9) << "hex" << std::endl;
		out << std::setfill('-') << std::setw(13) << ' '
			<< std::setw(11) << ' '
			<< std::setw(8) << "" << std::endl;

		while (true)
		{
			in >> number;

			if (in.fail())
			{
				in.clear();
				in >> Trash;
			}
			else
			{
				out << std::setfill(' ') << std::setw(12) << std::oct << number
					<< std::setw(11) << std::dec << number
					<< std::setw(9) << std::uppercase << std::hex << number << std::endl;
			}

			if (in.eof()) {
				break;
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float number;
		float max;
		bool bChk_first = true;
		while (true)
		{
			in >> number;

			if (bChk_first)
			{
				max = number;
				bChk_first = false;
			}

			if (number > max && !in.fail())
			{
				max = number;
			}

			if (in.fail())
			{
				in.clear();
				in >> Trash;
			}
			else
			{
				out << std::setw(5) << std::setfill(' ') << ""
					<< std::setw(15) << std::showpos << std::fixed << std::setprecision(3) << std::internal << number << std::endl;
			}

			if (in.eof())
			{
				out << std::setw(5) << std::setfill(' ') << std::left << "max:"
					<< std::setw(15) << std::showpos << std::fixed << std::setprecision(3) << std::internal << max << std::endl;
				break;
			}
		}
	}
}