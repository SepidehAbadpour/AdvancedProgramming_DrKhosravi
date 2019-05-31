#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<char> Stage;
typedef vector<Stage> Network;
typedef vector<int> Numbers;


Numbers read_numbers(int num_of_inputs) {
	Numbers result;
	for (int i = 0; i < num_of_inputs; i++) {
		int number;
		cin >> number;
		result.push_back(number);
	}
	return result;
}

Network read_network(int num_of_inputs, int num_of_stages) {
	Network net(num_of_stages);
	for (int i = 0; i < num_of_inputs; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < row.length(); j++) {
			net[j].push_back(row[j]);
		}
	}
	return net;
}

int stages(Network net) {
	return net.size();
}

int inputs(Network net) {
	return net[0].size();
}

Stage ith_stage(Network net, int i) {
	return net[i];
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool is_valid_network(Network network) {
	for (int j = 0; j < stages(network); ++j) {
		for (int i = 0; i < inputs(network); ++i) {
			if (network[j][i] == '-')
				continue;

			int count = 0;
			for (int k = 0; k < inputs(network); k++)
				if (network[j][i] == network[j][k])
					count++;

			if (count != 2) {
				return false;
			}
		}
	}
	return true;
}

void pass_through(Numbers &nums, Stage stage) {
	for (int r = 0; r < stage.size(); r++) {
		if (stage[r] == '-')
			continue;

		for (int i = r + 1; i < stage.size(); i++)
			if (stage[r] == stage[i])
				if (nums[r] > nums[i])
					swap(nums[r], nums[i]);
	}
}

bool sorted(vector<int> numbers) {
	for (int i = 0; i < numbers.size() - 1; i++)
		if (numbers[i] > numbers[i + 1])
			return false;
	return true;
}

void process_testcase(int num_of_inputs, int num_of_stages) {
	Network net = read_network(num_of_inputs, num_of_stages);
	Numbers numbers = read_numbers(num_of_inputs);

	if (!is_valid_network(net)) {
		cout << "Invalid network\n";
		return;
	}

	for (int j = 0; j < num_of_stages; j++)
		pass_through(numbers, ith_stage(net, j));

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
	process_testcase(num_of_inputs, num_of_stages);
	system("pause");
	return 0;
}