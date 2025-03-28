# Assignment5



1. For removing all invalid parenthesis from a given string the approach I decided to implement was a Breadth-First
Search that will help find any valid outputs. The first function is a boolean function that checks if the string has any
valid parenthesis. In the fuction there is a counter that helps keep track of all the open brackets, in the beginning it
is set to 0 since there have been no encounters yet. Then there is the for loop that goes through each character in
string s. The for loop has an if else statement inside with the first if statement having the job of checking if there
has been an open bracket, if so, the counter is incremented because we have finally encountered an open bracket. Then
else if statement checks if there has been a closing bracket in the string s, if so, and there has been no encounters of
an open bracket, the function returns false since the string is invalid. if the else if statement is true, the counter
is also decremented. At the end of the function, it returns counter being equal to 0 which would mean that there was a
valid sequence in the string. The function that follows is the void function that goes through the process of taking out
any invalid parenthesis using Breadth-First Search. There is first an unordered_set named "marked" which will help keep 
track of all visted strings so that we don't risk any revisiting of strings that were already processed. There a queue
that will be the BFS queue to go through the string. There is also a set "results" that will help with storing all valid
outputs from the string so that we keep track of any unique outputs. After the initialization of these variables, a bool
"found" is created and set to false, this will help with stopping the search as soon as there has been a valid output 
found. The queue and the marked are also inserted with the string so that the searching can begin. There is a while loop
that runs as long as the queue isn't empty. In the while loop, there is a integer "size" that is the size of the queue
so that we process all of the queue's levels. There is also an unordered set that is created that will be used as a
temporary set that keeps note of strings found at whatever level the queue is at. There is also a for loop that has a
string "curr" that will be used for the queue's first value and the queue is popped each iteration so that the next
value is looked at. Next, the curr value is checked to make sure its a valid expression with the help of the isValid
function. If the curr value is indeed valid, it will be put into the results variable and the found will be set to true.
After, found is checked to see if it is set to true so that the processing is cut off from the current level once a valid
output has been found. Next, a for loop is made that runs for the size of the curr value. In the for loop, there is an
if statement that will skip any value that isn't a parenthesis from the curr[j] position. Then there is a next variable 
that is made after the curr[j] is skipped. The next string will be the new string holding all that comes before j and
after j. There is an if statement that follows that checks if the next has not been visited, if so it will be processed.
the next string is pushed into the queue for the BFS and then is added to the visited variable so that it will not be
looked at again. If there has been any valid expression found at that level, then the BFS is stopped and the marked set
is updated with the visited values. Lastly, printing all the expressions that were found at the end of the process. This
algorithm has a time complexity of O(n * 2^n) considering that the process of making a string valid is O(n) and with BFS
the Big-O is O(2^n). The space complexity is the flipped O(2^n * n) considering that the queue and the two sets marked
and results take O(2^n) time to be completed, and each level needs O(n) space.





2. For getting the minimum absolute difference between the two nodes, an inorder traversal was done with efficient track-
ing to help find the right output. To begin, there is the structure for the TreeNode that has the variables of each node
that will be in the tree. Each node will have a val which is an integer value, and a left/right pointer that refer to the
tree's child. The first function is the inorder traversal function that passes the node's root, and a previous/ different
value to help with keeping track of the node's values. First is a base case for the function since there is going to be 
some recursion done. If the root is empty, then the function returns. Now the inorder traversal recursion is done, first
the left subtree is traversed through, while visiting the left subtree, the root is visited and the difference is checked
between the current node and the previous node. The if statement makes sure that the first value is skipped since there
are no previous values before the first one. If the statement is true, the diff variable is updated to help keep track
of the min absolute difference is between the nodes that are being looked at. The prev value is then moved to the current
node's value so that the process of the previous value being compared to the new one is continued. At the end of the
function, the right subtree is then traversed with the same process. The function that follows is what will help find
the min difference with the nodes. The node's root is passed into the function with the diff and prev variables being
set to INT_MAX and INT_MIN to help with storing the min absolute difference and making sure the first comparison in the
inorder function is valid. After that the inorder function is called and once the call is complete, diff should hold the
minimum absolute difference from the two nodes. This algorithm has a time/space complexity of O(n) where the n is
determined by the size of the tree for the space complexity and the amount of nodes in the tree for the time complexity.




