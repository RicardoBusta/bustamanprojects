package quadratura.concorrente;

import java.util.concurrent.Semaphore;

public class Bag {
	/* Control the number of idle workers */
	public static Semaphore size = new Semaphore(0);

	public static void acquire() {
		try {
			size.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public static void release() {
		size.release();
	}

	public static void add(Task task) {
		tasks.add(task);
	}

	public static Task get() {
		return tasks.poll();
	}

	private static TaskQueue tasks = new TaskQueue();
}
