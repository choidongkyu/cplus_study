#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		auto keyiter = keys.begin();
		auto valueiter = values.begin();
		size_t size = keys.size() < values.size() ? keys.size() : values.size();
		for (size_t i = 0; i < size; ++i)
		{
			m.insert(std::pair<K, V>(*keyiter, *valueiter));
			++valueiter;
			++keyiter;
		}
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(m.size());
		auto iter = m.begin();
		for (size_t i = 0; i < m.size(); ++i)
		{
			v.push_back(iter->first);
			++iter;
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		v.reserve(m.size());
		auto iter = m.begin();
		for (size_t i = 0; i < m.size(); ++i)
		{
			v.push_back(iter->second);
			++iter;
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		rv.reserve(v.size());
		auto iter = v.end();
		for (size_t i = 0; i < v.size(); ++i)
		{
			--iter;
			rv.push_back(*iter);
		}
		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		size_t size = v1.size() + v2.size();
		combined.reserve(size);
		size_t i = 0;
		for (auto iter = v1.begin(); iter != v1.end(); ++iter)
		{
			auto finditer = find(v1.begin(), iter, *iter);
			if (finditer == iter)
			{
				combined.push_back(*iter);
			}
		}


		for (auto iter = v2.begin(); iter != v2.end(); ++iter)
		{
			auto finditer = find(v1.begin(), v1.end(), *iter);
			if (finditer == v1.end())
			{
				combined.push_back(*iter);
			}
		}
		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;
		for (auto iter = m1.begin(); iter != m1.end(); ++iter)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}

		for (auto iter = m2.begin(); iter != m2.end(); ++iter)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		auto iter = v.begin();
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (i == v.size() - 1)
			{
				os << *iter;
			}
			else
			{
				os << *iter << ", ";
			}
			++iter;

		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (auto iter = m.begin(); iter != m.end(); ++iter)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}
		return os;
	}
}