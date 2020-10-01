package trees;

public class BTNode {
	int value;
	int height;
	BTNode left, right;
	
	
	public int getHeight() {
		return height;
	}
	
	public void setHeight(int height) {
		this.height = height;
	}
	
	public int getValue() {
		return value;
	}
	
	public void setValue(int value) {
		this.value = value;
	}
	
	public BTNode getLeft() {
		return left;
	}
	
	public void setLeft(BTNode left) {
		this.left = left;
	}
	
	public BTNode getRight() {
		return right;
	}
	
	public void setRight(BTNode right) {
		this.right = right;
	}
	
	
	
}
