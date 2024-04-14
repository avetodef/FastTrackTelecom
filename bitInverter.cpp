//Íàïèøèòå ôóíêöèþ, êîòîðàÿ èíâåðòèðóåò òîëüêî âûáðàííûå áèòû 
//â ó÷àñòêå ïàìÿòè, çàäàííîì óêàçàòåëåì è äëèíîé â áàéòàõ.
//Ñïîñîá âûáîðà áèòîâ äëÿ èíâåðòèðîâàíèÿ íà âàøå óñìîòðåíèå. - èíâåðòíóòü êàæäûé âòîðîé

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

	uint8_t arr[LEN] = {0};
	invert(arr, LEN);
	for (uint8_t i = 0; i < LEN; i++) {
		cout << (int)arr[i] << endl;
	}

	return 0;
}
