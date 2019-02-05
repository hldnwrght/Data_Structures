// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


//
// Fixed_Array
// -default constructor
template <typename T, size_t  N>
Fixed_Array <T, N>::Fixed_Array (void)
{

}

//
// Fixed_Array
// -copy constructor
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
{
	cur_size_ = sizeof(arr);
	max_size_ = sizeof(N);
	data_ = new T[sizeof(N)];
	this->data_ = *Fixed_Array.data_;
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
{
	cur_size_ = sizeof(arr);
	max_size_ = sizeof(M);
	data_ = new T[sizeof(M)];
	this->data_ = *Fixed_Array.data_;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
{
	cur_size_ = sizeof(fill);
	max_size_ = sizeof(fill);
	T* data_ = new T[length];
	this->data_ = &fill;					//data is set to the address of fill
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	delete[] data_;
	data_ = nullptr;
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if (this != &rhs)
	{
		size_t _size;		//for the size of the array
		size_t i = 0;			//holds number of iterations
		T ch;			//takes in contents for array

						//gets size of array
		std::cout << "Enter in the size of the array: ";
		std::cin >> _size;

		//fills in array
		T* newT_ = new T(_size);
		std::cout << "Enter in the values for the array: " << std::endl;
		while (i < _size || _size >= N) {				//checks to make sure size is not greater than N
			std::cin >> ch;
			newArr_[i] = ch;
			i++;
		}
		return *newT_;
	}
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	if (this != &rhs)
	{
		size_t _size;		//for the size of the array
		size_t i = 0;			//holds number of iterations
		T ch;			//takes in contents for array

						//gets size of array
		std::cout << "Enter in the size of the array: ";
		std::cin >> _size;

		//fills in array
		T* newT_ = new T(_size);
		std::cout << "Enter in the values for the array: " << std::endl;
		while (i < _size || _size >= M) {		//checks to make sure size is not greater than M
			std::cin >> ch;
			newArr_[i] = ch;
			i++;
		}
		return *newT_;
	}
}
