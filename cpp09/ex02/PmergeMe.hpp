#include <vector>
#include <deque>
#include <iostream>
#include "algorithm"
#include <sys/time.h>
#include <cstdlib>
#include <iomanip>
#include <utility>

// typedef std::vector<std::pair<int, int> > intPairVec;
// typedef std::deque<std::pair<int, int> > intPairDeque;

class PmergeMe
{
    private:
        std::vector<int> vector;
        std::deque<int> deque;

        double           vectorSortTime_;
        double           dequeSortTime_;

        void sortVec();
        void sortDeque();

        bool vecSortCheck();
        bool dequeSortCheck();


    public:
        PmergeMe();
        void ser_number(long int &num);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void sort();

        ~PmergeMe();
};
