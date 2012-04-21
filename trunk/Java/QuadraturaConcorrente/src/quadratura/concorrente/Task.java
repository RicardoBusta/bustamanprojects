package quadratura.concorrente;

public class Task {
	static double total = 0.0; // Total area and result.
	
	static int taskNumber = 0;
	
	int number;

	public Task next;

	double left, right, fleft, fright, lrarea;

	public static double epsilon = 0.00000001;

	public static int fx=0;

	public static double f(double x) {
		// F(x) = x²
		double ret;
		
		switch(fx){
		case 0:
			ret = x*x;
			break;
		default:
			ret = 0;
			break;
		}

		return ret;
	}

	public static double area(double left, double right, double fleft,
			double fright) {
		return (((right - left) * (fleft + fright)) / 2);
	}

	public static Task firstTask(double left, double right) {
		return new Task(left, right, f(left), f(right), area(left, right,
				f(left), f(right)));
	}

	public Task(double left, double right, double fleft, double fright,
			double lrarea) {
		this.number = ++taskNumber;
		this.left = left;
		this.right = right;
		this.fleft = fleft;
		this.fright = fright;
		this.lrarea = lrarea;
	}
}
