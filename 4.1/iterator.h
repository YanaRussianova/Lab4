#include <iterator>

template  <typename T>
class Iterator :public iterator<forward_iterator_tag, T>
{
private:
	T *ptr;
public:
	//friend class List <T>;
	Iterator(T *x) :ptr(x) {}

	Iterator &operator++() {
		ptr = ptr->next;
		return *this;
	}
	Iterator &operator--() {
		ptr = ptr->prev;
		return *this;
	}
	/*Iterator begin() {
		static iterator i(head);
		return i;
	}
	Iterator end() {
		static iterator i(tail);
		return i;
	}*/
	T operator *()
	{
		return  ptr->date;
	}
	bool operator==(Iterator<T> & r) {
		return ptr == r.ptr;
	}
};
