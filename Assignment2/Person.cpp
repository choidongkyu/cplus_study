#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mName(name)
		, mWeight(weight)
	{
	}

	Person::~Person()
	{
	}

	Person::Person(const Person* person)
		: mName(person->mName)
		, mWeight(person->mWeight)
	{
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
	const void Person::Printf() const
	{
		if (this == NULL)
		{
			std::cout << "NULL" << std::endl;
			return;
		}
		std::cout <<"person name = "<< mName << std::endl;
	}
}