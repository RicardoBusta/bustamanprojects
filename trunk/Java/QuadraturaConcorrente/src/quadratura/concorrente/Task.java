package quadratura.concorrente;

import net.sourceforge.jeval.EvaluationException;
import net.sourceforge.jeval.Evaluator;

public class Task {
	public static double total = 0.0; // Total area and result.

	private static int taskNumber = 0;

	public int number;

	public Task next;

	double left, right, fleft, fright, lrarea;

	public static double epsilon = 0.00000001;

	public static String fx = "(x*x)";

	public static void setF(String fx) {
		Task.fx = fx;
	}

	public static String sf(double x){
		return Task.fx.replaceAll("x", "("+x+")");
	}
	
	public static double area(double left, double right, double fleft,
			double fright) {
		return (((right - left) * (fleft + fright)) / 2);
	}

	public Task(double left, double right){
		Evaluator eval = new Evaluator();
		
		String fl="0",fr="0";
		try {
			fl = eval.evaluate(sf(left));
			fr = eval.evaluate(sf(right));
		} catch (EvaluationException e) {
			e.printStackTrace();
		}		
		
		this.number = ++taskNumber;
		this.left = left;
		this.right = right;
		this.fleft = Double.valueOf(fl);
		this.fright = Double.valueOf(fr);
		this.lrarea = area(this.left,this.right,this.fleft,this.fright);
	}

	public Task(double left, double right, double fleft, double fright, double lrarea) {
		this.number = ++taskNumber;
		this.left = left;
		this.right = right;
		this.fleft = fleft;
		this.fright = fright;
		this.lrarea = lrarea;
	}
}
