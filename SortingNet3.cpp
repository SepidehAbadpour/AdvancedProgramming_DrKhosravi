#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Comparator {
	int end1;
	int end2;
};

typedef vector<Comparator> Stage;
typedef vector<Stage> Network;
typedef vector<int> Numbers;

Comparator new_comparator(int, int);
Numbers read_numbers(int);
Network read_network(int, int);
Stage ith_stage(Network, int);
void swap(int&, int&);
void apply(Numbers&, Stage);
bool sorted(Numbers);
void process_testcase(int, int);

int main() {
	int num_of_inputs;
	int num_of_stages;

	cin >> num_of_inputs >> num_of_stages;
	process_testcase(num_of_inputs, num_of_stages);
	system("pause");
	return 0;
}

Comparator new_comparator(int e1, int e2) {
	Comparator c;
	c.end1 = e1;
	c.end2 = e2;
	return c;
}

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
	vector<string> temp_net;
	for (int i = 0; i < num_of_inputs; i++) {
		string line;
		cin >> line;
		temp_net.push_back(line);
	}

	for (int i = 0; i < num_of_stages; i++) {
		for (int j = 0; j < num_of_inputs; j++) {
			if (temp_net[j][i] == '-')
				continue;
			for (int k = j + 1; k < num_of_inputs; k++)
				if (temp_net[j][i] == temp_net[k][i])
					net[i].push_back(new_comparator(j, k));
		}
	}
	return net;
}

Stage ith_stage(Network net, int i) {
	return net[i];
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void apply(Numbers &nums, Stage stage) {
	for (int c = 0; c < stage.size(); c++) {
		if (nums[stage[c].end1] > nums[stage[c].end2])
			swap(nums[stage[c].end1], nums[stage[c].end2]);
	}
}

bool sorted(Numbers numbers) {
	for (int i = 0; i < numbers.size() - 1; i++)
		if (numbers[i] > numbers[i + 1])
			return false;
	return true;
}

void process_testcase(int num_of_inputs, int num_of_stages) {
	Network net = read_network(num_of_inputs, num_of_stages);
	Numbers numbers = read_numbers(num_of_inputs);

	for (int j = 0; j < num_of_stages; j++)
		apply(numbers, ith_stage(net, j));

	if (sorted(numbers))
		cout << "Sorted";
	else
		cout << "Not sorted";
	cout << endl;
}