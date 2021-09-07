// We find the labels starting from given label in bottom to top order
// First we find the depth of the current label as : depth = log2(label)
// The parent label (next label) of  the current label will be label/2 in non zigzag binary tree
// As the given tree is zigzag labeled no labels will have their original parent label which is label/2 except depth 1 labels, root has depth 0.
    
// So, we find the parent label (next label) of the current label in zigzag tree as:

// parent label = previous depth first element + (previous depth last element - next label in non zigzag tree)
// previous depth first element : 2^ (depth-1)
// previous depth last element : 2^ (depth) -1
// next label in non zigzag tree : label/2

// Example:
// For label 14, depth = log2(14) = 3
// depth = 3, label = 14, parent label = 2^(3-1) + 2^3 -1 - 14/2 = 4 + 7 - 7 = 4
// depth = 2, label =  4, parent label = 2^(2-1) + 2^2 -1 -  4/2 = 2 + 3 - 2 = 3
// depth = 1, label =  3, parent label = 2^(1-1) + 2^1 -1 -  3/2 = 1 + 1 - 1 = 1
// So, path = [1, 3, 4, 14]


class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>result;
        int depth = log10(label)/log10(2);
        
        while(depth>=0) {
            result.insert(result.begin(),label);
            label = (int)pow(2,depth-1) + (int)pow(2,depth) - 1 - label/2;
            depth--;
        }
        
        return result;
    }
};