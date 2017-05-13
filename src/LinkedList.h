#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

template<typename T>
class LinkedList {
    struct Node {
        Node* prev = nullptr;
        Node* next = nullptr;
        T data;

        Node(T& data)
        :   data(data)
        { }
    };

    private:
        int count   = 0;
        Node* first = nullptr;
        Node* last  = nullptr;

    public:
        LinkedList() = default;

        LinkedList& operator= (const LinkedList& other) {
            clear();

            Node* itr = other.first;

            while(itr->next) {
                push_back(itr->data);
                itr = itr->next;
            }

            return *this;
        }

        LinkedList& operator= (LinkedList&& other) {
            clear();

            first = other.first;
            last  = other.last;
            count = other.count;

            other.first = nullptr;
            other.last  = nullptr;
            other.count = 0;

            return *this;
        }

        LinkedList(const LinkedList& other) {
            *this = other;
        }

        LinkedList(LinkedList&& other) {
            *this = std::move(other);
        }

        ~LinkedList() {
            clear();
        }

        T& get(int index) {
            Node* itr = first;

            for(int i = 0; i < index; i++)
                itr = itr->next;

            return itr->data;
        }

        T& operator[] (int index) {
            return get(index);
        }

        void clear() {
            while(count != 0)
                erase(0);
        }

        int size() const {
            return count;
        }

        bool empty() const {
            return count == 0;
        }

        void push_back(T& data) {
            Node* node = new Node(data);

            if(count == 0) {
                first = node;
                last  = node;
                count++;
                return;
            }

            last->next = node;
            node->prev = last;
            last = node;
            count++;
        }

        void push_front(T& data) {
            Node* node = new Node(data);

            if(count == 0) {
                first = node;
                last  = node;
                count++;
                return;
            }

            first->prev = node;
            node->next = first;
            first = node;
            count++;
        }

        bool erase(int index) {
            if(count == 0)
                return false;

            if((index < 0) || (index >= count))
                return false;

            if(index == 0) {
                Node* temp = first;

                first = first->next;
                delete temp;
                count--;

                return true;
            }
            else if(index == count - 1) {
                Node* temp = last;

                last = last->prev;
                delete temp;
                count--;

                return true;
            }

            Node* itr = first;

            for(int i = 0; i < index; i++)
                itr = itr->next;

            itr->next->prev = itr->prev;
            itr->prev->next = itr->next;
            count--;

            delete itr;
            return true;
        }

        bool insert(int index, T& data) {
            if(index == 0) {
                push_front(data);
                return true;
            }
            else if(index == count) {
                push_back(data);
                return true;
            }
            else if((index < 0) || (index > count))
                return false;

            Node* itr = first;
            Node* node = new Node(data);

            for(int i = 0; i < index - 1; i++)
                itr = itr->next;

            itr->next->prev = node;
            node->next = itr->next;
            node->prev = itr;
            itr->next = node;
            count++;

            return true;
        }

        bool pop_back() {
            return erase(count-1);
        }

        bool pop_front() {
            return erase(0);
        }
};

#endif // LINKEDLIST_H_INCLUDED
