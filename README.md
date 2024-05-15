### Push Swap

Push Swap is a project from the 42 school curriculum. The goal is to sort a stack of integers using a predefined set of operations with the objective of sorting the stack with the fewest moves possible.

For this project, I implemented the Butterfly algorithm. 🦋 It divides the numbers into several groups based on the input arguments. The stack is then sorted by sending the groups to another stack, with the smallest group at the bottom and the largest at the top. This process is repeated for each group, resulting in a butterfly-shaped stack.

The Butterfly algorithm involves using linked lists and determining whether it is more efficient to rotate elements up or down, both when sending elements from stack A to stack B and vice versa. Each movement in the algorithm, such as `sa`, `sb`, `ra`, `rb`, etc., is carefully calculated to optimize the sorting process.

### Description of Moves

- `sa` (swap a): Swaps the top two elements of stack 'a'. No action is taken if there is only one or no element in 'a'.
- `sb` (swap b): Swaps the top two elements of stack 'b'. No action is taken if there is only one or no element in 'b'.
- `ss`: Executes 'sa' and 'sb' simultaneously.
- `pa` (push a): Moves the top element of stack 'b' to stack 'a'. No action is taken if 'b' is empty.
- `pb` (push b): Moves the top element of stack 'a' to stack 'b'. No action is taken if 'a' is empty.
- `ra` (rotate a): Shifts all elements of stack 'a' up by one position. The first element becomes the last.
- `rb` (rotate b): Shifts all elements of stack 'b' up by one position. The first element becomes the last.
- `rr`: Executes 'ra' and 'rb' simultaneously.
- `rra` (reverse rotate a): Shifts all elements of stack 'a' down by one position. The last element becomes the first.
- `rrb` (reverse rotate b): Shifts all elements of stack 'b' down by one position. The last element becomes the first.
- `rrr`: Executes 'rra' and 'rrb' simultaneously.
    
Overall, Push Swap provides an excellent opportunity to deepen understanding of sorting algorithms and data structures while offering an engaging and challenging project experience.
