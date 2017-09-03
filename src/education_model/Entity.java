package education_model;

import java.util.Scanner;
import java.util.Stack;

public interface Entity {
	//i changed Process to take in an index as well to maintain index of previous object
	public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success);
	
}
