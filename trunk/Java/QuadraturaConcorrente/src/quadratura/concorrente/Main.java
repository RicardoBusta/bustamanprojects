package quadratura.concorrente;

public class Main {
	// Create the 10 workers that will handle tasks.
	public static Thread worker[] = new Thread[Worker.numberOfWorkers];
	
	public static void main(String[] args) {
		// Add the first task to the bag. It is the interval [a,b].
		
		double a = 0.0;
		double b = 10.0;
		
		Worker.fileoutput.begin();
		Worker.fileoutput.writeln("Start! Initial task: f(x) ["+a+";"+b+"].");
		Bag.add(Task.firstTask(a, b));
		Bag.release();

		// Start the 10 threads that will compute eventual tasks.
		for (int i = 0; i < Worker.numberOfWorkers; i++) {
			worker[i] = new Thread(new Worker(i));
			worker[i].start();
		}

		// Wait for every thread termination before presenting results.
		for (int i = 0; i < Worker.numberOfWorkers; i++) {
			try {
				worker[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		// Show the result of the problem.
		
		Worker.fileoutput.writeln("Result: "+Task.total);
		Worker.fileoutput.end();
		System.out.println("out.txt file generated.");
	}
}
