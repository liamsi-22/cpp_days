#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

void PmergeMe::ser_number(long int &num){
    vector.push_back(num);
    deque.push_back(num);
}

PmergeMe::PmergeMe(const PmergeMe& other):vector(other.vector), deque(other.deque), vectorSortTime_(other.vectorSortTime_), dequeSortTime_(other.dequeSortTime_){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other)
	{
		vector = other.vector;
		deque = other.deque;
		vectorSortTime_ = other.vectorSortTime_;
		dequeSortTime_ = other.dequeSortTime_;
	}
	return (*this);
}

bool PmergeMe::vecSortCheck()
{
	for (size_t i = 0; i < vector.size() - 1; i++)
	{
		if (vector[i] > vector[i + 1])
			return (false);
	}
	return (true);
}

bool PmergeMe::dequeSortCheck()
{
	for (size_t i = 0; i < deque.size() - 1; i++)
	{
		if (deque[i] > deque[i + 1])
			return (false);
	}
	return (true);
}

pairVectorContainer createPairs(std::vector<int>& vectorIntSeq)
{
	pairVectorContainer pairVec;
	std::vector<int>::iterator it = vectorIntSeq.begin();
	while (it != vectorIntSeq.end() && (it + 1) != vectorIntSeq.end())
	{
		std::pair<int, int> pair;
		pair.first = *it;
		it = vectorIntSeq.erase(it);
		pair.second = *it;
		it = vectorIntSeq.erase(it);
		if (pair.second < pair.first)
			std::swap(pair.first, pair.second);
		pairVec.push_back(pair);
	}
	return pairVec;
}

pairdequeContainer createPairs(std::deque<int>& dequeIntSeq)
{
	pairdequeContainer pairVec;
	std::deque<int>::iterator it = dequeIntSeq.begin();
	while (it != dequeIntSeq.end() && (it + 1) != dequeIntSeq.end())
	{
		std::pair<int, int> pair;
		pair.first = *it;
		it = dequeIntSeq.erase(it);
		pair.second = *it;
		it = dequeIntSeq.erase(it);
		if (pair.second < pair.first)
			std::swap(pair.first, pair.second);
		pairVec.push_back(pair);
	}
	return pairVec;
}

pairVectorContainer mergePairs(pairVectorContainer a, pairVectorContainer b)
{
	pairVectorContainer c;

	while(!a.empty() && !b.empty())
	{
		if (a[0].second > b[0].second)
		{
			c.push_back(b[0]);
			b.erase(b.begin());
		}
		else
		{
			c.push_back(a[0]);
			a.erase(a.begin());
		}
	}
	while (!a.empty())
	{
		c.push_back(a[0]);
		a.erase(a.begin());
	}
	
	while (!b.empty())
	{
		c.push_back(b[0]);
		b.erase(b.begin());
	}
	return c;
}

pairdequeContainer mergePairs(pairdequeContainer a, pairdequeContainer b)
{
	pairdequeContainer c;

	while(!a.empty() && !b.empty())
	{
		if (a[0].second > b[0].second)
		{
			c.push_back(b[0]);
			b.erase(b.begin());
		}
		else
		{
			c.push_back(a[0]);
			a.erase(a.begin());
		}
	}
	while (!a.empty())
	{
		c.push_back(a[0]);
		a.erase(a.begin());
	}
	
	while (!b.empty())
	{
		c.push_back(b[0]);
		b.erase(b.begin());
	}
	return c;
}

pairVectorContainer mergesortPairs(pairVectorContainer& pairVec, int n)
{
	if (n == 1)
		return pairVec;

	pairVectorContainer arr1;
	for (int i = 0; i < n / 2; i++)
		arr1.push_back(pairVec[i]);

	pairVectorContainer arr2;
	for (int i = n / 2; i < n; i++)
		arr2.push_back(pairVec[i]);

	arr1 = mergesortPairs(arr1, arr1.size());
	arr2 = mergesortPairs(arr2, arr2.size());

	return mergePairs(arr1, arr2);
}

pairdequeContainer mergesortPairs(pairdequeContainer& pairdeque, int n)
{
	if (n == 1)
		return pairdeque;

	pairdequeContainer arr1;
	for (int i = 0; i < n / 2; i++)
		arr1.push_back(pairdeque[i]);

	pairdequeContainer arr2;
	for (int i = n / 2; i < n; i++)
		arr2.push_back(pairdeque[i]);

	arr1 = mergesortPairs(arr1, arr1.size());
	arr2 = mergesortPairs(arr2, arr2.size());

	return mergePairs(arr1, arr2);
}

std::vector<int> extractChain(const std::vector<std::pair<int,int> >& pairVec, int chainType)
{
    std::vector<int> chain;
	std::vector<std::pair<int,int> >::const_iterator it;
    for (it = pairVec.begin(); it != pairVec.end(); ++it)
    {
        if (chainType == 1)
            chain.push_back(it->first);
        else
            chain.push_back(it->second);
    }
    return chain;
}

std::deque<int> extractChain(const std::deque<std::pair<int,int> >& pairdeque, int chainType)
{
    std::deque<int> chain;
	std::deque<std::pair<int,int> >::const_iterator it;
    for (it = pairdeque.begin(); it != pairdeque.end(); ++it)
    {
        if (chainType == 1)
            chain.push_back(it->first);
        else
            chain.push_back(it->second);
    }
    return chain;
}

