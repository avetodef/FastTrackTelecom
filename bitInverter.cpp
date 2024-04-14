//�������� �������, ������� ����������� ������ ��������� ���� 
//� ������� ������, �������� ���������� � ������ � ������.
//������ ������ ����� ��� �������������� �� ���� ����������. - ���������� ������ ������

#include <iostream> 
#include <cstdint>


using namespace std;


void invert(void* ptr, size_t len) {

	if (ptr == nullptr) {
		return;
	}

	uint8_t mask = 0b01010101;
	
	uint8_t* casted = (uint8_t*)ptr;

	for (size_t i = 0; i < len; i++) {
		casted[i] = casted[i] ^ mask;
	}

}

int main() {
	const uint8_t LEN = 10;

	uint8_t arr[LEN] = {1,2,3,4,5,6,7,8,9,10};
	invert(arr, LEN);
	for (uint8_t i = 0; i < LEN; i++) {
		cout << (int)arr[i] << endl;
	}

	return 0;
}