package quadratura.concorrente;

public class Worker implements Runnable {
	public static FileOutput fileoutput = new FileOutput();
	
	/* Number of workers on this problem */
	public static final int numberOfWorkers = 10;

	/* Control the number of idle workers */
	public static int idle = 0;

	public static boolean over = false;

	int id;

	Task task = null;

	public Worker(int id) {
		this.id = id;
	}

	double mid, fmid, larea, rarea;

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
				task = Bag.get();
				idle--;
				fileoutput.writeln("Worker "+id+"> get task: ["+task.left+";"+task.right+"].");
				Critical.close();

				/* Calculate mid and fmid */
				mid = (task.left + task.right) / 2;
				fmid = Task.f(mid);
				/* Calculate larea and rarea */
				larea = Task.area(task.left, mid, task.fleft, fmid);
				rarea = Task.area(mid, task.right, fmid, task.fright);

				/* Check if further approximation is needed */
				
				if (Math.abs((larea + rarea) - task.lrarea) > Task.epsilon) {
					Critical.open();
					fileoutput.writeln("Worker "+id+"> result: "+task.lrarea+ ". New tasks created.");
					Bag.add(new Task(task.left, mid, task.fleft, fmid, larea));
					Bag.release();
					Bag.add(new Task(mid, task.right, fmid, task.fright, rarea));
					Bag.release();
					Critical.close();
				} else {
					Critical.open();
					Task.total += task.lrarea;
					fileoutput.writeln("Worker "+id+"> result: "+task.lrarea+". Total now is: "+Task.total);
					Critical.close();
				}
			} else {
				break;
			}
		}
		fileoutput.writeln("Worker " + id + "> end.");
		Bag.release();
	}
}
