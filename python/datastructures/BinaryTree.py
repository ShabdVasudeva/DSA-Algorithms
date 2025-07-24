class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

idx = -1
def insert(seq):
    global idx
    idx += 1
    if idx >= len(seq) or seq[idx] is None:
        return None
    root = Node(seq[idx])
    root.left = insert(seq)
    root.right = insert(seq)
    return root

def preorder_traversal(root):
    if root is None:
        return
    print(root.data, end=" ")
    preorder_traversal(root.left)
    preorder_traversal(root.right)

if __name__ == "__main__":
    seq = [1, 2, None, None, 3, 4, None, None, 5, None, None]
    root = insert(seq)
    preorder_traversal(root)