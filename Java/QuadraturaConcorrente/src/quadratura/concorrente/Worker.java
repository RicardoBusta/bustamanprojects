package quadratura.concorrente;

import net.sourceforge.jeval.EvaluationException;
import net.sourceforge.jeval.Evaluator;

public class Worker implements Runnable {
	public static FileOutput fileoutput = new FileOutput();

	/* Number of workers on this problem */
	public static int numberOfWorkers = 5;

	/* Control the number of idle workers */
	public static int idle = 0;

	public static boolean over = false;

	int id;

	public int taskCount;

	Task task = null;

	public Worker(int id) {
		this.id = id;
		eval = new Evaluator();
		this.taskCount = 0;
	}

	double mid, fmid, larea, rarea;

	private Evaluator eval;

	public double f(double x) {
		String res = "";
		try {
			res = eval.evaluate(Task.sf(x));
		} catch (EvaluationException e) {
			e.printStackTrace();
		}
		return Double.valueOf(res);
	}

	public void run() {
		while (!over) {
			/* Check for Termination */

			Critical.open();
			idle++;
			if (idle == numberOfWorkers && Bag.size.availablePermits() == 0) {
				over = true;
				Bag.release();
			}
			Critical.close();

			/* Get task from bag */
			Bag.acquire();
			if (!over) {
				Critical.open();
				taskCount++;
				task = Bag.get();
				idle--;
				fileoutput.writeln("Worker " + id + "> get task " + task.number
						+ ": [" + task.left + ";" + task.right + "].");
				Critical.close();

				/* Calculate mid and fmid */
				mid = (task.left + task.right) / 2;
				fmid = f(mid);
				/* Calculate larea and rarea */
				larea = Task.area(task.left, mid, task.fleft, fmid);
				rarea = Task.area(mid, task.right, fmid, task.fright);

				/* Check if further approximation is needed */

				if (Math.abs((larea + rarea) - task.lrarea) > Task.epsilon) {
					Critical.open();
					fileoutput.writeln("Worker " + id + "> result: "
							+ task.lrarea + ". New tasks created.");
					Bag.add(new Task(task.left, mid, task.fleft, fmid, larea));
					Bag.release();
					Bag.add(new Task(mid, task.right, fmid, task.fright, rarea));
					Bag.release();
					Critical.close();
				} else {
					Critical.open();
					Task.total += task.lrarea;
					fileoutput.writeln("Worker " + id + "> result: "
							+ task.lrarea + ". Total now is: " + Task.total);
					Critical.close();
				}
			} else {
				break;
			}
		}
		fileoutput.writeln("Worker " + id + "> ended after processing "
				+ taskCount + " tasks.");
		Bag.release();
	}
}
