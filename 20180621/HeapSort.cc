 ///
 /// @file    HeapSort.cc
 /// @author  LJW
 /// @date    2018-06-24 20:30:29
 ///
 
#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using std::endl;


template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
	HeapSort(vector<T> & array)
	: _array(array)
	{}

	void makeHeap()
	{
		for(int idx = _array.size() / 2 - 1; idx >= 0; --idx)
		{
			HeapAdjust(idx, _array.size());
		}
	}
	
	void sort()
	{
		makeHeap();
		for(int idx = _array.size() - 1; idx >= 0; --idx)
		{
			std::swap(_array[0], _array[idx]); // 
			HeapAdjust(0, idx);
		}
	}

	void HeapAdjust(int parent, int size)
	{
		int lchild = 2 * parent + 1;
		Compare compare;
		while(lchild < size)
		{
			int rchild = lchild + 1;
			if(rchild < size && compare(_array[lchild], _array[rchild]))
				++lchild;

			if(compare(_array[parent], _array[lchild]))
			{
				std::swap(_array[parent], _array[lchild]);
				parent = lchild;
				lchild = 2 * lchild + 1;
			}
			else
				break;
		}
	}

	void print() const
	{
		vector<int>::const_reverse_iterator rit = _array.rbegin();
		while(rit != _array.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}

private:
	vector<T> _array;

};


int main()
{
	vector<int> numbers = {2, 6, 8, 5, 3, 1};
	HeapSort<int> hs(numbers);
	hs.sort();
	hs.print();
	return 0;
}
