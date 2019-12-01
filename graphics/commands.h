#include <vector> 
#include "window.h"
class Command {
public:
	virtual ~Command() = default;

	virtual void execute(std::vector<int>& container, std::vector<Color>& colors) const = 0;
};

class LesserComparison : public Command {
	int index1;
	int index2;
public:
	LesserComparison(int index1, int index2) : index1(index1), index2(index2) {}
	void execute(std::vector<int>& container, std::vector<Color>& colors) const {
		SDL_Delay(100);
		colors[index1].set(0, 0, 255, 1); //blue 
		colors[index2].set(255, 0, 0, 1); //red 

	}
};

class MoveAssign : public Command {
	int index;
	int data;
public:
	MoveAssign(int index, int data) : index(index), data(data) {}

	void execute(std::vector<int>& container, std::vector<Color>& colors) const {
		SDL_Delay(100);
		colors[index].set(255, 15, 93, 1); //purple
		container[index] = data;
	}
};