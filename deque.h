/**
 * @file deque.h
 * @author Joseph Russell Zachery Pickell
 * @date 2026-04-14
 * @brief Creates prototypes of deque functions
 * 
 * Creates the prototypes used in the code used in deque.cpp.
 */

 #ifndef DEQUE_H
 #define DEQUE_H

 

template <typename T>
class Deque {
    private:
        T** blockmap;
        int mapSize;
        int blockSize;
        int start;
        int end;
        int count;

        //Adds a new block to the deque when the current blocks are full
        void resize_map() {
            int newSize = mapSize * 2;
            T** newMap = new T*[newSize];

            for (int i = 0; i < newSize; ++i) {
                newMap[i] = nullptr;
            }

            int offset = (newSize - mapSize) / 2;

            for (int i = 0; i < mapSize; ++i) {
                newMap[offset + i] = blockmap[i];
            }

            start += offset * blockSize;
            end += offset * blockSize;

            delete[] blockmap;
            blockmap = newMap;
            mapSize = newSize;
        }

    public:
        //Constructor initializes the deque with default values and allocates memory for the blockmap
        Deque() {
            mapSize = 8;
            blockSize = 4;
            count = 0;

            blockmap = new T*[mapSize];

            for (int i = 0; i < mapSize; ++i) {
                blockmap[i] = nullptr;
            }

            int mid = mapSize / 2;
            blockmap[mid] = new T[blockSize];

            start = mid * blockSize + blockSize / 2;
            end = start;
        }
        
        //Destructor deallocates memory used by the blockmap and its blocks
        ~Deque() {
            for (int i = 0; i < mapSize; i++) {
                if (blockmap[i] != nullptr) {
                    delete[] blockmap[i];
                }
            }
            delete[] blockmap;
        }

        //Pushes a value to the back of the deque, resizing if necessary
        void push_back(T val) {
            if (end >= mapSize * blockSize) {
                resize_map();
            }

            int block = end / blockSize;
            int index = end % blockSize;

            if (blockmap[block] == nullptr) {
                blockmap[block] = new T[blockSize];
            }

            blockmap[block][index] = val;
            end++;
            count++;
        }

        //Pushes a value to the front of the deque, resizing if necessary
        void push_front(T val) {
            if (start <= 1) {
                resize_map();
            }

            start--;
            int block = start / blockSize;
            int index = start % blockSize;

            if (blockmap[block] == nullptr) {
                blockmap[block] = new T[blockSize];
            }

            blockmap[block][index] = val;
            count++;
        }

        //Pops a value from the back of the deque, updating the end index and count
        void pop_back() {
            if (empty()) return;
            end--;
            count--;
        }

        //Pops a value from the front of the deque, updating the start index and count
        void pop_front() {
            if (empty()) return;
            start++;
            count--;
        }

        //Returns the value at the front of the deque by calculating its position in the blockmap
        T front() {
            int pos = start;
            int block = pos / blockSize;
            int index = pos % blockSize;
            return blockmap[block][index];
        }

        //Returns the value at the back of the deque by calculating its position in the blockmap
        T back() {
            int pos = end - 1;
            int block = pos / blockSize;
            int index = pos % blockSize;
            return blockmap[block][index];
        }

        //Checks if the deque is empty by checking if the count is zero
        bool empty() {
            return count == 0;
        }

        //Returns the number of elements in the deque by returning the count variable
        int size() {
            return count;
        }

        //Overloads the subscript operator to allow access to elements in the deque by index, 
        //calculating their position in the blockmap
        T& operator[](int i) {
            if (i < 0 || i >= count) {
                throw std::out_of_range("Deque index out of range");
            }

            int pos = start + i;
            int block = pos / blockSize;
            int index = pos % blockSize;
            return blockmap[block][index];
        }
};

 #endif