3. For finding the shortest path that visits all nodes with the connected graph given, I decided to use a Breadth-First
Search. First is the State structure that will represent the current state that the search is in. The State has a node
is the current node the function is at, a mask that is a bitmask that will help track what nodes were already visited,
and a counter that will keep track of the steps taken. Then there are 3 global variables, nodes is a constant integer
that is set to 12 meaning that there is 12 nodes in total. There is a graph that is a matrix the size of the amount of
nodes. There is the degree integer that is an array the size of nodes that will store the amount of neighbors of each
node. Now for the shortest path function, to begin there is an integer fin that will calculate the final mask where all
bits are set to 1, this will help with checking if every node has been looked at. There is a queue that will store the
states of the node. An unordered set "visited" that will hold each node's state where all the nodes have their own
unique mask for the visited node so that it isn't visited again. Next, there is a for loop that will push the initial
state of each node into the queue for the BFS to process. The mask for the nodes is set to only the ith node being
visited and the counter is set to 0 considering that there have been no steps taken at this point in the process. The
state is also marked in the visited variable so that the node in that set is marked accordingly. Next is a while loop 
runs as long as the queue isn't empty, the state s is dequeued, in this is the current node, the bitmask, and the
counter. There is an if statement that checks if the state's mask is equal to the final mask which would mean that all
nodes were visited. If that is the case, then the value for the counter is returned and that will be the shortest path
needed. If not, then there is a for loop that will help take a look at the neighbors of the current node. The new bitmask
is calculated by initializing the mask to the neighbor node's. There is then an if statement that checks if the current
neighbor node's state was visited. If so, the state is marked and then the new state is pushed into the queue for BFS.
At the bottom, -1 is returned if there were no solutions found after the BFS is done. The time/space complexity for this
approach is O(n * 2^n). For the time complexity, the n comes from the amount of nodes and the 2^n comes from the size of
the bitmask. For the space complexity, the queue and the set that stores the mask for each node are O(n * 2^n) where
like I said the n comes from the number of nodes and the 2^n from the size of the bitmask.




4. For finding the maximum path sum of a binary tree, I used a Depth-First
search to get the output needed. To begin, you have the structure for the TreeNode which will have the values each node
in the tree holds. That is a value and a left/right child. There is also a global variable maxSum that will help keep
track of the maximum path sum while the DFS is being done. The first function is the DFS function. There is a base case 
that checks if the root of the tree is empty, if so then the function returns 0. This function will help look through
the binary tree and help calculate the path sums that are found with recursion. There are two variables Max_left/right
that both recursively check the max path sum of their subtree. the max(0, DFS->left/right) is used because it helps
look over path sums that are either negative so the total sum isn't decreased in any way. So only positive path sums are
taken as well as 0. The global variable maxSum is then set to the maximum of the current value along with the sum of the
paths found in the current node added with the left/right children. The function then returns the maximum path sum + the
max of the left/right child. The second function is the MaxPath function that passes in the node's root. In this function
maxSum is set to INT_MIN so that the edge cases of the nodes are handled. The DFS function is then called with the root
being passed through. Once the traversal is done, the maxSum is returned which at this point will hold the maximum path
sum of the path in the tree. This approach has a time complexity of O(n) where n is the total amount of nodes in the tree.
The space complexity of the approach is also O(n) because of the recursion done in the functions, where the n is the size 
of the binary tree.




5. For handling returning the numbers in range of 1 and n in lexicographical order, I decided to do a Depth-First Search.
The first function is the DFS function, a curr and n variable are passed into the function. Where curr is the current
number the function is on and the number given. There is first a base case that checks if the current number is greater
than the n number, if the statement is true the function returns. Next the current number is printed into the output
every time there the function is called considering that the number is between the range of 1 and n. Then there is a for
loop that will help with getting the number that comes next. The "next" number is calculated by taking the current
number and multiplying 10 + the ith iteration to make sure the lexicographical order logic is correct. The "next" number
is then run through the same comparison done for the base case because if the next is bigger than the n the numbers
beyond that point are invalid since they would be greater than n. Then the DFS function is recursively called to repeat
the process. The last function is the lexical function that serves as the beginner for the depth-first search. It starts
with a for loop that runs through numbers in the range of 1-9 and calls the DFS function so that new numbers are made
beginning with the smallest possible lexicographical value. This process continues as long as the number being made is
less than or equal to n. In the main, the n is chosen and the lexical function is called to begin the DFS process for
the n. This approach has a time complexity of O(n) considering that the numbers being made are made once and they are
also looked at once through the DFS process. This makes sure that there are no repetition of visits or any repeat numbers.
The space complexity for this approach is O(1) considering that no arrays, vectors, or any sort of data structure is used
to store the values, the approach uses a fixed amount of space no matter what the n is.