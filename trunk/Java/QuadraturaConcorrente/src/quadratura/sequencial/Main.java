package quadratura.sequencial;

import quadratura.concorrente.FileOutput;

public class Main {	
	public static double epsilon = 0.00000001; 
	
	public static double f(double x){
		return x*x;
	}
	
	public static double calcarea(double a, double b, double fa, double fb){
		return ((b-a)*(fa+fb)/2);
	}
	
	public static void main(String[] args) {
		double a = 0.0;
		double b = 10.0;
		double fa = f(a);
		double fb = f(b);
		
		double newarea = calcarea(a,b,f(a),f(b));
		double area, la, lb;
		
		int div = 2;
		
		do{
			area = newarea;
			newarea = 0;
			for(int i=0;i<div-1;i++){
				la = a+(i*((b-a)/div));
				lb = a+((i+1)*((b-a)/div));
				newarea += calcarea(la,lb,f(la),f(lb));
				//System.out.println("["+la+";"+lb+"]");
			}
			la = (div-1)*((b-a)/div);
			lb = b;
			newarea += calcarea(la,lb,f(la),f(lb));
			div*=2;
		}while(Math.abs(area-newarea)>epsilon);
		System.out.println("Result: "+newarea);
	}
}
