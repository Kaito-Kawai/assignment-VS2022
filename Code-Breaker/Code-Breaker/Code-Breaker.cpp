#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

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

		result.clear = result.hit == 4;
	}

	const JudgeResult& getResult()const
	{
		return result;
	}
};

class Output
{
public:
	void showInputGuide(int challengeCount) const
	{
		std::cout << "Challenge " << challengeCount << std::endl;
		std::cout << "Input 4 numbers from 0 to 9." << std::endl;
		std::cout << std::endl;
	}

	void showResult(const JudgeResult& result) const
	{
		std::cout << "Hit: " << result.hit << std::endl;
		std::cout << "Blow: " << result.blow << std::endl;
		std::cout << std::endl;
	}

	void showClear(int challengeCount)const
	{
		std::cout << "Game Clear!!!" << std::endl;
		std::cout << "Challenge Count: " << challengeCount << std::endl;
	}
};

int main()
{
	RandomHolder randomHolder;
	Output output;

	randomHolder.generateNumbers();

	int challengeCount = 0;
	bool isClear = false;

	while (!isClear)
	{
		InputHolder inputHolder;
		challengeCount++;

		output.showInputGuide(challengeCount);

		//	Debug --
		//const std::vector<int>& debugNumbers = randomHolder.getNumbers();

		//std::cout << "Random: ";

		//for (int number : debugNumbers)
		//{
		//	std::cout << number << " ";
		//}

		//std::cout << std::endl;
		//	-- Debug

		for (int i = 0; i < 4; i++)
		{
			int inputValue = 0;

			std::cout << "Number" << i + 1 << ": ";
			std::cin >> inputValue;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please input number." << std::endl;
				i--;
				continue;
			}

			try
			{
				inputHolder.addValue(inputValue);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
				i--;
			}
		}

		JudgeHolder judgeHolder(&randomHolder, &inputHolder);
		judgeHolder.judge();

		const JudgeResult& result = judgeHolder.getResult();
		output.showResult(result);

		isClear = result.clear;
	}
	output.showClear(challengeCount);
}