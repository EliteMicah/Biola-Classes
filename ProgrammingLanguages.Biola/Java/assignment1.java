import java.util.Scanner;
public class CSstudents {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
    
        System.out.print("Enter # of freshmen: ");
        int freshmenCount = input.nextInt();
    
        System.out.print("Enter # of sophomores: ");
        int sophomoreCount = input.nextInt();
    
        System.out.print("Enter # of juniors: ");
        int juniorCount = input.nextInt();
    
        System.out.print("Enter # of seniors: ");
        int seniorCount = input.nextInt();
    
        int total = freshmenCount + sophomoreCount + juniorCount + seniorCount;
    
        System.out.println("Total number of CS students: " + total);
    }
}
