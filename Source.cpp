#include <vector>
#include <iostream>
#include <time.h>
using namespace std;


struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

stats bubble_sort(std::vector<int> &data) {
	stats stat;
	for (size_t i = 0; i < data.size() - 1; i++) {
		for (size_t j = 0; j < data.size() - 1 - i; j++) {

			if (data[j + 1] < data[j])
			{
				stat.comparison_count++;
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
				stat.copy_count++;
			}
		}
	}
	return stat;
}

stats shell_sort(std::vector<int>& data){
    stats stat;
    for (size_t d = data.size() / 2; d > 0; d /= 2)
    {
        for (size_t i = d; i < data.size(); ++i)
        {
            stat.comparison_count++;
            for (int j = i - d; j >= 0 && data[j] > data[j + d]; j -= d)
            {
                int temp = data[j];
                data[j] = data[j + d];
                data[j + d] = temp;
                stat.copy_count++;
            }
        }
    }
    return stat;
}

int main() {

	stats counter;
	std::vector<int> v1 = { 9,1,-7,9,1,4,5,2,10};
	std::vector<int> v2 = { 9,1,7,9,1,4,5,-2,10,8};
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	counter = bubble_sort(v1);
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	std::cout << "Comparisons:" << counter.comparison_count << std::endl;
	std::cout << "Copies:" << counter.copy_count << std::endl;
	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	counter = shell_sort(v2);
	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	std::cout << "Comparisons:" << counter.comparison_count << std::endl;
	std::cout << "Copies:" << counter.copy_count << std::endl;
	std::cout << "\n";


