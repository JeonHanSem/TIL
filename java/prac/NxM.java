import java.util.Scanner;
import java.util.InputMismatchException;

public class NxM{
	int N;
	int M;
	int size;

	NxM(int N,int M,int size){
		this.N = N;
		this.M = M;
		this.size = size;
	}

	public void calc(){
		for(int i=1;i<=size;i++){
			if((i % N == 0) || (i % M == 0)){
				System.out.println(i);
			}
		}	
	}

	public static void main(String[] args){
		try{
			Scanner scan = new Scanner(System.in);
			int n = scan.nextInt();
			int m = scan.nextInt();
			int size = scan.nextInt();
			NxM nm = new NxM(n,m,size);
			nm.calc();
		}catch (InputMismatchException e){
			System.out.println("input exception");
		}
	}
}
