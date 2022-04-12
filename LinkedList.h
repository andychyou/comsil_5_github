#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
#include <string>
using namespace std;

//Node
template <typename T>
class Node{
	public:
		//T 타입의 데이터 저장
		T data;
		//다음 노드의 포인터
		Node<T> *link;

		Node(T element){//생성자 T 타입의 element를 받고 link를 NULL로 초기화
		  data = element;
		  link = NULL;
		}
};

//LinkedList 
template <typename T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size;
	public:
		//생성자. 처음에는 아무 값도 없으니 first는 NULL, size도 0
		LinkedList(){
			first = NULL;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList ver
		virtual bool Delete(T &element);

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template <typename T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	newnode -> link = first;
	first = newnode;	//first는 이제 새 노드
	current_size++;	//사이즈 증가
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <typename T>
bool LinkedList<T>::Delete(T &element){

	if (first == NULL)// 비어있으면 delete할 수 없음
		return false;
	
	Node<T> *current = first;	//시작은 first
	Node<T> *previous = NULL;	//전 노드는 없으니 NULL로 초기화
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == NULL){  //current가 마지막 노드일 때를 찾는 것
			if (previous)	//리스트에 노드가 두 개 이상일 때
				previous -> link = current -> link;//지울 node 전 node의 link를 NULL로 만듦
			else//리스트에 노드가 하나만 있을 때
				first = first -> link;	//first는 이제 비었음
			break;
		}
		previous = current;	//previous가 current node가 되면서 전진
		current = current -> link;	//current가 다음 node가 되면서 전진
	}
	element = current -> data;	//삭제할 current node의 값을 element에 참조
	delete current;	//current 삭제
	current = NULL;
	current_size--;	//개수 감소	
	return true;
}

//리스트를 출력하는 Print 함수
template <typename T>
void LinkedList<T>::Print(){
	Node<T> *cur_node;	//현재 프린트 할 노드
	int num = 1;	//현재 노드가 몇 번째인지

	if (current_size != 0){	//리스트 안에 값이 있을 때 출력할 수 있음
		for( cur_node = first; cur_node != NULL; cur_node = cur_node->link){	//cur_node가 NULL이 될 때까지 출력
			if (num == current_size){	//마지막 노드는 뒤에 ->가 없어야 함
				cout << "[" << num << "|";//num 부분
				cout << cur_node -> data << ']';//data 부분 출력
			}
			
			else {
				cout << "[" << num << "|";
				cout << cur_node -> data << "]->";	//아직 뒤에 노드가 남아있으면 ->를 붙임
			}
			num++;	//num 증가
		}
		cout << endl;
	}

}


#endif
