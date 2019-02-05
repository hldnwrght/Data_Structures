// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

/// Default constructor.
template <typename T>
std::Queue<T>::Queue(void)
{

}

/// Copy constructor.
template <typename T>
Queue<T>::Queue (const Queue & q)
{
	max_ = sizeof(q);
	queue_size_ = sizeof(q);
	front_ = 0;
	back_ = sizeof(q);
	queue_data_ = new T[];
	this->queue_data_ = *q.data;
}

/// Destructor.
template <typename T>
Queue<T>::~Queue(void)
{
	delete[] queue_data_;
	queue_data = nullptr;
}

/**
* Assignment operator
*/
template <typename T>
const Queue & Queue<T>::operator = (const Queue & rhs)
{
	if (this != &rhs)
	{
		size_t _size;
		int i = 0;
		char ch;

		//gets size of array
		std::cout << "Enter in the size of the array: ";
		std::cin >> _size;

		//fill in array
		Queue* newQueue_ = new Queue(_size);
		std::cout << "Enter in the values for the array: " << std::endl;
		while (i < _size) {
			std::cin >> ch;
			newArr_[i] = ch;
			i++;
		}
		return *newQueue_;
	}
}

/*
*	enqueue
*/
template <typename T>
Queue<T>::enqueue(T element)
{
	try 
	{
		if(is_full())
		{
			throw std::overflow_error;
		}
	}
	catch (std::overflow_error)
	{
		std::cout << "Error: Overflow was detected\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "Inserting: " << element << std::endl;

	back_ = (back_ + 1) % max_;
	queue_data_[back_] = element;
	queue_size_++;
}

/**
* dequeue
*/
template <typename T>
T Queue<T>::dequeue(void)
{
	try
	{
		if (is_empty())
		{
			throw std::underflow_error;
		}
	}
	catch (std::underflow_error)
	{
		std::cout << "Error: Underflow was detected\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "Removing" << queue_data_[front_] << std::endl;

	front_ = (front + 1) % max_;
	queue_size_--;
}

/**
* clear
*/
template <typename T>
Queue<T>::clear(void)
{
	if (is_empty())
	{
		std::cout << "Queue has already been cleared\n";
	}
	else
	{
		while (!is_empty())
		{
			front_ = (front + 1) % max_;
			queue_size_--;
		}
		std::cout << "All elements within Queue have been cleared...\n";
	}
}