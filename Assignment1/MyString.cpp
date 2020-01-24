#include "MyString.h"
using namespace std;

namespace assignment1
{
	MyString::MyString(const char* s)
		: mSize(Strlen(s) + 1)
	{
		mString = new char[mSize];
		Memcpy(mString, s, mSize);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
	{
		mString = new char[mSize];
		Memcpy(mString, other.mString, mSize);
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return Strlen(mString);
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		size_t size = Strlen(s);
		char* tmp;
		tmp = new char[mSize + size];
		Memcpy(tmp, mString, Strlen(mString));
		Memcpy(tmp + Strlen(mString), s, size + 1);
		delete[] mString;
		mSize += size;
		mString = new char[mSize];
		Memcpy(mString, tmp, mSize);
		delete[] tmp;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString result(mString);
		result.Append(other.mString);
		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		const char* copy = mString;
		const char* input = s;
		int i = 0;
		size_t k;
		while (*copy != '\0')
		{
			if (*copy == *input)
			{
				for (k = 1; k < Strlen(input); k++)
				{
					++i;
					++copy;
					if (*copy != input[k])
					{
						break;
					}
				}
				if (input[k] == '\0')
				{
					return i - (Strlen(s) - 1);
				}
			}
			++copy;
			++i;
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		const char* copy = mString + Strlen(mString) - 1;
		int i = Strlen(mString) - 1;
		while (copy != mString)
		{
			if (*copy == *(s + Strlen(s) - 1))
			{
				const char* input = s + Strlen(s) - 1;
				while (input != s)
				{
					--input;
					--copy;
					--i;
					if (*input != *copy)
					{
						break;
					}
				}
				if (input == s)
				{
					return i;
				}
			}
			--i;
			--copy;
		}

		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		const char* copy = mString;
		mSize = mSize + Strlen(s);
		char* tmp = new char[mSize];
		for (size_t i = 0; i < mSize; i++)
		{
			if ((i % 2 == 0 && *copy != '\0') || *s == '\0')
			{
				*(tmp + i) = *copy;
				++copy;
			}
			else if (i % 2 != 0 || *copy == '\0')
			{
				*(tmp + i) = *s;
				++s;
			}
		}
		delete[] mString;
		mString = tmp;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index >= mSize)
		{
			return false;
		}
		mSize -= 1;
		while (*(mString + index) != '\0')
		{
			*(mString + index) = *(mString + index + 1);
			++index;
		}

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		int size = totalLength - Strlen(mString);
		if (size <= 0)
		{
			return;
		}
		mSize += static_cast<size_t>(size);
		char* tmp = new char[mSize];
		for (size_t i = 0; i < mSize; i++)
		{
			if (i < static_cast<size_t>(size))
			{
				*(tmp + i) = ' ';
			}
			else
			{
				*(tmp + i) = *(mString++);
			}
		}
		mString -= (mSize - size);
		delete[] mString;
		mString = tmp;
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		int size = totalLength - Strlen(mString);
		if (size <= 0)
		{
			return;
		}
		mSize += static_cast<size_t>(size);
		char* tmp = new char[mSize];
		for (size_t i = 0; i < mSize; i++)
		{
			if (i < static_cast<size_t>(size))
			{
				*(tmp + i) = c;
			}
			else
			{
				*(tmp + i) = *(mString++);
			}
		}
		mString -= (mSize - size);
		delete[] mString;
		mString = tmp;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		int size = totalLength - Strlen(mString);
		if (size <= 0)
		{
			return;
		}
		mSize += static_cast<size_t>(size);
		char* tmp = new char[mSize];
		for (size_t i = 0; i < mSize; i++)
		{
			if (i < mSize - size - 1)
			{
				*(tmp + i) = *(mString++);
			}
			else
			{
				*(tmp + i) = '-';
			}
		}
		tmp[mSize - 1] = '\0';
		mString -= (mSize - size - 1);
		delete[] mString;
		mString = tmp;
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		int size = totalLength - Strlen(mString);
		if (size <= 0)
		{
			return;
		}
		mSize += static_cast<size_t>(size);
		char* tmp = new char[mSize];
		for (size_t i = 0; i < mSize; i++)
		{
			if (i < mSize - size - 1)
			{
				*(tmp + i) = *(mString++);
			}
			else
			{
				*(tmp + i) = c;
			}
		}
		tmp[mSize - 1] = '\0';
		mString -= (mSize - size - 1);
		delete[] mString;
		mString = tmp;
	}

	void MyString::Reverse()
	{
		size_t size = Strlen(mString);
		char* start = mString;
		char* end = mString + Strlen(mString) - 1;
		char tmp;
		for (size_t i = 0; i < size / 2; i++)
		{
			tmp = *start;
			*start = *end;
			*end = tmp;
			++start;
			--end;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return Strcmp(mString, rhs.mString);
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (Memcmp(mString, rhs.mString, mSize))
		{
			return *this;
		}
		mSize = rhs.mSize;
		delete[] mString;
		mString = new char[mSize];
		Memcpy(mString, rhs.mString, mSize);
		return *this;
	}

	void MyString::ToLower()
	{
		char* copy = mString;
		while (*copy != '\0')
		{
			if (*copy >= 'A' && *copy <= 'Z')
			{
				*copy += 32;
			}
			++copy;
		}
	}

	void MyString::ToUpper()
	{
		char* copy = mString;
		while (*copy != '\0')
		{
			if (*copy >= 'a' && *copy <= 'z')
			{
				*copy -= 32;
			}
			++copy;
		}
	}

	bool MyString::Strcmp(const char* str1, const char* str2) const
	{
		while (*str1 != '\0' && *str1 == *str2)
		{
			++str1;
			++str2;
		}
		if (*str1 == *str2)
		{
			return true;
		}

		return false;
	}
	size_t MyString::Strlen(const char* s) const
	{
		size_t cnt = 0;
		while (*s != '\0')
		{
			++s;
			++cnt;
		}
		return cnt;
	}

	void MyString::Memcpy(char* dst, const char* src, size_t count)
	{
		for (size_t i = 0; i < count; i++)
		{
			*(dst + i) = *(src + i);
		}
	}

	bool MyString::Memcmp(const char* src1, const char* src2, size_t size) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (*(src1 + i) != *(src2 + i))
			{
				return false;
			}
		}
		return true;
	}
}