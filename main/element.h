#include "D:/2LAB/Laba2/graphics/visualizer.h" 


class Elem {
private:
	int data;		//�������� ��������
	int index;		//������ ��������
public:
	Elem(int data_, int index_) : data(data_), index(index_) {}

	operator int() const {
		return data;
	}

	//�������� ��������� � ����������
	bool operator<(const Elem& cb) {
		//SDL_Delay(500);
		Visualizer::getInstance().pushCommand(new LesserComparison(this->index, cb.index));	//������������ ������������ ��������
		printf("lesser of elem %d and %d \n", this->index, cb.index);			//������� � �������
		return this->data < cb.data;											//���������� 1 ���� �������� ������ ������������� � 0 ���� ��������
	}

	//������� �����������
	Elem(Elem&& cb) noexcept {
		//SDL_Delay(500);
		printf("elem %d construct- moved from %d\n", this->index, cb.index);	//����� � �������(�� ���� �����)
		this->index = cb.index;													//�������� ������ ��������
		this->data = cb.data;													//�������� �������� ��������
	}

	//�������, ���� ��� �������� �����
	Elem& operator=(Elem&& cb) noexcept {
		//SDL_Delay(500);
		Visualizer::getInstance().pushCommand(new MoveAssign(this->index, cb.data));	//��������� ������ ��������
		printf("elem %d moved-assigment from %d \n", this->index, cb.index);// ����� � �������(�� ���� �����)
		std::swap(this->data, cb.data);										//�������� ������� �������� ���� ���������
		return *this;														//���������� 
	}

	//�������� ������� (�� ������, ��� ��������)
	Elem& operator=(const Elem& elem1) = delete;

	Elem(const Elem& elem1) = delete;
};