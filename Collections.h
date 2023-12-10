#ifndef COLLECTIONS_H
#define COLLECTIONS_H

struct Node
{
    int value = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class IList
{
public:
    virtual void toStart() = 0;
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual int get() = 0;
    virtual void set(int value) = 0;
    virtual void add(int value) = 0;
    virtual ~IList(){}
};


class List : public IList
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;
public:
    void toStart() override;
    void next() override;
    void prev() override;
    int get() override;
    void set(int value) override;
    void add(int value) override;
    ~List() override;
};


class IArray
{
public:
    virtual int get(int index) = 0;
    virtual void set(int index, int value) = 0;
    virtual ~IArray(){}
};

class Array : public IArray
{
private:
    int size;
    int* arr;
public:
    Array(int size);
    int get(int index) override;
    void set(int index, int value) override;
    ~Array() override;
};

class ArrayToListAdapter : public IList
{
private:
    IArray* adaptee;
    int counter = 0;
public:
    ArrayToListAdapter(IArray* adaptee);
    void toStart() override;
    void next() override;
    void prev() override;
    int get() override;
    void set(int value) override;
    void add(int value) override;
};

class ListToArrayAdapter : public IArray
{
private:
    IList* adaptee;
public:
    ListToArrayAdapter(IList* adaptee);
    int get(int index) override;
    void set(int index, int value) override;
};

#endif // COLLECTIONS_H
