import java.io.Serializable;
import java.util.Date;

public class Assignment implements Serializable {

	public static final long serialVersionUID = 1;
	private int number;
	private String name;
	private float points;
	private String description;
	private Date assigned;
	private Date due;
	
	public Assignment(int number, String name, float points, String description, Date assigned, Date due) {
		setNumber(number);
		setName(name);
		setPoints(points);
		setDescription(description);
		setAssigned(assigned);
		setDue(due);
	}

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public float getPoints() {
		return points;
	}

	public void setPoints(float points) {
		this.points = points;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public Date getAssigned() {
		return assigned;
	}

	public void setAssigned(Date assigned) {
		this.assigned = assigned;
	}

	public Date getDue() {
		return due;
	}

	public void setDue(Date due) {
		this.due = due;
	}
}
