package quadratura;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import quadratura.concorrente.*;

public class Main {
	// Create the 10 workers that will handle tasks.
	public static Worker worker[];
	public static Thread workerThread[];

	public static void main(String[] args) {
		// Add the first task to the bag. It is the interval [a,b].

		BufferedReader input = new BufferedReader(new InputStreamReader(
				System.in));

		double a = 0, b = 0;

		try {
			System.out.println("Enter the function f(x) being x the variable:");
			Task.setF(input.readLine());
			System.out.println("Enter the value of 'a' (interval [a,b]):");
			a = Double.parseDouble(input.readLine());
			System.out.println("Enter the value of 'b' (interval [a,b]):");
			b = Double.parseDouble(input.readLine());
			System.out.println("Enter the number of workers to be generated for this job:");
			Worker.numberOfWorkers = Integer.parseInt(input.readLine());
		} catch (Exception e) {
		}

		Task firstTask = new Task(a, b);
		Bag.add(firstTask);
		Bag.release();

		System.out.println("Start! Task: f(x)=" + Task.fx
				+ " => [" + a + ";" + b + "].");
		Worker.fileoutput.begin();
		Worker.fileoutput.writeln("Start! Initial task: f(x)=" + Task.fx
				+ " => [" + a + ";" + b + "].");

		// Start the 10 threads that will compute eventual tasks.
		worker = new Worker[Worker.numberOfWorkers];
		workerThread = new Thread[Worker.numberOfWorkers];
		for (int i = 0; i < Worker.numberOfWorkers; i++) {
			workerThread[i] = new Thread(worker[i] = new Worker(i));
			workerThread[i].start();
		}

		// Wait for every thread termination before presenting results.
		for (int i = 0; i < Worker.numberOfWorkers; i++) {
			try {
				workerThread[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		// Show the result of the problem.

		Worker.fileoutput.writeln("Result: " + Task.total);
		Worker.fileoutput.end();
		System.out.println("Result: " + Task.total);
		System.out.println("Tasks created: " + Task.taskNumber);
		for (int i = 0; i < Worker.numberOfWorkers; i++) {
			System.out.println("Tasks by worker " + i + ":"
					+ worker[i].taskCount);
		}
		System.out.println("Detailed log file 'out.txt' generated.");
	}
}
