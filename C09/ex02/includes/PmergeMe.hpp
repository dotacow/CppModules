#pragma once
#include <set>
#include <vector>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		template <typename T>
		void mergeInsertionSort(T &container)
		{
			if (container.size() <= 1)
				return;
			std::vector<int> larger, smaller;
			for (unsigned int i = 0; i + 1 < container.size(); i += 2)
			{
				if (container[i] > container[i + 1])
				{
					larger.push_back(container[i]);
					smaller.push_back(container[i + 1]);
				}
				else
				{
					larger.push_back(container[i + 1]);
					smaller.push_back(container[i]);
				}
			}
			if (container.size() % 2 != 0)
				smaller.push_back(container.back());
			T sortedLarger(larger.begin(), larger.end());
			mergeInsertionSort(sortedLarger);//T(n) = T(n/2) + O(n/2) + O(n/2 * log n) ~=> O(n log n)
			std::multiset<int> result = std::multiset<int>(sortedLarger.begin(), sortedLarger.end());
			for (unsigned int i = 0; i < smaller.size(); ++i)
				result.insert(smaller[i]);// O(log n)
			container = T(result.begin(), result.end());
		}
	public:
		template <typename T>
		PmergeMe(T &container) { mergeInsertionSort(container); };
		~PmergeMe();
};