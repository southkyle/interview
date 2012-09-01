#include <iostream>
#include <vector>
#include <algorithm>

class Input
{
public:
	 Input(std::vector<int>* data) : data_(data), cur_index_(0) {

	 }
	~ Input() { 
	}

	int Value() const {
		return (*data_)[cur_index_];
	}

	bool Valid() const {
		return cur_index_ < data_->size();
	}

	void Next() {
		cur_index_++;
	}

	bool operator < (const Input& rhs) {
		return Value() > rhs.Value();
	}
private:
	std::vector<int>* data_;
	int cur_index_;
};

void Merge(std::vector<Input>* inputs, std::vector<int>* out) {
	make_heap(inputs->begin(), inputs->end());
	while (!inputs->empty()) {
		pop_heap(inputs->begin(), inputs->end());
		out->push_back(inputs->back().Value());
		inputs->back().Next();
		if (inputs->back().Valid()) {
			push_heap(inputs->begin(), inputs->end());
		} else {
			inputs->pop_back();
		}
	}
}

#define arraysize(v) (sizeof(v)/sizeof(v[0]))

int main(int argc, char const *argv[])
{
	int array0[] = {1, 3, 5, 7, 9};
	int array1[] = {2, 4, 6, 8, 10};
	int array2[] = {-100, -99, -30};
	int array3[] = {-1000, -98, -22};
	int array4[] = {-80, -79, -60, -50};

	std::vector<int> v0(array0, array0 + arraysize(array0));
	std::vector<int> v1(array1, array1 + arraysize(array1));
	std::vector<int> v2(array2, array2 + arraysize(array2));
	std::vector<int> v3(array3, array3 + arraysize(array3));
	std::vector<int> v4(array4, array4 + arraysize(array4));

	std::vector<Input> inputs;
	inputs.push_back(Input(&v0));
	inputs.push_back(Input(&v1));
	inputs.push_back(Input(&v2));
	inputs.push_back(Input(&v3));
	inputs.push_back(Input(&v4));

	std::vector<int> out;
	Merge(&inputs, &out);
	for (size_t i = 0; i < out.size(); i++) {
		std::cout << out[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
// The better way is to make a Iterater class.


class Iterator {
	virtual bool IsValid() const = 0;
	virtual int Value() const = 0;
	virtual void Next() = 0;
};

