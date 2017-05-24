#pragma once
#include <cstdint>
#include <string>
#include "Exception.h"

template <typename T>
class Element {
public:
	Element<T> * m_next;
	Element<T> * m_previous;
	Element(T *value, Element<T> * next, Element<T> * previous) {
		m_value = value;
		m_next = next;
		m_previous = previous;
	}
	~Element() {
		delete m_value;
	}
	T * get() const {
		return m_value;
	}
private:
	T * m_value;
};

template <typename T>
class Container {
public: 

	Container() {
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
	}

	~Container();
	void add_head(T * new_element);
	void add_tail(T * new_element);
	void remove_head();
	void remove_tail();
	T * get_head() const;
	T * get_tail() const;
	bool is_it_empty() const;
	uint32_t get_size() const;
	void clean();
	T & get_value(uint32_t index) {
		Element<T>* element = m_head;
		while (index != 0) {
			element = element->m_next;
			--index;
		}
		return *element->get();
	}


	
private:
	Element<T> * m_head;
	Element<T> * m_tail;
	uint32_t m_size;
};

template <typename T>
bool Container<T>::is_it_empty() const {
	if (m_size == 0) return true;
	else return false;
}

template <typename T>
void Container<T>::add_head(T * new_element) {
	m_head = new Element<T>(new_element, m_head, nullptr);
	if (m_head->m_next == nullptr)
		m_tail = m_head;
	if (m_head->m_next != nullptr)
		m_head->m_next->m_previous = m_head;

	++m_size;
}

template <typename T> 
void Container<T>::add_tail(T * new_element) {
	m_tail = new Element<T>(new_element, nullptr, m_tail);
	if (m_tail->m_previous == nullptr)
		m_head = m_tail;
	if (m_tail->m_previous != nullptr)
		m_tail->m_previous->m_next = m_tail;

	++m_size;
}

template <typename T>
void Container<T>::remove_head() {
	if (is_it_empty) {
		throw Is_empty();
	}
	Element<T> * new_head;
	new_head = m_head->m_next;
	delete m_head;
	m_head = new_head;
	--m_size;
}

template <typename T>
void Container<T>::remove_tail() {
	if (is_it_empty) {
		throw Is_empty();
	}
	Element<T> * new_tail;
	new_tail = m_tail->m_previous;
	delete m_tail;
	m_tail = new_tail;
	--m_size;
}

template <typename T>
T* Container<T>::get_head() const {
	if (is_it_empty()) {
		throw Is_empty();
	}
	return m_head->get();
}

template <typename T>
T* Container<T>::get_tail() const {
	if (is_it_empty()) {
		throw Is_empty();
	}
	return m_tail->get();
}



template <typename T>
uint32_t Container<T>::get_size() const {
	return m_size;
}

template <typename T>
Container<T>::~Container() {
	Element<T> * element;
	element = m_head;
	while (element != nullptr) {
		Element<T>* temp;
		temp = element;
		element = element->m_next;
		delete(temp);
	}
}


template <typename T>
void Container<T>::clean() {
	if (is_it_empty()) {
		return;
	}
	Element<T> * element;
	element = m_head;
	while (element != nullptr) {
		Element<T>* temp;
		temp = element;
		element = element->m_next;
		delete temp;
	} 
	m_size = 0;
	m_head = nullptr;
	m_tail = nullptr;
}
