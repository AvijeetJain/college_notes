import math

#in the max(minimax()) part there will be branchingFactor number of elements to compare

def minimax(curDepth, nodeIndex,
            maxTurn, scores,
            targetDepth):

    if (curDepth == targetDepth):
        return scores[nodeIndex]

    if (maxTurn):
        return max(minimax(curDepth + 1, nodeIndex * branchingFactor,
                           False, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex * branchingFactor + 1,
                           False, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex * branchingFactor + 2,
                           False, scores, targetDepth))

    else:
        return min(minimax(curDepth + 1, nodeIndex * branchingFactor,
                           True, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex * branchingFactor + 1,
                           True, scores, targetDepth),
                   minimax(curDepth + 1, nodeIndex*branchingFactor + 2, True, scores, targetDepth))


# Driver code
scores = [2, 1, 5, 6, 2, 11, 8, 5, 1, 3, 2, 4, 10,
          11, 12, 1, 2, 1, 3, 1, 3, 6, 1, 11, 2, 5, 1]

treeDepth = math.log(len(scores), 3)
branchingFactor = 3

print("The optimal value is : ", end="")
print(minimax(0, 0, True, scores, treeDepth))

# This code is contributed
# by rootshadow
