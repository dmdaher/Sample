package file_io;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

import com.google.gson.Gson;
import com.google.gson.JsonParseException;
import com.google.gson.JsonSyntaxException;

import consoleNav.Navigation;
import education_model.Entities.EducationModel;
import education_model.Entity;

public class Main {
	public static void main(String [] args) {

		boolean success = false;
		EducationModel edModel = null;
		do
		{
			try {
				System.out.print("Enter input filename: ");
				Scanner scan = new Scanner(System.in);
				String inputFilename = scan.nextLine();
				FileReader fr = new FileReader(inputFilename);
				Gson gson = new Gson();
				edModel = gson.fromJson(fr, EducationModel.class);
				success = true;
			} 
			catch (JsonSyntaxException e) {
			    System.out.print("That is not a well-formed JSON file");
			} catch (JsonParseException e) {
				System.out.print("That is not a well-formed JSON file");
			}
			catch(IOException ioe) {
				System.out.println("That file could not be found");
			}
		}while(!success);
		
		Stack<Entity> stEntity = new Stack<Entity>();
		while(success == true)
		{
			// Start initial prompt
			Scanner scan2 = new Scanner(System.in);
			System.out.println("	1) Display Schools "
					+ "\n	2) Exit "
					+ "\nWhat would you like to do?");
			if(scan2.hasNextInt())
			{
				int firstOption = scan2.nextInt();
				if(firstOption == 1) 
				{
					success = true;
					stEntity.push(edModel);
					//once choice is made, call entity func
					Navigation.goToEntity(" ", edModel, scan2, stEntity, success); 
				}
				else if(firstOption == 2)
				{
					success = false;
					System.out.print("Thanks for using my program!");
				}
			}
			else if(!scan2.hasNextInt())
			{
				System.out.println("Invalid input! \n");
			}
			else
			{
				break;	
			}
			System.gc();
		}
	}
}