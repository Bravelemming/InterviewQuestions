/* CallingMethods.java
 *
 * illustrates how to call static methods a class
 * from a method in the same class
 */

public class CallingMethods
{
	public static void main(String[] args) {
		printOne();
		printTwo();
	}

	public static void printOne() {
		System.out.println("Hello World!");
	}

	public static void printTwo() {
		printOne();
		printOne();
		printOne();
	}
}