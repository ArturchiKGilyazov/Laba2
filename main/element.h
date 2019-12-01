#include "D:/2LAB/Laba2/graphics/visualizer.h" 


class Elem {
private:
	int data;		//Значение элемента
	int index;		//индекс элемента
public:
	Elem(int data_, int index_) : data(data_), index(index_) {}

	operator int() const {
		return data;
	}

	//оператор сравнения с наименьшим
	bool operator<(const Elem& cb) {
		//SDL_Delay(500);
		Visualizer::getInstance().pushCommand(new LesserComparison(this->index, cb.index));	//отрисовываем сравниваемые значения
		printf("lesser of elem %d and %d \n", this->index, cb.index);			//выводим в консоль
		return this->data < cb.data;											//возвращаем 1 если исходный меньше сравниваемого и 0 если наоборот
	}

	//функция копирования
	Elem(Elem&& cb) noexcept {
		//SDL_Delay(500);
		printf("elem %d construct- moved from %d\n", this->index, cb.index);	//вывод в консоль(мы сюда зашли)
		this->index = cb.index;													//копируем индекс элемента
		this->data = cb.data;													//копируем значение элемента
	}

	//функция, если два элемента равны
	Elem& operator=(Elem&& cb) noexcept {
		//SDL_Delay(500);
		Visualizer::getInstance().pushCommand(new MoveAssign(this->index, cb.data));	//отрисовка равных значений
		printf("elem %d moved-assigment from %d \n", this->index, cb.index);// вывод в консоль(мы сюда зашли)
		std::swap(this->data, cb.data);										//поменять местами значения этих элементов
		return *this;														//возвратить 
	}

	//исходные функции (не трогай, оно работает)
	Elem& operator=(const Elem& elem1) = delete;

	Elem(const Elem& elem1) = delete;
};