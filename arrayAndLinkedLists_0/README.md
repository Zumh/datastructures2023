# arrayLinkedList
- Arrays are collections of elements laid out in contiguous memory.
- They can be located on the stack or the heap.
- Elements are of equal size and are indexed by contiguous integers.
- Arrays can be one-dimensional or multi-dimensional.
- Some languages use zero-based indexing, while others use one-based indexing.
- Key advantage of arrays: random access with constant time for reading or writing elements.
- Address of a particular array element can be calculated using arithmetic operations.
- Multi-dimensional arrays require additional arithmetic to find the address of an element.
- Arrays can be laid out in either row-major or column-major ordering in memory.
- Adding or removing elements at the end of an array is O(1) operation.
- Removing or adding elements at the beginning or in the middle is an O(n) operation.
- Arrays provide constant time access to elements, which is a major advantage.
- Summary: Arrays require contiguous memory, equal-sized elements, and contiguous integer indexing. They offer constant time access, O(1) for end operations, but O(n) for middle or beginning operations.

## What is the address of the lement at index <#number>?
### Constant-time access (Single dimension)
- addr = array_addr + elem_size * (index - first_index)

### Row major ordering
-   address = base_address + (row_index * number_of_columns + column_index) * element_size
-   Row majoring is repeated column number change rapidly than row number. 

### Column major ordering
-   address = base_address + (column_index * number_of_rows + row_index) * element_size
-   Column majoring is row number change more than column number.

### pros and cons
-   Begin
    -   Add O(n)
    -   Remove O(n)
-   Middle
    -   Add O(n)
    -   Remove  O(n)      
-   End
    -   Add O(1)
    -   Remove O(1)
