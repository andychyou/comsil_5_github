#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T>//템플릿 확장
class Stack : public LinkedList<T>{
	public:	//delete 함수만 새로 구현
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0){
				return false;
			}

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T>* new_first = this->first->link;	//새로운 시작점
			Node<T>* temp = this->first;	//원래 시작점을 보관하는 변수
			element = this->first->data;	//삭제하는 element 참조
			this->first = new_first;	//새로운 시작점 지정
			delete temp;	//원래 시작점 노드 삭제
			temp = NULL;	//노드 NULL 초기화
			this->current_size--;//개수 감소
			return true;
		}
};
