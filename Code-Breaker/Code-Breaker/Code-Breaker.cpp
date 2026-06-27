#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <stdexcept>

struct JudgeResult
{
	int hit = 0;
	int blow = 0;
	bool clear = false;
};
class RandomHolder
{
private:
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<int>dist;
	std::vector<int> numbers;

public:
	RandomHolder(int min=1,int max=9)
		: gen(rd()), dist(min,max){}

	void generateNumbers()
	{
		numbers.clear();
		for (int i = 0; i < 4; i++)
		{
			numbers.push_back(dist(gen));
		}
	}
	const std::vector<int>& getNumbers() const
	{
		return numbers;
	}
};

class InputHolder
{
private:
	std::array<int, 4>values;
	int count = 0;

public:
	void addValue(int val)
	{
		if (val < 0 || val>9)
		{
			throw std::out_of_range("Error: Out of Range Input.");
		}
		if (count >= 4)
		{
			throw std::length_error("Error: Input Digit Count.");
		}
		values[count]= val;
		count++;
	}
	const std::array<int, 4>& getValues() const
	{
		return values;
	}
	bool isComplete() const
	{
		return count == 4;
	}
};

class JudgeHolder
{
private:
	const RandomHolder* randomHolder;
	const InputHolder* inputHolder;
	JudgeResult result;

public:
	JudgeHolder(const RandomHolder* randomAddress,const InputHolder*inputAddres)
		:randomHolder(randomAddress), inputHolder(inputAddres){ }

	void judge()
	{
		if (randomHolder == nullptr || inputHolder == nullptr)
		{
			throw std::invalid_argument("Error: Null Address.");
		}
		if (!inputHolder->isComplete())
		{
			throw std::length_error("Error: Input is not complete.");
		}

		const std::vector<int>& randomNumbers = randomHolder->getNumbers();
		const std::array<int, 4>& inputValues = inputHolder->getValues();

		if (randomNumbers.size() != 4)
		{
			throw std::length_error("Error: Random numbers are not generated.");
		}

		result = JudgeResult();

		int randomCount[10] = {};
		int inputCount[10] = {};

		for (int i = 0; i < 4; i++)
		{
			if (randomNumbers[i] == inputValues[i])
			{
				result.hit++;
			}
			else
			{
				randomCount[randomNumbers[i]]++;
				inputCount[inputValues[i]]++;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			result.blow += std::min(randomCount[i], inputCount[i]);
		}

		result.clear = result.hit = 4;
	}

	const JudgeResult& getResult()const
	{
		return result;
	}
};

class Output
{

};

int main()
{

}