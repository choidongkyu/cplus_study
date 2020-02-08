#pragma once
#include <iostream>
#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		~Person();
		Person(const Person* person);

		const std::string& GetName() const;
		unsigned int GetWeight() const;
		const void Printf() const;

	private:
		std::string mName;
		unsigned int mWeight;
	};
}