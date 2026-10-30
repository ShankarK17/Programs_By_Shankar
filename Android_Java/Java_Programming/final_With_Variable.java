/* A java file can contain at most only one public class in entire file and if there one the filename must 
 * match as of public class name other (must be same case too). Otherwise if the file doesn't contain any public
 * class then to run the main we must explicitly provide the class name containing main method to execute it with 
 * java "Class name" in terminal
 */

class Final_Variables{
	public static void main(String []args){
		final float pi = 3.1415f; // variable defined final, means cannot be reassigned
		// pi = 3.14156 or pi++; is invalid as variable declared final cannot be changes
		System.out.println("Value of pi = " + pi);

		final int[] arr = {1, 2, 3};// the array name with final(reference variable) cannot be use to initialize any other object of same type 
		//arr = new int[]{4, 5 ,6}; // completely invalid
		arr[0] = 11; // this is valid
		System.out.println("Array first element is " + arr[0]);
	}
}
		
