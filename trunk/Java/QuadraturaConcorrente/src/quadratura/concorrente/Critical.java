package quadratura.concorrente;

import java.util.concurrent.Semaphore;

public class Critical {
	public static Semaphore critical = new Semaphore(1);

	public static void open() {
		try {
			critical.acquire();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public static void close() {
		critical.release();
	}
}
