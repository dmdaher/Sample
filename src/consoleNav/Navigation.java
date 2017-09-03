package consoleNav;

import java.util.Scanner;
import java.util.Stack;

import education_model.Entity;

public class Navigation 
{
	public static void goToEntity(String prevTag, Entity ent, Scanner scan, Stack<Entity> stEntity, boolean success)
	{
		ent.Process(prevTag, scan, stEntity, success);
	}
}
