## DSA HW-2  
### Problem 0:  
1. 李沛宸 B10902032
2. 李沛宸 B10902032
3. 李沛宸 B10902032
4. 李沛宸 B10902032
5. 李沛宸 B10902032
### Problem 1:  
1. Tree:  
   <img src="./P1-1.jpg" style="zoom:35%" />  
   Human algorithm: In a postorder traversal it's last node in that subtree will be it's root, so we can cut the tree in half by looking at the inorder traversal, cause the nodes at the left side of the root are in the left subtree and right side in the right subtree. By doing this we can reconstruct the tree.  

2. Tree:  
   <img src="./P1-2.jpg" style="zoom:35%" />  

3. Algorithm:  
   ```C
    int a = 0
    modify_T(root):
        if root is nullptr:
            return
        else:
            modify_T(root->right)
            root->data += a
            a = root->data
            modify_T(root->left)
   ```  
   The time complexity is O(n) cause it traverse through n node with O(1) operation to the node.  
   The algorithm works by traversing from the largest node to the smallest node, and adjust the data in the node by adding the sum of the value of every node that has been traversed, which is the nodes that are larger than it.  

4. Prove:  
    1. Let x be a leaf node and y's left child, assume z is a node smaller than y then z must be in y's left subtree, however x is the only node in y's left subtree, so by contradict y must be the smallest node among all nodes larger than x  
    2. Let x be a leaf node and y's right child, assume z is a node larger than y then z must be in y's right subtree, however x is the only node in y's right subtree, so by contradict must be the largest node among all nodes smaller than x  
    3. By the 2 fact above we can prove that y is either the smallest node among all nodes larger than x, or the largest node among all nodes smaller than x, when x is a leaf node and y is its parent.  
   
5. Tree:  
   <img src="./P1-5.jpg" style="zoom:35%" />   

6. Algorithm:  
   ```C
    height(root):
        if root is nullptr:
            return 0
        else
            return 1 + max(height(root->left), height(root->left))
    wasted_positions_num = pow(2, height(root)) - 1 - n
   ```  
   The time complexity is O(n) cause the recursive fuction traverse through n nodes with O(1) operations during the traverse  
   The algorithm works cause we know that the number of nodes in a complete binary tree are 2^height - 1, so the wated positions in an array will be 2^height - 1 - n  

### Problem 2:  
1. Algoritm:  
   ```C
   start = 1
   end = n
   find_max_min(start, end):
        stack = empty stack
        push(stack, start)  //push and pop both finish in O(1) operations
        push(stack, start + 1)
        for i =  start = 2 to i = end:
            push(stack, i)
            a = pop(stack), b = pop(stack), c = pop(stack)
            if query_attitude_value(a, b, c) == True:
                push(stack, a)
                push(stack, c)
            else if query_attitude_value(a, c, b) == True
                push(stack, a)
                push(stack, b)
            else
                push(stack, b)
                push(stack, c)
        max_min = {pop(stack), pop(stack)}
        return max_min    
   ```
   The time complexity is O(n) query complexity, cause the for loop interations are n-2, and each iteration needs O(1) query complexty  
   The algorithm works by using a stack to store max and min value, and because by asking for query at most two times we can always get the max and min among three values.  

2. Algoritm:  
   ```C

   ```  
   
3. Algoritm:  
   ```C
    add_new_group(n):
        if()
   ```  
   
4. Algoritm:  
   ```C

   ```  
   
5. There are 2 "good triplets" 

6. Algoritm:  
   ```C

   ```  

### Prolem 3:  
1. Tree:  
   <img src="./P3-1.jpg" style="zoom:35%" />  

2. Tree:  
   <img src="./P3-2.jpg" style="zoom:50%" />   

3. Algorithm:  
   ```C
    find_max_value_index(heights, a, b):
        max = 0
        index = 0
        for i = a to b:
            if heights[i] > max
                max = heights[i]
                index = i
        return index
    build_cartesian_tree(root, heights, a, b):  //intially a = 0, b = n - 1
        if a == b:
            return
        else:
            index = find_max_value_index(heights, a, b)
            root->data = heights[index]
            root->index = index  //O(n) extra space for problem 4,5,6
            build_cartesian_tree(root->left, heights, a, index-1)
            build_cartesian_tree(root->right, heights, index+1, b)
   ```  
   The time complexity is O(n * h) because to complete every floor of the tree it will take (n-c) times for searching the max index  
    Example for the worst case:  
    <img src="./P3-3.jpg" style="zoom:35%" />   
    The algorithm works by finding the index of the max value between index a and index b and cutting the tree in half. By the property of cartesian tree we know that the nodes in the left subtree will be at the left side of the root index in the array and same as the right subtree, also the root value will be the max value in its subtree.  

4. Algorithm:  
   ```C
   find_index_value(root, index):
      if root->index == index:
         return root->data
      else if root->index < index:
         find_index_value(root->right, index)
      else if root->index > index:
         find_index_value(root->left, index)
   ```  
   The time complexity is O(log n) cause the worst case is when it traverse to the leaf, which is determined by the depth of the tree.  
   The algorithm works by cutting of impossible cases, because we know that the index larger than the root index must be in its right subtree and smaller ones in the left subtree, so we only need to tranverse through the subtree that have the index in it.  

5. Algorithm:  
   ```C
   find_max_value(root, left, right):
      if left >= right:
         return 0   //invalid situation
      if left <= root->index < right:
         return root->data
      else if root->index < left:
         find_max_value(root->right, index)
      else if root->index >= right:
         find_index_value(root->left, index)
   ```  
   The time complexity is O(log n) cause the worst case is when left = right-1, which means it will traverse to the leaf with at most depth's operation.  
   The algorithm works by finding there lowest common ancestor, with similar thoughts from problem 3, we only need to check the subtree with the answer.  

6. Algorithm:  
   ```C
   visible_building_stack = empty stack
   visible_heights_stack = empty stack
   a = 0
   left_hand_side_view(root):
      if root == nullptr:
         return
      else:
         left_hand_side_view(root->left)
         push(visible_building_stack, root->index)
         push(visible_heights_stack, root->data - a)
         a = root->data
   ``` 
   The time complexity is O(log n) because the function will traverse through the left-most chain in the tree which depth is at most log n.  
   The algorithm works by kowing that the left-most chain in the cartesian tree will be the buildings we need, cause its the only chain in the tree which is monotonically increasing in both index and value in the nodes.  
