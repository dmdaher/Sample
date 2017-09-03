package education_model;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

import consoleNav.Navigation;
import display.Display;

public class Entities {
	
	public class Time implements Entity
	{
		public String start;
		public String end;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) {}
	}
	
	public class MeetingPeriod implements Entity
	{
		public String day;
		public Time time;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) {}
	}
	
	public class Name implements Entity
	{
		public String fname;
		public String lname;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) {}
	}
	
	public class Assistant implements Entity
	{
		public String staffMemberID;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) {}
	}
	//meetings and officeHours are both type Meeting
	public class Meeting implements Entity
	{
		public String type;
		public String section;
		public String room;
		public ArrayList<MeetingPeriod> meetingPeriods;
		public ArrayList<Assistant> assistants;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) 
		{
			Course currObj = (Course)stEntity.peek();
			//cut prevTag
			String[] result = prevTag.split(" ", 2);
			String cutPrevTag = result[0];
			Display.meetingDisplay(currObj.meetings, prevTag);
			if(scan.hasNextInt())
			{
				int option = scan.nextInt();
				if(option <= currObj.meetings.size() && option > 0)
				{
					option--;
					Display.fullMeetingInfo2(prevTag, currObj.meetings.get(option));
					Process(prevTag, scan, stEntity, success);		
				}
				else if (option == currObj.meetings.size() + 1)
				{
					Navigation.goToEntity(cutPrevTag, currObj, scan, stEntity, success);
				}
				else if(option == currObj.meetings.size() + 2)
				{
					//Exit
					System.out.print("Thanks for using my program!");
				}
				else
				{
					System.out.println("Invalid option! \n");
					Process(cutPrevTag, scan, stEntity, success);
				}
			}
			else
			{
				System.out.println("Invalid input! \n");
				scan.nextLine();
				Process(prevTag, scan, stEntity, success);
			}
		}
	}
	
	public class StaffMember implements Entity
	{
		public Name name;
		public ArrayList<MeetingPeriod> officeHours;
		public String id;
		public String type;
		public String office;
		public String phone;
		public String image;
		public String email;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) 
		{
			Course currObj = (Course)stEntity.peek();
			//cut prevTag
			String[] result = prevTag.split(" ", 2);
			String cutPrevTag = result[0];
			Display.staffDisplay(currObj.staffMembers, prevTag);
			if(scan.hasNextInt())
			{
				int option = scan.nextInt();
				if(option <= currObj.staffMembers.size() && option > 0)
				{
					option--;
					Display.fullStaffInfo2(prevTag, currObj.staffMembers.get(option));
					Process(prevTag, scan, stEntity, success);		
				}
				else if (option == currObj.staffMembers.size() + 1)
				{
					Navigation.goToEntity(cutPrevTag, currObj, scan, stEntity, success);
				}
				else if(option == currObj.staffMembers.size() + 2)
				{
					//Exit
					success = false;
					System.out.print("Thanks for using my program!");
				}
				else
				{
					System.out.println("Invalid option! \n");
					Process(prevTag, scan, stEntity, success);
				}
			}
			else
			{
				//cut prevTag
				System.out.println("Invalid input! \n");
				scan.nextLine();
				Process(cutPrevTag, scan, stEntity, success);
			}
		}
	}
	
	public class Course implements Entity
	{
		public ArrayList<StaffMember> staffMembers;
		public ArrayList<Meeting> meetings;
		public ArrayList<Department> departments;
		public String number;
		public String term;
		public String year;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) 
		{
			Display.staffOrMeetingDisplay(prevTag, number, term, year);
			prevTag += " " + number + " " + term + " " + year;
			if(scan.hasNextInt())
			{
				int option = scan.nextInt();
				//grab user choice and step through to next object
				if(option == 1)//view Staff 
				{
					option--;
					//call entity func ---- passing in staffmembers is just a hack. i will pop in the staff class above
					Navigation.goToEntity(prevTag, staffMembers.get(option), scan, stEntity, success);
				}
				else if(option == 2)//view Meetings
				{
					option--;
					//call entity func --- passing in meetings is just a hack. i will pop in the staff class above
					Navigation.goToEntity(prevTag, meetings.get(option), scan, stEntity, success);
				}
				else if(option == 3)//return to departments
				{
					stEntity.pop();
					Department prevObj = (Department)stEntity.peek();
					Navigation.goToEntity(prevTag, prevObj, scan, stEntity, success);
				}
				else if(option == 4)
				{
					//Exit
					success = false;
					System.out.print("Thanks for using my program!");
				}
				else
				{
					//cut prevTag
					String[] result = prevTag.split(" ", 2);
					String cutPrevTag = result[0];
					System.out.println("Invalid option! \n");
					Process(cutPrevTag, scan, stEntity, success);
				}
			}
			else
			{
				//cut prevTag
				String[] result = prevTag.split(" ", 2);
				String cutPrevTag = result[0];
				System.out.println("Invalid input! \n");
				scan.nextLine();
				Process(cutPrevTag, scan, stEntity, success);
			}
		}
	}
	
	public class Department implements Entity
	{
		public ArrayList<Course> courses;
		public String longName;
		public String prefix;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success)
		{
			Display.courseDisplay(courses, prevTag, longName, prefix);
			if(scan.hasNextInt())
			{
				int option = scan.nextInt();
				//grab user choice and step through to next object
				if(option <= courses.size() && option > 0) 
				{
					prevTag = prefix;
					option--;
					Course courseObj = courses.get(option);
					stEntity.push(courseObj);
					//call entity function
					Navigation.goToEntity(prevTag, courseObj, scan, stEntity, success);
				}
				else if(option == courses.size()+1)
				{
					stEntity.pop();
					School prevObj = (School)stEntity.peek();
					Navigation.goToEntity(prevTag, prevObj, scan, stEntity, success);
				}
				else if(option == courses.size()+2)
				{
					//Exit
					success = false;
					System.out.print("Thanks for using my program!");
				}
				else
				{
					System.out.println("Invalid option! \n");
					Process(prevTag, scan, stEntity, success);
				}
			}
			else
			{
				System.out.println("Invalid input! \n");
				scan.nextLine();
				Process(prevTag, scan, stEntity, success);
			}
		}
	}
	
	public class School implements Entity
	{
		public ArrayList<Department> departments;
		public String name;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) 
		{
			Display.schoolDisplay(departments, prevTag, name);
			if(scan.hasNextInt())
			{
				int option = scan.nextInt();
				//grab user choice and step through to next object
				if(option <= departments.size() && option > 0) 
				{
					option--;
					Department deptObj = departments.get(option);
					stEntity.push(deptObj);
					//call entity func
					Navigation.goToEntity(prevTag, deptObj, scan, stEntity, success);
				}
				else if(option == departments.size()+1)
				{
					stEntity.pop();
					EducationModel prevObj = (EducationModel)stEntity.peek();
					Navigation.goToEntity(prevTag, prevObj, scan, stEntity, success);
				}
				else if(option == departments.size()+2)
				{
					//Exit
					success = false;
					System.out.print("Thanks for using my program!");
				}
				else
				{
					System.out.println("Invalid option! \n");
					Process(prevTag, scan, stEntity, success);
				}
			}
			else
			{
				System.out.println("Invalid input! \n");
				scan.nextLine();
				Process(prevTag, scan, stEntity, success);
			}
		}
	}
	
	public class EducationModel implements Entity
	{
		public ArrayList<School> schools;
		public void Process(String prevTag, Scanner scan, Stack<Entity> stEntity, boolean success) 
		{
			Display.edModelDisplay(schools);
			if(scan.hasNextInt())
			{
				int option = scan.nextInt();
				if(option <= schools.size() && option > 0) 
				{
					option--;
					School schoolObj = schools.get(option);
					stEntity.push(schoolObj);
					//once choice is made, call entity func
					Navigation.goToEntity(prevTag, schoolObj, scan, stEntity, success);
				}
				else if(option == schools.size()+1)
				{
					stEntity.pop();
				}
				else if(option == schools.size()+2)
				{
					//Exit
					success = false;
					System.out.print("Thanks for using my program!");
				}
				else
				{
					System.out.println("Invalid option! \n");
					Process(prevTag, scan, stEntity, success);
				}
			}
			else
			{
				System.out.println("Invalid input! \n");
				scan.nextLine();
				Process(prevTag, scan, stEntity, success);
			}
		}
	}
}