void binaryInsert(int pend, std::vector<int>& main, int high)
{
	std::vector<int>::iterator pos = main.begin();

	int low = 0;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (main[mid] == pend)
		{
			main.insert(pos + mid, pend);
			return ;
		}
		else if (main[mid] > pend)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (low >= (int)main.size())
    	main.push_back(pend);
	else if (pend < main[low])
		main.insert(pos + low, pend);
	else
		main.insert(pos + low + 1, pend);
	return ;
}

void binaryInsert(int pend, std::deque<int>& main, int high)
{
	std::deque<int>::iterator pos = main.begin();

	int low = 0;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (main[mid] == pend)
		{
			main.insert(pos + mid, pend);
			return ;
		}
		else if (main[mid] > pend)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (low >= (int)main.size())
    	main.push_back(pend);
	else if (pend < main[low])
		main.insert(pos + low, pend);
	else
		main.insert(pos + low + 1, pend);
	return ;
}

size_t jacobsthalIndexGen(size_t current, int iteration)
{
	size_t n_2 = 0;
	size_t n_1 = 1;
	size_t n = 1;

	while (n < current)
	{
		n = 2 * n_2 + n_1;
		n_2 = n_1;
		n_1 = n;
	}

	if (iteration == 0)
		return (2 * n_2 + n_1);
	return n_2;
}

void binaryInsertionSort(const std::vector<int>& pend, std::vector<int>& main)
{
	size_t current = 3;
	size_t high = 3;
	size_t next = jacobsthalIndexGen(current, 0);
	size_t prev = jacobsthalIndexGen(current, 1);

	size_t pendSize = pend.size();

	while (current < pendSize)
	{
		while (current > prev)
		{
			binaryInsert(pend[current - 1], main, high - 1);
			current--;
		}
		current = next;
		next = jacobsthalIndexGen(current, 0);
		prev = jacobsthalIndexGen(current, 1);
		high = high * 2 + 1;
	}
	current = pendSize;
	high = main.size();
	while (current > prev)
	{
		binaryInsert(pend[current - 1], main, high - 1);
		current--;
	}
}

void binaryInsertionSort(const std::deque<int>& pend, std::deque<int>& main)
{
	size_t current = 3;
	size_t high = 3;
	size_t next = jacobsthalIndexGen(current, 0);
	size_t prev = jacobsthalIndexGen(current, 1);

	size_t pendSize = pend.size();

	while (current < pendSize)
	{
		while (current > prev)
		{
			binaryInsert(pend[current - 1], main, high - 1);
			current--;
		}
		current = next;
		next = jacobsthalIndexGen(current, 0);
		prev = jacobsthalIndexGen(current, 1);
		high = high * 2 + 1;
	}
	current = pendSize;
	high = main.size();
	while (current > prev)
	{
		binaryInsert(pend[current - 1], main, high - 1);
		current--;
	}
}

void recursive_vec(std::vector<int>& _vector)
{
	if (_vector.size() <= 1)
		return ;

	pairVectorContainer pairVec = createPairs(_vector);

	pairVec = mergesortPairs(pairVec, pairVec.size());

	std::vector<int> main = extractChain(pairVec, 0);
	std::vector<int> pend = extractChain(pairVec, 1);
	
	recursive_vec(main);
	if (!pend.empty())
		main.insert(main.begin(), pend[0]);
	
	binaryInsertionSort(pend, main);
	
	if (!_vector.empty())
		binaryInsert(_vector[0], main, main.size() - 1);

	_vector = main;
}

void recursive_deque(std::deque<int>& _deque)
{
	if (_deque.size() <= 1)
		return ;

	pairdequeContainer pairdeque = createPairs(_deque);

	pairdeque = mergesortPairs(pairdeque, pairdeque.size());

	std::deque<int> main = extractChain(pairdeque, 0);
	std::deque<int> pend = extractChain(pairdeque, 1);
	
	recursive_deque(main);
	if (!pend.empty())
		main.insert(main.begin(), pend[0]);
	
	binaryInsertionSort(pend, main);
	
	if (!_deque.empty())
		binaryInsert(_deque[0], main, main.size() - 1);

	_deque = main;
}

void PmergeMe::sortVec()
{
	struct timeval begin, end;

	gettimeofday(&begin, 0);
	recursive_vec(vector);
	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	vectorSortTime_ = seconds + microseconds * 1e-6;
}

void PmergeMe::sortDeque()
{
	struct timeval begin, end;

	gettimeofday(&begin, 0);
	recursive_deque(deque);
	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	dequeSortTime_ = seconds + microseconds * 1e-6;
}

void PmergeMe::sort()
{
	if (vecSortCheck() || dequeSortCheck())
	{
	    std::cout << "Numbers are already sorted ..." << std::endl;
	    return ;
	}
	std::cout << "Before:\t";
	size_t setSize = deque.size();
	for (size_t i = 0; i < setSize; i++)
		std::cout << deque[i] << ' ';
	std::cout << std::endl;

	if (setSize > 1)
	{
		sortVec();
		sortDeque();
	}

	std::cout << "After:\t";
	for (size_t i = 0; i < setSize; i++)
		std::cout << deque[i] << ' ';
	std::cout << std::endl;

	std::cout << "Time to process a range of " << std::setw(7) << setSize << " elements with std::vector<int> : ";
	std::cout << std::fixed << std::setprecision(6) << vectorSortTime_ << " seconds";

	std::cout << std::endl << "Time to process a range of " << std::setw(7) << setSize << " elements with std::deque<int>  : ";
	std::cout << std::fixed << std::setprecision(6) << dequeSortTime_ << " seconds";

}

PmergeMe::~PmergeMe(){}