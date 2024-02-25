#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  private: 
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int arySize;
  PComparator comp;

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): 
  arySize(m), comp(c)
{ }

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
    data.push_back(item);
    if (data.size() == 1) { return; }
    std::size_t index = data.size() - 1;
    std::size_t parent_index = (index - 1) / arySize;
    while (parent_index >= 0 && !comp(data[parent_index], data[index])) {
        T& current = data[index];
        T& parent = data[parent_index];
        std::swap(current, parent);
        if (parent_index == 0) {break;}
        index = parent_index;
        parent_index = (index - 1) / arySize;
    }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if (data.size() == 0) { return true; }
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Cannot call top()");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Cannot call pop()");
  }

    data[0] = data[data.size()-1];
    data.pop_back();

    std::size_t index = 0;
    std::size_t child_index = (arySize * index) + 1;
    int in = 1;
    while (in < arySize && child_index < data.size()){
      if (comp(data[child_index+in], data[child_index])){
        child_index += in;
      }
      in++;
    }
    while (child_index < data.size() && !comp(data[index], data[child_index])) {
        for (int i = 1; i < arySize; i++){
          if (child_index+1 < data.size() && comp(data[child_index+1], data[child_index])){
            child_index++;
          }
        }
        T& current = data[index];
        T& child = data[child_index];
        std::swap(current, child);
        if (child_index == data.size()-1) {break;}
        index = child_index;
        child_index = (arySize * index) + 1;
    }
}




#endif

