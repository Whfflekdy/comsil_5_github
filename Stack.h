#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T>
class Stack : public LinkedList<T> {
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if (this->first == 0) { return false; }
			
			Node<T> *current = this-> first;

			this->first = this->first->link; // first가 2번째 원소를 가리키게 함.
			element = current->data; // element에는 current의 데이터 값을 대입.(잘 작동)
			delete current;
			this->current_size--;
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			return true;
		}
};
