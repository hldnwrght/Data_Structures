// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


//
// Default Constructor of the Stack
//
template <typename T>
Stack <T>::Stack (void)
{

}

//
//Copy Constructor of the Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
	head = sizeof(stack);
	stack_size_ = sizeof(stack);
	stack_data_ = new T[];
	this->stack_data_ = *stack.data;
}

//
//Destructor of the ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	delete [] stack_data_;
	stack_data = nullptr;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // COMMENT The stack should be allowed to grow.
    //***FIXED - I fixed this by removing the try/catch to allow the stack to grow 
	
	std::cout << "Inserting Element: " << element << std::endl;
	stack_data_[++head_] = element;
	++stack_size;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
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
		std::cout << "Error: underflow was detected"
	}
	
	std::cout << "Popping Element: " << stack_data_[head] << std::endl;
	
	stack_data_[head--];
	--stack_size;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
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
		Array* newArr_ = new Array(_size);
		std::cout << "Enter in the values for the array: " << std::endl;
		while (i < _size) {
			std::cin >> ch;
			newArr_[i] = ch;
			i++;
		}
		return *newArr_;
	}
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
  // COMMENT Just reset the variables instead popping each element, which
  // is expensive.
  //***Fixed - I fixed this by swapping the stack container with an empty one
  
  Container<T> empty;	//Creates an empty container to swap with stack

	if (is_empty()) 
	{
		std::cout << "Stack has already been cleared" << std::endl;
	}
	else 
	{
		std::swap(stack_data, empty);
		std::cout << "Stack Has been Cleared" << std::endl;
	}
}
