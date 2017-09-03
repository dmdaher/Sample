package display;

import java.util.ArrayList;

import education_model.Entities.Course;
import education_model.Entities.Department;
import education_model.Entities.Meeting;
import education_model.Entities.School;
import education_model.Entities.StaffMember;

public class Display {
	public static void meetingDisplay(ArrayList<Meeting> meetings, String prevTag)
	{
		System.out.println(prevTag);
		System.out.println("Meeting Information");
		int num = 0;
		for(int i = 0; i < meetings.size(); i++)
		{
			num = i+1;
			if(meetings.get(i).type != null) System.out.println("    "+ num + ") " + meetings.get(i).type);
		}
		num++;
		System.out.println("    "+ num + ") " + "Go to " + prevTag + " menu");
		num++;
		System.out.println("    "+ num + ") " + "Exit");
		System.out.println("What would you like to do? \n");
	}
	public static void staffDisplay(ArrayList<StaffMember> staffMembers, String prevTag)
	{
		System.out.println(prevTag);
		System.out.println("Course Staff");
		int num = 0;
		for(int i = 0; i < staffMembers.size(); i++)
		{
			num = i+1;
			if(staffMembers.get(i).type != null) System.out.println("    "+ num + ") " + "View " + staffMembers.get(i).type);
		}
		num++;
		System.out.println("    "+ num + ") " + "Go to " + prevTag + " menu");
		num++;
		System.out.println("    "+ num + ") " + "Exit");
		System.out.println("What would you like to do? \n");
	}
	public static void courseDisplay(ArrayList<Course>courses, String prevTag, String longName, String prefix)
	{
		System.out.println(prefix + " Courses");
		int count = 0;
		for(int i = 0; i < courses.size(); i++)
		{
			int num = i+1;
			System.out.print("    "+ num + ") " + prefix + " ");
			if(courses.get(i).number != null) System.out.print(courses.get(i).number + " ");
			if(courses.get(i).term != null)System.out.print(courses.get(i).term + " "); 
			if(courses.get(i).year != null)System.out.print(courses.get(i).year);
			count++;
			System.out.println();
		}
		count++;
		System.out.println("    " + count + ") Go to Departments menu");
		count++;
		System.out.println("    " + count + ") Exit");
		System.out.println("What would you like to do?");
	}
	public static void schoolDisplay(ArrayList<Department>departments, String prevTag, String name)
	{
		System.out.println("Departments");
		int count = 0;
		for(int i = 0; i < departments.size(); i++)
		{
			int num = i+1;
			System.out.print("    "+ num + ") ");
			if(departments.get(i).longName != null)System.out.print(departments.get(i).longName + " (");
			if(departments.get(i).prefix != null)System.out.print(departments.get(i).prefix + ")");
			count++;
			System.out.println();
		}
		count++;
		System.out.println("    " + count + ") Go to Schools menu");
		count++;
		System.out.println("    " + count +") Exit");
		System.out.println("What would you like to do?");
	}
	public static void edModelDisplay(ArrayList<School> schools)
	{
		System.out.println("Schools");
		int count = 0;
		for(int i = 0; i < schools.size(); i++)
		{
			int num = i+1;
			System.out.print("    "+ num + ") ");
			if(schools.get(i).name != null)System.out.print(schools.get(i).name);
			count++;
			System.out.println();
		}
		count++;
		System.out.println("    " + count + ") Go to main menu");
		count++;
		System.out.println("    " + count + ") Exit");
		System.out.println("What would you like to do?");
	}
	public static void staffOrMeetingDisplay(String prevTag, String number, String term, String year)
	{
		System.out.println(prevTag + " " + number + " " + term + " " + year);
		System.out.println("    1)" + " View course staff");
		System.out.println("    2)"+ " View meeting information");
		System.out.println("    3) Go to " + prevTag + " Courses menu");
		System.out.println("    4) Exit");
		System.out.println("What would you like to do?");
	}
	public static void fullMeetingInfo2(String prevTag, Meeting meeting)
	{
		System.out.println(prevTag);
		if(meeting.type != null) System.out.println(meeting.type + " Meeting Information");
		if(meeting.section != null)System.out.println("Section: " + meeting.section);
		if(meeting.room != null)System.out.println("Room: " + meeting.room);
		System.out.print("Meetings: ");
		for(int i = 0; i < meeting.meetingPeriods.size(); i++)
		{
			if(meeting.meetingPeriods.get(i) != null)
			{
				if(meeting.meetingPeriods.get(i).day != null)System.out.print(meeting.meetingPeriods.get(i).day + " ");
				if(meeting.meetingPeriods.get(i).time != null)
				{
					if(meeting.meetingPeriods.get(i).time.start != null)System.out.print(meeting.meetingPeriods.get(i).time.start + "-" );
					if(meeting.meetingPeriods.get(i).time.end != null)System.out.print(meeting.meetingPeriods.get(i).time.end);
				}
				
			}
			if(i+1 != meeting.meetingPeriods.size())
			{
				System.out.print(", ");
			}
		}
		System.out.print("\n");
		if(meeting.assistants != null)
		{
			System.out.print("Assistants: ");
			for(int i = 0; i < meeting.assistants.size(); i++)
			{
				if(meeting.assistants.get(i) != null)
				{
					if(meeting.assistants.get(i).staffMemberID != null) System.out.print(meeting.assistants.get(i).staffMemberID);	
				}
				if(i+1 != meeting.assistants.size())
				{
					System.out.print(", ");
				}
			}
		}
		System.out.println("\n");
	}
	public static void fullStaffInfo2(String prevTag, StaffMember staffMembers)
	{
		System.out.println(prevTag);
		if(staffMembers.type != null) System.out.println(staffMembers.type);
		if(staffMembers.name != null)
		{
			System.out.print("Name: ");
			if(staffMembers.name.fname != null)System.out.print(staffMembers.name.fname + " ");
			if(staffMembers.name.lname != null)System.out.print(staffMembers.name.lname);
			System.out.println();
		}
		if(staffMembers.email != null) System.out.println("Email: " + staffMembers.email);
		if(staffMembers.image != null) System.out.println("Image: " + staffMembers.image);
		if(staffMembers.phone != null) System.out.println("Phone: " + staffMembers.phone);
		if(staffMembers.office != null) System.out.println("Office: " + staffMembers.office);
		if(staffMembers.officeHours != null) System.out.print("Office Hours: ");
		for(int i = 0; i < staffMembers.officeHours.size(); i++)
		{
			if(staffMembers.officeHours.get(i).day != null)System.out.print(staffMembers.officeHours.get(i).day + " ");
			if(staffMembers.officeHours.get(i).time != null)
			{
				if(staffMembers.officeHours.get(i).time.start != null)System.out.print(staffMembers.officeHours.get(i).time.start + "-");
				if(staffMembers.officeHours.get(i).time.end != null)System.out.print(staffMembers.officeHours.get(i).time.end);
			}
			if(i+1 != staffMembers.officeHours.size())
			{
				System.out.print(", ");
			}
		}
		System.out.print("\n");
	}
}
