package quadratura.concorrente;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class FileOutput {
	private FileWriter fstream;
	private BufferedWriter out;

	public void begin(){
		try {
			fstream = new FileWriter("out.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
		out = new BufferedWriter(fstream);
	}
	
	public void end(){
		try {
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void writeln(String s){
		try {
			out.write(s+"\r\n");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
