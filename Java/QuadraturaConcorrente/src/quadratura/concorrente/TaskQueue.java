package quadratura.concorrente;

public class TaskQueue {
	private Task first;
	private Task last;
	
	public Task poll(){
		Task out;
		if(first == null){
			out = null;
		}else{
			out = first;
			first = first.next;
		}
		return out;
	}
	
	public void add(Task t){
		if(first == null){
			first = t;
		}else{
			last.next = t;
		}
		t.next = null;
		last = t;
	}
	
	public TaskQueue(){
		first = null;
		last = null;
	}
}
