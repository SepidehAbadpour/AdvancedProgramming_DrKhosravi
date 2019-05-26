#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> read_numbers(int count) {
	vector<int> result;
	for (int i = 0; i < count; i++) {
		int number;
		cin >> number;
		result.push_back(number);
	}
	return result;
}

vector<string> read_network(int num_of_inputs) {
	vector<string> result;
	for (int i = 0; i < num_of_inputs; ++i) {
		string line;
		cin >> line;
		result.push_back(line);
	}
	return result;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool is_valid_network(vector<string> network, int num_of_stages) {
	for (int j = 0; j < num_of_stages; ++j) {
		for (int i = 0; i < network.size(); ++i) {
			if (network[i][j] == '-')
				continue;

			int count = 0;
			for (int k = 0; k < network.size(); k++)
				if (network[i][j] == network[k][j])
					count++;

			if (count != 2) {
				return false;
			}
		}
	}
	return true;
}

void apply(vector<string> network, int j, vector<int>& numbers) {
	for (int i = 0; i < network.size() - 1; i++) {
		if (network[i][j] == '-')
			continue;

		for (int k = i + 1; k < network.size(); k++)
			if (network[i][j] == network[k][j])
				if (numbers[i] > numbers[k])
					swap(numbers[i], numbers[k]);
	}
}

bool sorted(vector<int> numbers) {
	for (int i = 0; i < numbers.size() - 1; i++)
		if (numbers[i] > numbers[i + 1])
			return false;
	return true;
}

void process_testcase(int num_of_inputs, int num_of_stages) {
	vector<string> network = read_network(num_of_inputs);
	vector<int> numbers = read_numbers(num_of_inputs);

	if (!is_valid_network(network, num_of_stages)) {
		cout << "Invalid network\n";
		return;
	}

	for (int j = 0; j < num_of_stages; j++)
		apply(network, j, numbers);

	if (sorted(numbers))
		cout << "Sorted";
	else
		cout << "Not sorted";
	cout << endl;
}

int main() {
	int num_of_inputs;
	int num_of_stages;

	cin >> num_of_inputs >> num_of_stages;
	while (num_of_inputs != 0 && num_of_stages != 0) {
		process_testcase(num_of_inputs, num_of_stages);
		cin >> num_of_inputs >> num_of_stages;
	}
	//cin.ignore();
	//cin.get();
	return 0;
}