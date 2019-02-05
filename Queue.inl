
// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// is_empty
//
template <typename T>
inline
bool is_empty(void)
{
	return (size() == 0);
}

//
// is_full
//
template <typename T>
inline
bool is_full(void)
{
	return (size() == max_);
}

//
//size
//
template <typename T>
inline
size_t size(void)
{
	return queue_size_;
}