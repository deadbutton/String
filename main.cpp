#include <iostream>
// #define DEBUG

int length(const char* str) {
	int count = 0;
	while (true) {
		if (str[count] == '\0') {
			return count;
		}
		count++;
	}
}

class String {
private:
	char* string;
public:
	String(const char* str) {
#ifdef DEBUG
		std::cout << "Constructor called\t" << this << "\n";
#endif //DEBUG
		this->string = new char[length(str) + 1];

		for (int i = 0; i < length(str); i++) {
			string[i] = str[i];
		}

		string[length(str)] = '\0';
	}
	~String() {
#ifdef DEBUG
		std::cout << "Destructor called\t" << this << "\n";
#endif //DEBUG
		delete[] string;
	}
	String(const String& other) {
#ifdef DEBUG
		std::cout << "Copy constructor called\t" << this << "\n";
#endif //DEBUG
		string = new char[length(other.string) + 1];

		for (int i = 0; i < length(other.string); i++) {
			this->string[i] = other.string[i];
		}

		string[length(other.string)] = '\0';
	}

	String& operator=(const String& other) {
#ifdef DEBUG
		std::cout << "Operator= was called\t" << this << "\n";
#endif //DEBUG

		if (this == &other) {
#ifdef DEBUG
			std::cout << "this = &other";
#endif // DEBUG
			return *this;
		}


		delete[] string;
		this->string = new char[length(other.string) + 1];

		for (int i = 0; i < length(other.string); i++) {
			this->string[i] = other.string[i];
		}
		string[length(other.string)] = '\0';
		return *this;
	}
	String operator+(const String& other) {
#ifdef DEBUG
		std::cout << "Operator+ was called\t" << this << "\n";
#endif
		int thisLen = length(string);
		int otherLen = length(other.string);

		char* result = new char[thisLen + otherLen + 1];

		for (int i = 0; i < thisLen; i++) {
			result[i] = string[i];
		}
		for (int i = 0; i < otherLen; i++) {
			result[thisLen + i] = other.string[i];
		}
		result[thisLen + otherLen] = '\0';

		String RESULT = result;
		delete[] result;

		return RESULT;
	}
	void print(char sep='\n') {
		std::cout << string << sep;
	}
};
