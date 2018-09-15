#include <iostream>
#include <vector>

int getBit(int iNum, int iBit) {
	return (unsigned int)(iNum>>iBit)%2;
}

std::vector<int> getBitInterval(int iNum, int iFrom, int iTo) {
	std::vector<int> bits;
	for (int i = iTo-1; i >= iFrom-1; --i) {
		 bits.push_back(getBit(iNum, i));
	}
	return bits;
}

std::vector<int> getBitIntervalInversed(int iNum, int iFrom, int iTo) {
	std::vector<int> bits;
	for (int i = iFrom-1; i <= iTo-1; ++i) {
		bits.push_back(getBit(iNum, i));
	}
	return bits;
}

void showVector(std::vector<int> vec) {
	for (auto el : vec) {
		std::cout << el;
	}
	std::cout << std::endl;
}


int main() {
	int iNumber = 0x5FABFF01;
	auto bits = getBitInterval(iNumber, 9, 16);
	showVector(bits);
	bits = getBitInterval(~iNumber, 7, 7);
	showVector(bits);
	bits = getBitIntervalInversed(iNumber, 17, 20);
	showVector(bits);

	system("pause");
}