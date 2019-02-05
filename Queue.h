// -*- C++ -*-

//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_


/**
* @class Queue
*
* Basic Queue for abitrary elements.
*/
template <typename T>
class Queue
{
public:
	/// Type definition of the type.
	typedef T type;

	/// Default constructor.
	Queue (void);

	/// Copy constructor.
	Queue (const Queue & q);

	/// Destructor.
	~Queue (void);

	/**
	* Assignment operator
	*
	* @param[in]      rhs           Right-hand side of operator
	* @return         Reference to self
	*/
	const Queue & operator = (const Queue & rhs);

	/**
	*
	* Puts a new \a element into the queue. The element is placed directly
	* behind the previous element.
	*
	* @param[in]	element		element added to the queue
	*/
	void enqueue(T element);

	/**
	*
	* Takes first \a element from the queue and removes it. The element directly
	* behind it becomes the first in line
	*
	*@exception      empty_exception    The queue is empty.
	*/
	T dequeue (void);

	/**
	*
	* Checks to see if there are any \a elements within the queue. 
	* If no elements are found return true else return false.
	*
	*	@retval		True		queue is empty
	*	@retval		False		queue is not empty
	*/
	bool is_empty(void);

	/**
	*
	* Checks to see if the number of elements plus one is equal to the max size
	* of the queue and returns a true or false
	*
	*	@retval		True		queue is full
	*	@retval		False		queue is not full
	*/
	bool is_full(void);

	/**
	*
	* Goes through queue and counts number of elements within the
	* queue.
	*
	* @return		size of queue
	*/
	size_t size (void);

	/**
	*
	* Removes all elements within the queue effectively clearing it 
	* of all elements
	*
	*/
	void clear (void);

private:
  // COMMENT You are to use the Array class, and no a raw C array. Unfortunately,
  // I will not give comments on this submission since you did not following the
  // requirements, and I would be giving comments on a implementation that is
  // not realistic.
  
	//Pointer to Queue data
	T *queue_data_;

	//max size of queue
	size_t max_;

	//points to the front element in queue
	size_t front_;

	//points to the back element in queue
	size_t back_;

	//current size of queue
	size_t queue_size_;
};

//Include the Queue inline file
#include "Queue.inl"

//Include the Queue Source file
#include "Queue.cpp"

#endif		//Ends Queue header file
