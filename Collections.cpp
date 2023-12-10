#include"Collections.h"

void List::toStart()
{
    current = head;
}

void List::next()
{
    if(current->next != nullptr && current != nullptr)
    {
        current = current->next;
    }
}

void List::prev()
{
    if(current->prev != nullptr && current != nullptr)
    {
        current = current->prev;
    }
}

int List::get()
{
    if(current != nullptr)
    {
        return current->value;
    }
}

void List::set(int value)
{
    if(current != nullptr)
    {
        current->value = value;
    }
}


void List::add(int value)
{
    if(tail != nullptr)
    {
        tail->next = new Node;
        tail->next->prev = tail;
        tail->next->value = value;
        tail = tail->next;
    }
    else
    {
        head = tail = new Node;
        tail->value = value;
    }
}

List::~List()
{
    while (head != nullptr)
    {
        current = head;
        head = head->next;
        delete current;
    }
}

Array::Array(int size)
{
    this->size = size;
    arr = new int[size];
}

void Array::set(int index, int value)
{
    if(index < size)
    {
        arr[index] = value;
    }
}

int Array::get(int index)
{
    if(index < size)
    {
        return arr[index];
    }
    else
    {
        return arr[size - 1];
    }
}

Array::~Array()
{
    delete[] arr;
}

ArrayToListAdapter::ArrayToListAdapter(IArray* adaptee)
{
    this->adaptee = adaptee;
}

void ArrayToListAdapter::toStart()
{
    counter = 0;
}

void ArrayToListAdapter::next()
{
    counter++;
}

void ArrayToListAdapter::prev()
{
    if(counter > 0)
    {
        counter--;
    }
}

int ArrayToListAdapter::get()
{
    return adaptee->get(counter);
}

void ArrayToListAdapter::set(int value)
{
    adaptee->set(counter, value);
}

void ArrayToListAdapter::add(int value)
{

}

ListToArrayAdapter::ListToArrayAdapter(IList* adaptee)
{
    this->adaptee = adaptee;
}

int ListToArrayAdapter::get(int index)
{
    adaptee->toStart();
    while (index--)
    {
        adaptee->next();
    }
    return adaptee->get();
}

void ListToArrayAdapter::set(int index, int value)
{
    adaptee->toStart();
    while (index--)
    {
        adaptee->next();
    }
    adaptee->set(value);
}


