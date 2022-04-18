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
    modify_T(T.root):
        if T is NIL:
            return
        else:
            modify_T(T.root->right)
            int temp = T.root.data
            T.root.data += a
            a += temp
            modify_T(T.root->left)
   ```  
   The time complexity is O(n) cause it traverse through n node with O(1) operation to the node.  
   The algorithm works by traversing from the largest node to the smallest node, and adjust the data in the node by adding the sum of the value of every node that has been traversed, which is the nodes that are larger than it.
4. Prove:  
    1. If x is y's left child, y must be the largest node among all nodes smaller than x, cause x < y
    2. If x is y's right child, y must be the smallest node among all nodes larger than x, cause x > y
    3. If x is a leaf node and y's left child, nodes that are larger than x are y and nodes in y's right subtree, and y must be smaller than any nodes in its right subtree, so y must  be the smallest node among all nodes larger than x
    4. If x is a leaf node and y's right child, nodes that are smaller than x are y and nodes in y's left subtree, and y must be larger than any nodes in it's left subtree, so y must  be the largest node among all nodes smaller than x  
    5. By the 4 fact above we can prove that y is either the smallest node among all nodes larger than x, or the largest node among all nodes smaller than x, when x is a leaf node and y is its parent.  
   
5. Tree:  
   <img src="./P1-5.jpg" style="zoom:35%" />   

6. 