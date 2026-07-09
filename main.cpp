#include <iostream>
#include <cstring>

class String{
private:
	char* string;
public:
	int length = 0;
	
	String(){
		string = nullptr;
	}
	String(const char* string){
		while(string[length] != '\0'){
			length++;
		}
		this->string = new char[length + 1];
		
		for(int i = 0; i < length; i++){
			this->string[i] = string[i];
		}
		this->string[length] = '\0';
	}
	String(const String &other){
		length = other.length;
		
		string = new char[other.length + 1];
		
		for(int i = 0; i < other.length; i++){
			string[i] = other.string[i];
		}
		string[other.length] = '\0';
	}
	~String(){
		delete[] string;
	}
	char& operator[](int index){
		return string[index];
	}
	String& operator=(const char* string){
		delete[] this->string;
		int newLength = std::strlen(string);
		length = newLength;
		this->string = new char[newLength + 1];
		
		for(int i = 0; i < newLength; i++){
			this->string[i] = string[i];
		}
		this->string[newLength] = '\0';
		return *this;
		
	}
	String operator+(const String &other){
		char* newString = new char[length + other.length + 1];
		
		for(int i = 0; i < length; i++){
			newString[i] = string[i];
		}
		for(int i = 0; i < other.length; i++){
			newString[length + i] = other.string[i];
		}
		newString[length + other.length] = '\0';
		
		String result(newString);
		delete[] newString;
		
		return result;
	}
	String operator*(int number){
		char* newString = new char[length * number + 1];
		
		for(int i = 0; i < number; i++){
			for(int k = 0; k < length; k++){
				newString[i*length + k] = string[k];
			}
		}
		newString[length * number] = '\0';
		String result(newString);
		delete[] newString;
		
		return result;
	}
	bool operator==(const String &other){
		if(length != other.length){
			return false;
			}
		for(int i = 0; i < length; i++){
			if(string[i] != other.string[i]){
				return false;
			}
		}
		return true;
	}
	bool operator!=(const String &other){
		if(length != other.length){
			return true;
			}
		for(int i = 0; i < length; i++){
			if(string[i] != other.string[i]){
				return true;
			}
		}
		return false;
	}
	
};

int main(){
	return 0;
}

