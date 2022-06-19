#pragma once
class File
{
	string path;
	string* str = nullptr;
	int size = 0;
public:
	File(string path) {
		this->path = path;
		createArray();
	}
	void printFile() {
		for (int i = 0; i < size; i++) {
			cout << str[i] << endl;
		}
	}
	File(const File& file) {
		this->path = path;
		this->size = size;
		str = new string[size];
		for (int i = 0; i < size; i++) {
			str[i] = file.str[i];
		}
	}
	File(File&& file) {
		this->path = path;
		this->size = size;
		str = file.str;
		file.str = nullptr;
	}
	~File() {
		delete[]str;
	}
	File& operator = (const File& file) {
		this->path = path;
		this->size = size;
		str = new string[size];
		for (int i = 0; i < size; i++) {
			str[i] = file.str[i];
		}
	}
	void addToFile(string line) {
		ofstream out(path,ios::app);
		out << endl << line;
		out.close();
		addToArray(line);
	}
	int countString() {
		ifstream in(path);
		string str2;
		int counter = 0;
		if (in.is_open()) {
			while (getline(in, str2))
			{
				counter++;
			}
		}
		in.close();
		return counter;
	}
	void clearFile() {
		ofstream out(path);
		out.close();
		delete[]str;
		str = nullptr;
		size = 0;
	}
private:
	void createArray() {
		ifstream in(path);
		string str2;
		if (in.is_open()) {
			while (getline(in, str2))
			{
				addToArray(str2);
			}
		}
		in.close();
	}
	void addToArray(string line) {
			string* buf = new string[size + 1];
			for (int i = 0; i < size; i++) {
				buf[i] = str[i];
			}
			buf[size++] = line;
			delete[]str;
			str = buf;
	}
};

