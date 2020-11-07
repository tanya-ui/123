

#include <iostream>
using namespace std;

int main() {
	int mas[5] = { 1,2,3,4,5 };
	int* begin = mas;
	int* end = mas + sizeof(mas) / sizeof(*mas) - 1;

	while (begin < end)
	{
		*begin ^= *end ^= *begin ^= *end;
		begin++;
		end--;
	}
	for (int i = 0; i < sizeof(mas) / sizeof(*mas); i++)
		cout << *(mas + i) << " ";
}
