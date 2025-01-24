#include <iostream>
#include <ctime>
#include <cstdlib>

int rand_range(int a, int b)
{
	return rand() % ((b + 1) - a) + a;
}

int rand_range()
{
	return rand();
}

int search(int* arr, int lenght, int value)
{
	for(int i = 0; i < lenght; i++)
	{
		if(value == arr[i])
			return i;
	}

	return -1;
}

int binnary_search(int* arr, int lenght, int value)
{
	int right = lenght, left = 0;

	while(right > left)
	{
		std::cout << "Left: " << left << " Right: " << right << std::endl;
		int middle = (right + left) / 2;

		if(arr[middle] > value)
		{
			right = middle - 1;
		}
		else if(arr[middle] < value)
		{
			left = middle + 1;
		}
		else if(arr[middle] == value)
		{
			return middle;
		}
	}

	return -1;
}

void bubble_sort(int* arr, int lenght)
{
	for(int j = 0; j < lenght; j++)
        {
                bool sorted = true;
                for(int i = 0; i < lenght - j - 1; i++)
                {
                        if(arr[i] > arr[i + 1])
                        {
                                int a = 0;
                                a = arr[i];
                                arr[i] = arr[i + 1];
                                arr[i + 1] = a;
                                sorted = false;
                        }
                }

                if(sorted)
                        break;
        }
}
    struct vector
    {       int* data;   
            int size; 
            int capacity;
            vector(int size_ = 0):data(0), size(size_), capacity(2 * size + 1)
            {
                std::cout << "Counstructor" << std::endl;
                data = new int[capacity];
            };
            ~vector()
            {
                delete[] data;
                std::cout << "Destructor" << std::endl;
            }
            int get_size()
            {
                    return size;       
           };
            int at(int index)
            {
                    std::cout <<"Size: " << size << "\t" << "Capacity" << capacity << std::endl;
                    return data[index];
            };

            int& operator[](int index)
            {
                    return data[index];
            };
            void push_back(int element)
            {
                    if(size > capacity)
                    {
                        std::cout << "Resizing Size:  " << size << "\t Capacity: " << capacity << std::endl;
                        capacity *= 2;
                       int* temp = new int[capacity];

                        for(int i = 0; i < size; i++)
                        {
                            temp[i] = data[i];
                        }

                        delete[] data;

                        data = temp;
                    }
                    data[size++] = element;

            };
    };      
    


int main()
{
	srand((int)time(0));
    
    vector v;

    for (int i = 0; i < 100; i++)
            v.push_back(rand_range());

    for (int i = 0; i < 100; i++)
            std::cout << v[i] << "\t";
	return 0;   
}