#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{

	struct Command {
		std::string name;
		int delta;
	};

	const auto commands = []() {
		std::vector<Command> commands;
		for (std::string line; std::getline(std::cin, line);) {
			Command command;
			std::istringstream is(line);
			is >> command.name >> command.delta;
			commands.emplace_back(std::move(command));
		}
		return commands;
	}();

	struct Position {
		int x = 0;
		int depth = 0;
		int aim = 0;
	};

	// First run
	{
		Position position;
		for (const auto &command : commands) {
			if (command.name == "forward")
				position.x += command.delta;
			else if (command.name == "down")
				position.depth += command.delta;
			else if (command.name == "up")
				position.depth -= command.delta;
		}
		std::cout << position.x << ", " << position.depth << ", multiplication: " << position.x * position.depth << '\n';
	}

	// Second run, commands mean something different
	{
		Position position;
		for (const auto &command : commands) {
			if (command.name == "forward") {
				position.x += command.delta;
				position.depth += position.aim * command.delta;
			}
			else if (command.name == "down") {
				position.aim += command.delta;
			}
			else if (command.name == "up") {
				position.aim -= command.delta;
			}
		}
		std::cout << position.x << ", " << position.depth << ", multiplication: " << position.x * position.depth << '\n';
	}
}
